#ifndef __USART1_H
#define __USART1_H

#include "stdio.h"
#include "stm32f4xx.h"
#include "inf_typedef.h"
#include "system_init.h"

#define USART1_RECEIVE_BUF_LENGTH 128

extern uint16 usart1_send_buf_length;
extern uint8 usart1_send_buf[];
extern uint16 usart1_receive_buf_length;
extern uint8 usart1_receive_buf[];
extern uint8 usart1_rx_irq_updata_user_reset_status;
extern uint8 usart1_tx_irq_updata_user_reset_status;

void USART1_Init(uint8 baudrate_index);
void USART1_DMA_Init(void);
void USART1_DataFrame_Send (unsigned char *send_buf,int length);


#endif



