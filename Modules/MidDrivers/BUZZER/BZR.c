/*	
 * 	Name: PMG
 * 	Apr 22, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: BZR.c
 */
#include "BZR.h"
#include "Typedef.h"
#include "TPM.h"

static uint8 u8Activate = 0;
static uint8 u8Status = 0;

void BZR_vMain ( void )
{	
	if(u8Activate == 1)
	{
		if(u8Status == 0)
		{
			/*Turn OFF Buzzer*/
			TPM_vSetPWM(enTPM2, enChannel1, 0);
			u8Status = 1;
		}
		else
		{
			/*Turn ON Buzzer*/
			TPM_vSetPWM(enTPM2, enChannel1, 320);
			u8Status = 0;
		}
	}
}

void BZR_vActivateBuzzer( void )
{
	u8Activate = 1;
}

void BZR_vDeactivateBuzzer ( void )
{
	u8Activate = 0;
	TPM_vSetPWM(enTPM2, enChannel1, 0);
}
