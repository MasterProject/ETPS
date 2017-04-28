/*	
 * 	Name: PMG
 * 	Feb 26, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: SysInit.h
 */

#ifndef SYSINIT_H_
#define SYSINIT_H_

#include "derivative.h" /* include peripheral declarations */
#include "GPIO.h"
#include "TPM.h"
#include "ADC.h"
#include "Test.h"
#include "PIT.h"
#include "HeartBit.h"
#include "LCD.h"
#include "IRQ.h"
#include "MGCDvr.h"
#include "UART.h"
extern void SI_vInitSystem ( void );

#endif /* SYSINIT_H_ */
