/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "SysInit.h"
#include "Sch.h"

int main(void)
{
	SI_vInitSystem();
	for(;;) 
	{	  
		SCH_vMonitor();
		/*
		if(UART_CHECK_STATUS(UART_RX_DONE))
		{
			UART_bfnRxBuffer();
		}*/
	}
	return 0;
}



