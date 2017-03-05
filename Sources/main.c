/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "SysInit.h"
#include "Sch.h"
#include "Debouncer.h"

int main(void)
{
	uint8 u8FreqButton;
	uint8 u8PWMButton;
	
	SI_vInitSystem();
	
	for(;;) 
	{	  
		SCH_vMonitor();
	}
	return 0;
}



