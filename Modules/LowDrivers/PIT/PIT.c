
#include "PIT.h"

void PIT_vInit( void )
{
	/* enable the PIT clock */
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	
	/* Enable PIT interrupt to CPU */
	NVIC_ISER |= (1<<22);
	
	/* Enable the PIT module and the debug mode */
	PIT_MCR &= ~PIT_MCR_MDIS_MASK;
	PIT_MCR |= PIT_MCR_FRZ_MASK;
	/* Load the target count to the Counter0 */
	PIT_LDVAL0 = 52500;
	/* Start the counter and enable interrupts */
	PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK|PIT_TCTRL_TIE_MASK;
}
