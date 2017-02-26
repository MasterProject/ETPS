/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: HeartBit.h
 */

#ifndef HEARTBIT_H_
#define HEARTBIT_H_

#include "MKL25Z4.h"
#include "Typedef.h"

#define HB_TURN_OFF_HEART_BIT		GPIOD_PDOR &= ~(1 << 1)
#define HB_TOGGLE_HEART_BIT			GPIOD_PTOR |= (1 << 1)

#define HB_TOGGLE_RED_LED			GPIOA_PTOR |=  (1 << 1)
#define HB_TOGGLE_ANOTHER_LED		GPIOA_PTOR |=  (1 << 2)

extern void HB_vInit ( void );
extern void HB_vTask( void );
extern void HB_vTaskRedLed ( void );
extern void HB_vTaskAnotherLed ( void );

#endif /* HEARTBIT_H_ */
