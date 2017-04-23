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
#include "LCD.h"
#include "HMI.h"
#include "BZR.h"
#include "ET.h"

#define SCH_nTASKS 6


/*!Base Time 1 miliseconds*/
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
		DBNCR_vMonitor,			\
		0,						\
		15,						\
		0						\
	},							\
	{							\
		LCD_vDriver,			\
		0,						\
		1,						\
		1						\
	},							\
	{							\
		HMI_vMain,				\
		0,						\
		10,						\
		0						\
	},							\
	{							\
		BZR_vMain,				\
		0,						\
		500,					\
		0						\
	},							\
	{							\
		HB_vTask,				\
		0,						\
		500,					\
		0						\
	},							\
	{							\
		ET_vMain,				\
		0,						\
		50,						\
		0						\
	}							\
}								


extern void SCH_vMonitor ( void );

#endif /* SCH_H_ */
