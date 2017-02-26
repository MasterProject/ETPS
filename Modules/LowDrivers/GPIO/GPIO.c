/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: GPIO.c
 */

#include "GPIO.h"

void GPIO_vPinsInit(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK;		/*Enable Clock Gate*/
	
	PORTE_PCR20 = PORT_PCR_MUX(3);			/*!Mux = TPM1_CH0*/
	PORTE_PCR21 = PORT_PCR_MUX(3);			/*!Mux = TPM1_CH1*/
	PORTB_PCR18 = PORT_PCR_MUX(3);			/*!Mux = TPM2_CH0*/
	
	PORTB_PCR0  = PORT_PCR_MUX(0);			/*!Mux = ADC0_SE8*/
	PORTB_PCR1  = PORT_PCR_MUX(0);			/*!Mux = ADC0_SE9*/
	PORTB_PCR2  = PORT_PCR_MUX(0);			/*!Mux = ADC0_SE12*/
	
	/*!LCD INIT*/
}
