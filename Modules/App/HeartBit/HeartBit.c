/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: HeartBit.c
 */

#include "HeartBit.h"

void HB_vInit ( void )
{
	HB_TURN_OFF_HEART_BIT;
}

void HB_vTask( void )
{
	HB_TOGGLE_HEART_BIT;
}

void HB_vTaskRedLed ( void )
{
	HB_TOGGLE_RED_LED;
}

void HB_vTaskAnotherLed ( void )
{
	HB_TOGGLE_ANOTHER_LED;
}
