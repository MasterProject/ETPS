/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: ET.c
 */
#include "ET.h"
#include "HMI.h"
#include "TPM.h"

void ET_vMain ( void )
{
	uint8 u8CurrentFreq = 0;
	uint8 u8CurrentInts = 0;
	static uint8 u8PrevFreq = 0;
	static uint8 u8PrevInts = 0;
	
	u8CurrentFreq = HMI_u8GetFreqValue();
	u8CurrentInts = HMI_u8GetIntsValue();
	
	if(u8CurrentFreq != u8PrevFreq)
	{
		u8PrevFreq =  u8CurrentFreq;
		u8CurrentFreq = u8CurrentFreq * 80 / 100;
		u8CurrentFreq+= 20;
		/*Set Freq to Interface*/
		TPM_vChangeFrecuency(enTPM1, enChannel0, u8CurrentFreq);
		TPM_vChangeDutyCycle(enTPM1, enChannel0, u8CurrentInts);
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(u8CurrentInts != u8PrevInts)
	{
		u8PrevInts = u8CurrentInts;
		/*Set Ints to Interface*/
		TPM_vChangeDutyCycle(enTPM1, enChannel0, u8CurrentInts);
	}
	else
	{
		/*Nothing to do*/
	}
}
