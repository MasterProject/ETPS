/*	
 * 	Name: P. Molina
 * 	Feb 11, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: ADC.h
 */

#ifndef ADC_H_
#define ADC_H_

#include "MKL25Z4.h"
#include "Typedef.h"

extern void ADC_vInit(void);
extern uint16 ADC_u16ReadChannel(uint8 Channel);


#define ADC_nBITS_CONFIG			3	/*!16 bits conversion*/
#define ADC_nCLKSRC_CONFIG			0	/*!The divide ratio is 1 and the clock rate is input clock*/

#endif /* ADC_H_ */
