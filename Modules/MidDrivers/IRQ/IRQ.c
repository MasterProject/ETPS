/*	
 * 	Name: PMG
 * 	Mar 1, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: IRQ.c
 */

#include "IRQ.h"

void IRQ_vInit( void )
{
	/*Enable Interrupts*/
	asm(" CPSIE i");
	
	/* Set the ICPR and ISER registers accordingly */
	NVIC_ICPR |= 1 << ((INT_PORTA -16)%32);
	NVIC_ISER |= 1 << ((INT_PORTA -16)%32);
	
	/*!Emergency Stop Button*/
	PORTA_PCR13 |= PORT_PCR_IRQC(10) | PORT_PCR_PE_MASK;
}

void PORTA_IRQHandler(void)
{
	/*!Emergency Button Code*/
	
	asm("nop");
	/*!Clearing Interruption Flag*/
	PORTA_ISFR = (1 << 13);
	
}
