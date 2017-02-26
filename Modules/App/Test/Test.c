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


/*Set X Freq in PIN_E20*/
void TEST_vChangingFreq ( uint8 u8Freq )
{
	TPM_vChangeFrecuency(enTPM1, enChannel0, u8Freq);
}


