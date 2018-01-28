#include "system_init.h"
#include "stm32f4xx.h"
#include "task.h"

#include "bsp\system\system_param.h"
#include "bsp\delay\delay.h"
#include "bsp\led\led.h"
#include "bsp\key\key.h"
#include "bsp\usart\usart1.h"	
#include "bsp\systick\systick.h"

uint16 usart_rx_length;

/*
 * Function Name:System_Init
 * Description	:System init function
 * Input  			:None
 * Output  			:None
 */
void System_Init(void)
{
	System_Param_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  

	KEY_Init();
	LED_Init();
	USART1_Init(6);//baudrate:460800
	Systick_Init();
}



