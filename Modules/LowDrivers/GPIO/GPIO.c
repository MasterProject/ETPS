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
	/*Enable Clock Gate*/
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK |SIM_SCGC5_PORTE_MASK;		
	
	/*!Freq to Power Circuit*/
	PORTE_PCR20 = PORT_PCR_MUX(3);			/*!Mux = TPM1_CH0*/
	
	/*!Freq to Buzzer*/
	PORTE_PCR21 = PORT_PCR_MUX(3);			/*!Mux = TPM1_CH1*/
	
	/*!Blue Extern Led Heart Bit*/
	PORTD_PCR1  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOD_PDDR |= (1 << 1);
	
	/*!Red Extern Led Alert*/
	PORTC_PCR10 = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOC_PDDR |= (1 << 10);
	
	/*!Yellow Extern Led Pressure*/
	PORTC_PCR11 = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOC_PDDR |= (1 << 11);
	
	/*!Pot for Therapy*/
	PORTB_PCR0  = PORT_PCR_MUX(0);			/*!Mux = ADC0_SE8*/
	
	/*!Pot for Therapy*/
	PORTB_PCR1  = PORT_PCR_MUX(0);			/*!Mux = ADC0_SE9*/
	
	/*!SCL for Pressure Sensor*/		
	PORTB_PCR2  = PORT_PCR_MUX(2);			/*!Mux = I2C0_SCL*/
	
	/*!SDA for Pressure Sensor*/
	PORTB_PCR3  = PORT_PCR_MUX(2);			/*!Mux = I2C0_SDA*/
	
	/*!Push Button Return*/
	PORTB_PCR11  = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;;			/*!Mux = GPIO*/
	GPIOB_PDDR &= ~( 1 << 11 );
	
	/*!Push Button Ok*/
	PORTB_PCR10  = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;;			/*!Mux = GPIO*/
	GPIOB_PDDR &= ~( 1 << 10 );
	
	/*!Push Button UP*/
	PORTB_PCR8  = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;			/*!Mux = GPIO*/
	GPIOB_PDDR &= ~( 1 << 8 );
	
	/*!Push Button Down*/
	PORTB_PCR9  = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;			/*!Mux = GPIO*/
	GPIOB_PDDR &= ~( 1 << 9 );
	
	/*!Push Button Emergency*/
	PORTB_PCR10 = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOB_PDDR &= ~( 1 << 10 );
	
	/*!Switch to Stop Power Circuit*/
	PORTE_PCR2  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOE_PDDR |= ( 1 << 2 );
	
	/*!PIN to Test Times*/
	PORTE_PCR3  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOE_PDDR |= ( 1 << 3 );
	
	/*!LCD D0*/
	PORTA_PCR1  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOA_PDDR |= ( 1 << 1 );
	
	/*!LCD D1*/
	PORTA_PCR2  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOA_PDDR |= ( 1 << 2 );
	
	/*!LCD D2*/
	PORTD_PCR4  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOD_PDDR |= ( 1 << 4 );
	
	/*!LCD D3*/
	PORTA_PCR12 = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOA_PDDR |= ( 1 << 12 );
	
	/*!LCD D4*/
	PORTA_PCR4  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOA_PDDR |= ( 1 << 4 );
	
	/*!LCD D5*/
	PORTA_PCR5  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOA_PDDR |= ( 1 << 5 );
	
	/*!LCD D6*/
	PORTC_PCR8  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOC_PDDR |= ( 1 << 8 );
	
	/*!LCD D7*/
	PORTC_PCR9  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOC_PDDR |= ( 1 << 9);
	
	/*!LCD RS*/
	PORTC_PCR7  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOC_PDDR |= ( 1 << 7);
	
	/*!LCD RW*/
	PORTC_PCR0  = PORT_PCR_MUX(1);			/*!Mux = GPIO*/
	GPIOC_PDDR |= ( 1 << 0 );
	
}
