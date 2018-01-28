/**************I_UWB_DT-SDK**************
 *	File					:				main.c
 *  IDE						:			  MDK5.14
 *	Author				:	 		  	INF						
 *	Support				:		 www.inffuture.com
 *	QQ Group			:   	  168590475
 *  Github				: https://github.com/inf-labs
 *	Copyright			:	 				 INF
 *	Last Time			:			  20180128
 *			For infinite creativity
 */

#include "system_init.h"
#include "task.h"

/*
 * Function Name:main
 * Description	: 
 * Input  			:None
 * Output  			:None
 */
int main(void)
{
	System_Init();											//system initialize
  while(1)
	{
		System_Task_Loop();
	}
}

