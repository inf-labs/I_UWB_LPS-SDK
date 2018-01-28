#ifndef __SYSTEM_PARAM_H
#define __SYSTEM_PARAM_H
	
#include "inf_typedef.h"

typedef struct
{
	uint64 time;//
	
} stm32_system_struct;//基站i,j结构体

extern stm32_system_struct stm32_system;

void System_Param_Init(void);

#endif

