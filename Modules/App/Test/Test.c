/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: Test.c
 */

#include "Test.h"
#include "TPM.h"

void TEST_vBlinkTestPWM ( void )
{
	static uint16 u16LedFrecuency = 0;
	
	TPM_vSetPWM(enTPM1, enChannel0, u16LedFrecuency);
}


