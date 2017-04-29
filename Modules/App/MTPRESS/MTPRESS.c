/*
 * MTPRESS.c
 *
 *  Created on: Apr 3, 2017
 *      Author: Issac
 */

/***************************************************************************************************

Monitor Pressre calculated with Saturation of Oxigen on blod (SpO2)


**************************************************************************************************/


#include "IIC.h"
#include "MTPRESS.h"
#include "math.h"
#include "UART.h"	
#include "HeartBit.h"

// SaO2 Look-up Table

const uint8_t spO2LUT[43] = {100,100,100,100,99,99,99,99,99,99,98,98,98,98,
                                             98,97,97,97,97,97,97,96,96,96,96,96,96,95,95,
                                             95,95,95,95,94,94,94,94,94,93,93,93,93,93};



void MTPRESS_vMain(void)
{
	static uint8 u8Counter = 0;

	static uint8 u8DataArduino_SPO2 = 0;
	//static float f32DataPression = 0;
	static uint8 u8DataPression = 0;
	

	
	
	u8DataArduino_SPO2 = UART_bfnRxBuffer();/*Data SPO2 from Arduino*/
	
	if(u8DataArduino_SPO2 > BEAT_DETECTED)
	{
		u8DataPression = (0.6014* (exp(0.05208*u8DataArduino_SPO2)));;
		
		if(u8DataPression < LOW_PRESSURE)
		{
			HB_vActiveYellowLed(); /*Low pressure enabled*/
		}
		else{
			HB_vDeactiveYellowLed();
		}
		
	}
	
	else/*Not Beat detected*/
	{
		HB_vActiveYellowLed();
		u8DataPression = u8DataArduino_SPO2;
	}
	
	//u8DataPression = (int)f32DataPression;
	HMI_vSetPressure(u8DataPression);
	

}


