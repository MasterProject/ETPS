/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: Sch.h
 */

#ifndef SCH_H_
#define SCH_H_

#include "Typedef.h"
#include "MKL25Z4.h"
#include "HeartBit.h"
#include "Debouncer.h"

#define SCH_nTASKS 3


/*!Base Time 5 miliseconds*/
/*!Here define your task as:
 *
 *Task_Function
 *Initial Time
 *Target Time
 *Execute Flag Status 
 */

#define SHC_nTASK_DEFINITION 	\
{								\
	{							\
		HB_vTask,				\
		0,						\
		100,					\
		0						\
	},							\
	{							\
		DBNCR_vMonitor,			\
		0,						\
		4,					\
		0						\
	},							\
	{							\
		HB_vTaskAnotherLed,		\
		0,						\
		50,						\
		0						\
	}							\
}								

extern void SCH_vMonitor ( void );

#endif /* SCH_H_ */
