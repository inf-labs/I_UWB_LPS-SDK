#include "mc_led.h"
#include "led.h"
#include "inf_typedef.h"
#include "modules\mc_module\mc.h"


void MC_LED_Task(void)
{
	static u16 cnt_10ms = 1;

	cnt_10ms++;
	
	if(mc.status == MC_LOCK)
	{
		if((cnt_10ms % 50 == 0) && (cnt_10ms % 100 != 0))
		{
			LED_LEFT(0);
			LED_RIGHT(1);
		}
		else if((cnt_10ms % 50 == 0) && (cnt_10ms % 100 == 0))
		{
			LED_LEFT(1);
			LED_RIGHT(0);
		}		
	}
	else if(mc.status == MC_UNLOCK)
	{
		if((cnt_10ms % 50 == 0) && (cnt_10ms % 100 != 0))
		{
			LED_LEFT(0);
			LED_RIGHT(0);
		}
		else if((cnt_10ms % 50 == 0) && (cnt_10ms % 100 == 0))
		{
			LED_LEFT(1);
			LED_RIGHT(1);
		}		
	}
	else if(mc.status == MC_FLYING)
	{
		if((cnt_10ms % 100 == 0) || (cnt_10ms % 100 == 20))
		{
			LED_LEFT(1);
			LED_RIGHT(1);
		}
		else if((cnt_10ms % 100 == 10) || (cnt_10ms % 100 == 30))
		{
			LED_LEFT(0);
			LED_RIGHT(0);
		}
	}
	else if((mc.status == MC_FLYING_LP) || (mc.status == MC_LP))
	{
		if(cnt_10ms % 5 == 0)
		{
			LED_LEFT_TOGGLE;
			LED_RIGHT_TOGGLE;
		}
	}
	


	if(cnt_10ms > 10000) cnt_10ms = 1;
	
}


