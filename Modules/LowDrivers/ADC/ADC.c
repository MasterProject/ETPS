/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: ADC.c
 */

#include "ADC.h"

void ADC_vInit(void)
{
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;								
	ADC0_CFG1 |= (ADC_CFG1_MODE(ADC_nBITS_CONFIG) | ADC_CFG1_ADIV(ADC_nCLKSRC_CONFIG));
	ADC0_SC1A  = ADC_SC1_ADCH(31); 									/*Turn off the ADC*/
}

uint16 ADC_u16ReadChannel(uint8 u8Channel)
{
	ADC0_SC1A = u8Channel & ADC_SC1_ADCH_MASK; 	/*Write to SC1A the channel to start conversion*/
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK);  		/*Conversion in progress*/
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK));	/*Until conversion complete*/
	return ADC0_RA;								/*Return the data*/
}
