/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "GPIO.h"
#include "TPM.h"
#include "ADC.h"
#include "Test.h"

int main(void)
{
#if(TEST == ON)
	static uint8 u8Freq = 0;
#endif
	
	GPIO_vPinsInit();
	TPM_vInit();
	ADC_vInit();
	
	for(;;) 
	{	  
#if(TEST == ON)
		TEST_vChangingFreq(u8Freq);
#endif
	}
	
	return 0;
}
