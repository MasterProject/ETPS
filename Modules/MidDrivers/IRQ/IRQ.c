/*	
 * 	Name: PMG
 * 	Mar 1, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: IRQ.c
 */

#include "IRQ.h"
#include "HMI.h"

void IRQ_vInit( void )
{
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	
	/*Enable Interrupts*/
	asm(" CPSIE i");
	
	/* Set the ICPR and ISER registers accordingly */
	NVIC_ICPR |= 1 << ((INT_PORTA -16)%32);
	NVIC_ISER |= 1 << ((INT_PORTA -16)%32);
	
	/*!Emergency Stop Button*/
	 PORTA_PCR13 |= PORT_PCR_MUX(1)|PORT_PCR_IRQC(0x8)|PORT_PCR_PE_MASK;
	GPIOA_PDDR &= ~( 1 << 13 );
}

void PORTA_IRQHandler(void)
{
	static uint8 u8Entry = 0;
	
	/*!Emergency Button Code*/
	if(u8Entry)
	{
		HMI_vSetEmergencyStop();	
	}
	else
	{
		u8Entry++;
	}
	
	asm("nop");
	/*!Clearing Interruption Flag*/
	PORTA_ISFR = (1 << 13);
	
}
