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

#define MOD_VALUE_TPM1			50000
#define MOD_VALUE_TPM2			50000

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

#endif /* TPM_H_ */
