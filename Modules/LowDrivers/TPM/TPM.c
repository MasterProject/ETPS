/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: TPM.c
 */
#include "TPM.h"

static uint16 u16CurrentMod = 0;
static uint16 u16CurrentDutyCycle = 0;

void TPM_vInit(void)
{
	SIM_SCGC6 |= SIM_SCGC6_TPM1_MASK | SIM_SCGC6_TPM2_MASK;		/*Enable TPM Clock Gate*/
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);							/*Enable the TPMSRC*/
	TPM1_MOD = MOD_VALUE_TPM1; 									/*Charging the Modulo Value*/
	TPM2_MOD = MOD_VALUE_TPM2; 									/*Charging the Modulo Value*/
	
	/*Config Channel*/
	TPM1_CnSC(0) |= (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK);
	TPM1_CnSC(1) |= (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK);
	TPM2_CnSC(0) |= (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK);
	TPM2_CnSC(1) |= (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK);
	
	/*Turn on Clocks*/
	TPM1_SC |= TPM_SC_PS(6)|TPM_SC_TOF_MASK |TPM_SC_TOIE_MASK |TPM_SC_CMOD(1);		/*ClockSource/2, TOF and TOIE enable*/
	TPM2_SC |= TPM_SC_PS(6)|TPM_SC_TOF_MASK |TPM_SC_TOIE_MASK |TPM_SC_CMOD(1);			/*ClockSource/2, TOF and TOIE enable*/
}

void TPM_vSetPWM(TPM_tenModules enModule, TPM_tenChannels enChannel, uint16 u16Value)
{
	if(enModule == enTPM0)
	{
		TPM0_CnV(enChannel) = u16Value;
	}
	else if(enModule == enTPM1)
	{
		TPM1_CnV(enChannel) = u16Value;		
	}
	else if(enModule ==  enTPM2)
	{
		TPM2_CnV(enChannel) = u16Value;
	}
	else
	{
		/*!Nothing to do*/
	}
}

void TPM_vChangeDutyCycle(TPM_tenModules enModule, TPM_tenChannels enChannel, uint8 u8DutyCycle)
{
	if( u8DutyCycle < 101 )
	{	
		u16CurrentDutyCycle = ((u8DutyCycle*u16CurrentMod)/100);
		if(enModule == enTPM0)
		{
			TPM0_CnV(enChannel) = u16CurrentDutyCycle;
		}
		else if(enModule == enTPM1)
		{
			TPM1_CnV(enChannel) = u16CurrentDutyCycle;
		}
		else if(enModule == enTPM2)
		{
			TPM2_CnV(enChannel) = u16CurrentDutyCycle;
		}
		else
		{
			/*Nothing to do*/
		}
	}
	else
	{
		/*Nothing to do*/
	}
}

void TPM_vChangeFrecuency(TPM_tenModules enModule, TPM_tenChannels enChannel, uint16 u8Frecuency)
{
	u16CurrentMod = MOD_K_CONSTANT / u8Frecuency;
	if(enModule == enTPM0)
	{
		TPM0_MOD = u16CurrentMod;
	}
	else if(enModule == enTPM1)
	{
		TPM1_MOD = u16CurrentMod;
	}
	else if(enModule == enTPM2)
	{
		TPM2_MOD = MOD_VALUE_TPM2;
	}
	else
	{
		/*Nothing to do*/
	}
}
