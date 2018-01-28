#ifndef __SYSTEM_INIT_H
#define __SYSTEM_INIT_H
	
#include "inf_typedef.h"	
	
enum I_UWB_LPS
{
	TAG_ROLE,
	AHRS_ROLE
};

#define I_UWB_LPS_ROLE 	TAG_ROLE //define I-UWB LPS ROLE: TAG_ROLE or AHRS_ROLE

extern uint16 usart_rx_length;

void System_Init(void);


#endif


