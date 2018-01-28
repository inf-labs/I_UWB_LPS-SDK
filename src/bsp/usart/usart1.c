#include "usart1.h"		  
#include <stdarg.h>
#include "string.h"
#include "bsp\led\led.h"
#include "system_init.h"
#include "modules\ilink\ilink_i_uwb_lps.h"
#include "modules\ilink\ilink_ahrs.h"


uint16 usart1_send_buf_length = 0;
uint8 usart1_send_buf[USART1_RECEIVE_BUF_LENGTH];
uint16 usart1_receive_buf_length = 0;
uint8 usart1_receive_buf[USART1_RECEIVE_BUF_LENGTH];

uint32 usart1_baudrate_buf[9] = {9600,38400,57600,100000,115200,256000,460800,921600,1382400};

static uint32 USART1_BaudRate_Select(uint8 index);

static uint32 USART1_BaudRate_Select(uint8 index)
{
	return  usart1_baudrate_buf[index];
}

/*
 * 函数名：USART1_Init
 * 描述  ：串口1初始化函数
 * 输入  ：波特率
 * 输出  ：无
 */
void USART1_Init(uint8 baudrate_index)
{
	//GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//使能USART1时钟，注意串口3的时钟是挂在APB1上的
	
	//USART1端口配置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10; //GPIOA9与GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure); //初始化PA9，PA10
	
	//串口1对应引脚复用映射
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9复用为USART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10复用为USART1
	
   //USART1 初始化设置
	
	USART_InitStructure.USART_BaudRate = USART1_BaudRate_Select(baudrate_index);//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
  USART_Init(USART1, &USART_InitStructure); //初始化串口1
	
	USART_Cmd(USART1, ENABLE);  //使能串口1  
	
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);//开启USART空闲中断
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//串口1中断通道  
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//抢占优先级3  
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;       //子优先级3  
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;         //IRQ通道使能  
  NVIC_Init(&NVIC_InitStructure); //根据指定的参数初始化VIC寄存器
		
	if(I_UWB_LPS_ROLE == TAG_ROLE)	usart_rx_length = I_UWB_LPS_TAG_DATAFRAME0_LENGTH;//设置接收数据长度 
	else if(I_UWB_LPS_ROLE == AHRS_ROLE)	usart_rx_length = I_AHRS_DATAFRAME0_LENGTH;
	
	
	USART1_DMA_Init();
}


void USART1_DMA_Init(void)
{
	DMA_InitTypeDef  DMA_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);//DMA1时钟使能 

	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);  //使能串口1的DMA发送     
  USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);  //使能串口1的DMA接收
	
	//****************************配置USART1发送  
	DMA_DeInit(DMA2_Stream7);  
	while (DMA_GetCmdStatus(DMA2_Stream7) != DISABLE);//等待DMA可配置   
	
	/* 配置 DMA Stream */  
	DMA_InitStructure.DMA_Channel = DMA_Channel_4;  //通道选择  
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&USART1->DR;//DMA外设地址  
	DMA_InitStructure.DMA_Memory0BaseAddr = (u32)usart1_send_buf;//DMA 存储器0地址  
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;//存储器到外设模式  
	DMA_InitStructure.DMA_BufferSize = usart1_send_buf_length;//数据传输量   
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设非增量模式  
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//存储器增量模式  
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//外设数据长度:8位  
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;//存储器数据长度:8位  
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;// 使用普通模式   
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;//中等优先级  
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;           
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;  
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输  
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输  
	DMA_Init(DMA2_Stream7, &DMA_InitStructure);//初始化DMA Stream  
	
	//DMA NVIC    
	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream7_IRQn;    
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;    
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    
	NVIC_Init(&NVIC_InitStructure);    

	DMA_ITConfig(DMA2_Stream7,DMA_IT_TC,ENABLE);  
	
	
	//****************************配置UART1接收  
	DMA_DeInit(DMA2_Stream5);  
	while (DMA_GetCmdStatus(DMA2_Stream5) != DISABLE);//等待DMA可配置   
	
	DMA_InitStructure.DMA_Channel = DMA_Channel_4;  //通道选择  
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&USART1->DR;//DMA外设地址  
	DMA_InitStructure.DMA_Memory0BaseAddr = (u32)usart1_receive_buf;//DMA 存储器0地址  
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;//外设到存储器模式  
	DMA_InitStructure.DMA_BufferSize = usart_rx_length;//数据传输量   
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设非增量模式  
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//存储器增量模式  
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//外设数据长度:8位  
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;//存储器数据长度:8位  
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;// 使用普通模式   
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;//中等优先级  
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;           
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;  
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//存储器突发单次传输  
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//外设突发单次传输  
	DMA_Init(DMA2_Stream5, &DMA_InitStructure);//初始化DMA Stream  
	
	DMA_Cmd(DMA2_Stream5, ENABLE);  //开启DMA传输
	
	usart1_rx_irq_updata_user_reset_status = 0;
	usart1_tx_irq_updata_user_reset_status = 0;
}


uint8 usart1_tx_irq_updata_user_reset_status = 0;

void DMA2_Stream7_IRQHandler(void)
{
    if(DMA_GetITStatus(DMA2_Stream7,DMA_IT_TCIF7) != RESET)
		{
			
        DMA_Cmd(DMA2_Stream7,DISABLE); //DISABLE DMA 
        
				DMA_ClearFlag(DMA2_Stream7,DMA_FLAG_TCIF7); 
				usart1_tx_irq_updata_user_reset_status = 0;
    }
}

/*
 * Function Name:USART1_DataFrame_Send
 * Description	:
 * Input  			:send_buf, send_buf length
 * Output  			:None
 */ 
void USART1_DataFrame_Send(unsigned char *send_buf,int length)
{
	if(usart1_tx_irq_updata_user_reset_status == 0)
	{
		memcpy(&usart1_send_buf,send_buf,length);
	
		DMA_SetCurrDataCounter(DMA2_Stream7,length);//设置传输数据长度
		DMA_Cmd(DMA2_Stream7,ENABLE); //启动DMA
		USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);

		usart1_tx_irq_updata_user_reset_status = 1;
	}
}

uint8 usart1_rx_irq_updata_user_reset_status = 0;

void USART1_IRQHandler(void)
{
    if(USART_GetITStatus(USART1,USART_IT_IDLE) != RESET)
    {
				
				DMA_Cmd(DMA2_Stream5, DISABLE); 
        USART1->SR;
        USART1->DR;
			
        DMA_ClearFlag(DMA2_Stream5,DMA_FLAG_TCIF5 | DMA_FLAG_FEIF5 | DMA_FLAG_DMEIF5 | DMA_FLAG_TEIF5 | DMA_FLAG_HTIF5);//清除DMA2_Steam7传输完成标志  
				
				DMA_SetCurrDataCounter(DMA2_Stream5, usart_rx_length);  
        DMA_Cmd(DMA2_Stream5, ENABLE);    
				usart1_rx_irq_updata_user_reset_status = 1;
				
    }
}



//*****************************************************
#if 1
#pragma import(__use_no_semihosting)             
//not use micro lib           
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       

void _sys_exit(int x) 
{ 
	x = x; 
} 
//redefine fputc function 
int fputc(int ch, FILE *f)
{      
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET){}; 
    USART_SendData(USART1,(uint8_t)ch);   
	return ch;
}
#endif 
//*****************************************************

