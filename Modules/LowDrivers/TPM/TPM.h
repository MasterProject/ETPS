/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: TPM.h
 */

#ifndef TPM_H_
#define TPM_H_

#include "MKL25Z4.h"
#include "Typedef.h"

#define MOD_VALUE_TPM1			32000
#define MOD_VALUE_TPM2			328

#define MOD_K_CONSTANT			328125
#define MAX_FREQ_ALLOWED		101

typedef enum
{
	enTPM0,
	enTPM1,
	enTPM2
}TPM_tenModules;

typedef enum
{
	enChannel0,
	enChannel1
}TPM_tenChannels;

extern void TPM_vInit(void);
extern void TPM_vSetPWM(TPM_tenModules enModule, TPM_tenChannels enChannel, uint16 u16Value);
extern void TPM_vChangeFrecuency(TPM_tenModules enModule, TPM_tenChannels enChannel, uint16 u8Frecuency);
void TPM_vChangeDutyCycle(TPM_tenModules enModule, TPM_tenChannels enChannel, uint8 u8DutyCycle);

#endif /* TPM_H_ */
