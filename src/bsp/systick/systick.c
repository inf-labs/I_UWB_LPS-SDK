#include "systick.h"

static __IO u32 TimingDelay = 0;

/*
 * 函数名：SysTick_Init
 * 描述  ：启动系统滴答定时器
 * 输入  ：无
 * 输出  ：无
 */
void Systick_Init(void)
{ 
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//SystemCoreClock / 1000    1ms中断一次
	//SystemCoreClock / 500	    2ms中断一次
	 
	if (SysTick_Config(SystemCoreClock / 1000))
	{ 
		while (1);
	}		
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
  NVIC_InitStruct.NVIC_IRQChannel = (uint8_t)SysTick_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x000F;
  NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct);

	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;//关闭滴答定时器  	
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk; //使能滴答定时器  
}

