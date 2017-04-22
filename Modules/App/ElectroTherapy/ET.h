/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: ET.h
 */

#ifndef ET_H_
#define ET_H_

#include "Test.h"
#include "Debouncer.h"
#include "TPM.h"

#define KeyPressed			1

#define MaxFrequency		100
#define MinFrequency		20

#define MaxPWM				100
#define MinPWM				0

//#define FreqRange		(MaxFrequency - MinFrequency)
//#define FreqResolution	((FreqRange)/(100))
//#define PWMResolution	((MaxPWM - MinPWM)/(100))

void ET_Dumy ( void );

void ET_UpdateFrequency ( uint8 u8Frequency );
void ET_UpdatePWM ( uint8 u8PWM );

extern void TPM_vChangeDutyCycle(TPM_tenModules enModule, TPM_tenChannels enChannel, uint8 u8DutyCycle);
extern void TPM_vChangeFrecuency(TPM_tenModules enModule, TPM_tenChannels enChannel, uint8 u8Frecuency);

#endif /* ET_H_ */
