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
	GPIO_vPinsInit();
	TPM_vInit();
	ADC_vInit();
	
	for(;;) 
	{	  
		TEST_vBlinkTestPWM();
	}
	
	return 0;
}
