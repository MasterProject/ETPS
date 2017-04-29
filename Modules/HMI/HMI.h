/*	
 * 	Name: PMG
 * 	Apr 9, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: HMI.h
 */

#include "LCD.h"
#include "MKL25Z4.h"

#ifndef HMI_H_
#define HMI_H_

#include "Typedef.h"


typedef enum
{
	HMI_enWelcomeScreen = 0,
	HMI_enTherapySelectedScreen,
	HMI_enPressureSelectedScreen,
	HMI_enFreqSelectedScreen,
	HMI_enIntsSelectedScreen,
	HMI_enFreqValueScreen,
	HMI_enInstValueScreen,
	HMI_enPressureValueScreen,
	HMI_enClearScreen,
	HMI_enEmergencyState,
	HMI_enPswrdState0,
	HMI_enPswrdState1,
	HMI_enPswrdState2,
	HMI_enPswrdState3,
	HMI_enPswrdState4
}HMI_tenScreens;

typedef struct 
{
	HMI_tenScreens enCurrentState;
	HMI_tenScreens enNextState;
}HMI_enStateMachine;


void HMI_vMain ( void );
void HMI_vSetEmergencyStop ( void );
uint8 HMI_vGetEmergencyStop ( void );
uint8 HMI_u8GetFreqValue ( void );
uint8 HMI_u8GetIntsValue ( void );
void HMI_vSetPressure ( uint8 u8Press_value );

#endif /* HMI_H_ */
