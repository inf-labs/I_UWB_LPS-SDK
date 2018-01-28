#include "ilink.h"




uint8 Sum_Check_Get(uint8 *buf,uint32 length)
{
  uint32 i;
  uint8 sum = 0;
	
	for(i = 0;i < (length-1); i++)
	{
		sum += buf[i];
	}

	return sum;
}



