/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: ET.c
 */

#include "ET.h"


void ET_UpdateFrequency ( uint8 u8RawFrequency )
{
	float fFreqRange =	(MaxFrequency - MinFrequency);
	float fFreqResolution = (fFreqRange/100);
	uint8 u8Frequency = (MinFrequency + (u8RawFrequency * fFreqResolution));
	if ((u8Frequency <= MaxFrequency) && (u8Frequency >= MinFrequency))
	{
		TEST_vChangingFreq ( u8Frequency );
	}
}

void ET_UpdatePWM ( uint8 u8RawPWM )
{
	TPM_tenModules enMod = enTPM1;
	TPM_tenChannels enChan = enChannel0;
	float fPWMRange = (MaxPWM - MinPWM);
	float fPWMResolution = (fPWMRange/(100));
	uint8 u8PWM = (MinPWM + (u8RawPWM * fPWMResolution));
			
	if ((u8PWM <= MaxPWM )&& (u8PWM >= MinPWM))
	{
		TPM_vChangeDutyCycle(enMod, enChan, u8PWM);
	}
}
