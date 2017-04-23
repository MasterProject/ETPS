/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "SysInit.h"
#include "Sch.h"
#include "Debouncer.h"
#include "BZR.h"

int main(void)
{
	SI_vInitSystem();
	
	for(;;) 
	{	  
		SCH_vMonitor();
	}
	return 0;
}



