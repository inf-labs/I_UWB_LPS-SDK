#ifndef __ILINK_H
#define __ILINK_H
	
#include "inf_typedef.h"

//The length of data frame
#define DATA_FRAME_LENGTH_8 8
#define DATA_FRAME_LENGTH_16 16			
#define DATA_FRAME_LENGTH_24 24			
#define DATA_FRAME_LENGTH_32 32			
#define DATA_FRAME_LENGTH_64 64			
#define DATA_FRAME_LENGTH_128 128	
#define DATA_FRAME_LENGTH_256 256		
#define DATA_FRAME_LENGTH_512 512	
#define DATA_FRAME_LENGTH_1024 1024		
#define DATA_FRAME_LENGTH_2048 1024		
#define DATA_FRAME_LENGTH_4096 4096		

uint8 Sum_Check_Get(uint8 *buf,uint32 length);


#endif

