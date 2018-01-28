#ifndef __KEY_H
#define __KEY_H

#include "inf_typedef.h"

#define KEY GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) //PE4

void KEY_Init(void);
uint8 KEY_Scan(void);

#endif



