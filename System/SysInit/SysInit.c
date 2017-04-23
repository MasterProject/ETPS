/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: SysInit.c
 */

#include "SysInit.h"

void SI_vInitSystem ( void )
{
	GPIO_vPinsInit();
	TPM_vInit();
	ADC_vInit();
	PIT_vInit();
	HB_vInit();
	LCD_vInit();
	IRQ_vInit();
}
