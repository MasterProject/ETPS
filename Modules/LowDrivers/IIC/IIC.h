/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: IIC.h
 */

#include "MKL25Z4.h"
#include "Typedef.h"

#ifndef IIC_H_
#define IIC_H_

extern void IIC_vInit ( void );
extern void IIC_vWrite( uint8 u8SlaveAddress, uint8 u8RegisterAddress, uint8 u8Data );
extern uint8 IIC_u8Read(uint8 u8SlaveAddress, uint8 u8RegisterAddress);


#endif /* IIC_H_ */
