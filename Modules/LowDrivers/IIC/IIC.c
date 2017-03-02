/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: IIC.c
 */

#include "IIC.h"

void Pause(int number)
{
	int cnt;
	for(cnt=0; cnt<number; cnt++)
	{
		asm("nop");
	};
}

void IIC_vInit ( void )
{
	SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;		/* Turn on clock to I2C0 module */
	I2C0_F  |= I2C_F_ICR(0x14); 			/* SDA hold time = 2.125us, SCL start hold time = 4.25us, SCL stop hold time = 5.125us*/
	I2C0_C1 |= I2C_C1_IICEN_MASK;    		/* Enable I2C0 module*/
}

void IIC_vWrite( uint8 u8SlaveAddress, uint8 u8RegisterAddress, uint8 u8Data )
{
	I2C0_C1 |= I2C_C1_TX_MASK;
	I2C0_C1 |= I2C_C1_MST_MASK;
	
	I2C0_D = u8SlaveAddress;									/* Send I2C device address with W/R bit = 0 */
	
	while((I2C0_S & I2C_S_IICIF_MASK)==0);
	I2C0_S |= I2C_S_IICIF_MASK;

	I2C0_D = u8RegisterAddress;										/* Send register address */
	while((I2C0_S & I2C_S_IICIF_MASK)==0);
	I2C0_S |= I2C_S_IICIF_MASK;
	
	I2C0_D = u8Data;												/* Send the data */
	while((I2C0_S & I2C_S_IICIF_MASK)==0);
	I2C0_S |= I2C_S_IICIF_MASK;

	I2C0_C1 &= ~I2C_C1_MST_MASK;
	I2C0_C1 &= ~I2C_C1_TX_MASK;

    Pause(50);
}

uint8 IIC_u8Read(uint8 u8SlaveAddress, uint8 u8RegisterAddress)
{
	uint8 result;
	  
	I2C0_C1 |= I2C_C1_TX_MASK;
	I2C0_C1 |= I2C_C1_MST_MASK;
	
	I2C0_D = 0xAE;									/* Send I2C device address with W/R bit = 0 */
	
	while((I2C0_S & I2C_S_IICIF_MASK)==0);
	I2C0_S |= I2C_S_IICIF_MASK;					

	I2C0_D = u8RegisterAddress;										/* Send register address */
	
	while((I2C0_S & I2C_S_IICIF_MASK)==0);
	I2C0_S |= I2C_S_IICIF_MASK;

	I2C0_C1 |= I2C_C1_RSTA_MASK;
	
	I2C0_D = 0xAF;							/* Send I2C device address this time with W/R bit = 1 */ 
	
	while((I2C0_S & I2C_S_IICIF_MASK)==0);
	I2C0_S |= I2C_S_IICIF_MASK;	

	I2C0_C1 &= ~I2C_C1_TX_MASK;					/*!RxMode*/
	I2C0_C1 |= I2C_C1_TXAK_MASK;				/*!Ack Disable*/

	result = I2C0_D;
	
	while((I2C0_S & I2C_S_IICIF_MASK)==0);
	I2C0_S |= I2C_S_IICIF_MASK;
	
	I2C0_C1 &= ~I2C_C1_MST_MASK;
	I2C0_C1 &= ~I2C_C1_TX_MASK;
	
	result = I2C0_D;
	
	Pause(50);
	return result;
}
