#include "delay.h"


/*
 * Function Name:Delay_Us
 * Description	:delay
 * Input  			:delay time, unit:us
 * Output  			:None
 */ 
void Delay_Us(uint32_t us)
{
   u16 i=0;  
   while(us--)
   {
      i=1000;  
      while(i--);    
   }
}

/*
 * Function Name:Delay_Ms
 * Description	:delay
 * Input  			:delay time, unit:ms
 * Output  			:None
 */ 
void Delay_Ms(u32 ms)
{
  u32 i = 0;
	for(;i < ms; i++)
		Delay_1ms();
}


void Delay_1ms(void)
{
  u32 j = 0,z = 0;
		for(;j < 1000; j++)
			for(;z < 24000; z++);
}





