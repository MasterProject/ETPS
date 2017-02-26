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
	}
	return 0;
}



