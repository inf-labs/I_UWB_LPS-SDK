#ifndef __LED_H
#define __LED_H

#include "stm32f4xx.h"

#define LED_TOGGLE   GPIOE->ODR ^= GPIO_Pin_15;

#define  LED_ON        GPIO_SetBits(GPIOE,GPIO_Pin_15)
#define  LED_OFF       GPIO_ResetBits(GPIOE,GPIO_Pin_15)

void LED_Init(void);

#endif



