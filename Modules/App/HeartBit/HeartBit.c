/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: HeartBit.c
 */

#include "HeartBit.h"

static uint8 u8WarningYellowLed = 0;

void HB_vInit ( void )
{
	HB_TURN_OFF_HEART_BIT;
}

void HB_vTask( void )
{
	HB_TOGGLE_HEART_BIT;
	if(u8WarningYellowLed)
	{
		HB_TOGGLE_YELLOW_LED;
	}
	else
	{
		/*Nothing to do*/
	}
}

void HB_vActiveYellowLed ( void )
{
	u8WarningYellowLed = 1;
}

void HB_vDeactiveYellowLed ( void )
{
	u8WarningYellowLed = 0;
	HB_TURN_OFF_YELLOW_LED;
}
