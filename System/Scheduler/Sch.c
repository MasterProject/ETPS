/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: Sch.c
 */

#include "Sch.h"

#define TIME_TASK 100

typedef struct
{
	void (*TaskFunction) (void);
	uint16 u16CurrentTaskTime;
	uint16 u16TargetTaskTime;
	uint8  u8FlagToExectue;
}SCH_tstTaskStruct;

static SCH_tstTaskStruct _astTasks[SCH_nTASKS] = SHC_nTASK_DEFINITION;

void SCH_vMonitor ( void )
{
	uint16 u16TaskIndex = 0;
	
	while(u16TaskIndex != SCH_nTASKS)
	{
		if( _astTasks[u16TaskIndex].u8FlagToExectue )
		{
			_astTasks[u16TaskIndex].TaskFunction();
			_astTasks[u16TaskIndex].u8FlagToExectue = 0;
		}
		u16TaskIndex++;
	}
}

void PIT_IRQHandler(void)
{
	uint16 u16TaskIndex = 0;
	
	if (PIT_TFLG0 & PIT_TFLG_TIF_MASK)
	{
		PIT_TFLG0 |= PIT_TFLG_TIF_MASK;	
		
		while(u16TaskIndex != SCH_nTASKS)
		{
			if( _astTasks[u16TaskIndex].u16CurrentTaskTime == _astTasks[u16TaskIndex].u16TargetTaskTime )
			{
				_astTasks[u16TaskIndex].u8FlagToExectue = 1;
				_astTasks[u16TaskIndex].u16CurrentTaskTime = 0;
			}
			else
			{
				_astTasks[u16TaskIndex].u16CurrentTaskTime++;
			}
			
			u16TaskIndex++;
		}
	}
}

