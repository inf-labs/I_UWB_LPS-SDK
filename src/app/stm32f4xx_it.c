/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    04-August-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"

#include "bsp\led\led.h" 
#include "bsp\systick\systick.h"
#include "bsp\usart\usart1.h"

volatile unsigned long time32_incr;

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/




#include "task.h"
#include "bsp\system\system_param.h"
#include "bsp\usart\usart1.h"


extern TASK_TIME Task_Time;

/*
 * 函数名：SysTick_Handler
 * 描述  ：滴答中断函数
 * 输入  ：无
 * 输出  ：无
 */  
void SysTick_Handler(void)
{
	stm32_system.time++;
	
	Task_Time.Cnt_1Ms++;
	Task_Time.Cnt_2Ms++;
	Task_Time.Cnt_4Ms++;
	Task_Time.Cnt_5Ms++;
	Task_Time.Cnt_10Ms++;
	Task_Time.Cnt_20Ms++;
	Task_Time.Cnt_40Ms++;
	Task_Time.Cnt_50Ms++;
	Task_Time.Cnt_150Ms++;
	
}





