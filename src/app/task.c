#include "task.h"
#include "bsp\led\led.h"
#include "bsp\usart\usart1.h"
#include "bsp\delay\delay.h"
#include "i_uwb_lps.h"


TASK_TIME Task_Time;


/*
 * Function Name:Task_1Ms
 * Description	:1ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_1Ms(void)
{
	
}

/*
 * Function Name:Task_2Ms
 * Description	:2ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_2Ms(void)
{
	
}

/*
 * Function Name:Task_5Ms
 * Description	:5ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_4Ms(void)
{
	
}

/*
 * Function Name:Task_5Ms
 * Description	:5ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_5Ms(void)
{

}

/*
 * Function Name:Task_10Ms
 * Description	:10ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_10Ms(void)
{
	I_UWB_LPS_Tag_Data_Update();
}

/*
 * Function Name:Task_20Ms
 * Description	:20ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_20Ms(void)
{

}

/*
 * Function Name:Task_40Ms
 * Description	:40ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_40Ms(void)
{

}

/*
 * Function Name:Task_50Ms
 * Description	:50ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_50Ms(void)
{

}

/*
 * Function Name:Task_150Ms
 * Description	:150ms task,user can add his function to this task,but the runtime of function must be considered
 * Input  			:None
 * Output  			:None
 */
void Task_150Ms(void)
{
	LED_TOGGLE;
}

/*
 * Function Name:System_Task_Loop
 * Description	:the main loop
 * Input  			:None
 * Output  			:None
 */
void System_Task_Loop(void)
{
	if(Task_Time.Cnt_1Ms >= 1)
	{
		Task_Time.Cnt_1Ms = 0;
		Task_1Ms();
	}
	
	if(Task_Time.Cnt_2Ms >= 2)
	{
		Task_Time.Cnt_2Ms = 0;
		Task_2Ms();
	}
	
	if(Task_Time.Cnt_4Ms >= 4)
	{
		Task_Time.Cnt_4Ms = 0;
		Task_4Ms();
	}
	
	if(Task_Time.Cnt_5Ms >= 5)
	{
		Task_Time.Cnt_5Ms = 0;
		Task_5Ms();
	}

	if(Task_Time.Cnt_10Ms >= 10)
	{
		Task_Time.Cnt_10Ms = 0;
		Task_10Ms();
	}

	if(Task_Time.Cnt_20Ms >= 20)
	{
		Task_Time.Cnt_20Ms = 0;
		Task_20Ms();
	}
	
	if(Task_Time.Cnt_40Ms >= 40)
	{
		Task_Time.Cnt_40Ms = 0;
		Task_40Ms();
	}
	
	if(Task_Time.Cnt_50Ms >= 50)
	{
		Task_Time.Cnt_50Ms = 0;
		Task_50Ms();
	}
	
	if(Task_Time.Cnt_150Ms >= 150)
	{
		Task_Time.Cnt_150Ms = 0;
		Task_150Ms();
	}	
}	


