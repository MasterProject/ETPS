/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "SysInit.h"
#include "Sch.h"
#include "IIC.h"

int main(void)
{
	uint8 u8Data = 0;
	static uint8 u8RW = 0;
	static uint8 u8Reg = 0;
	static uint8 u8DataTx;
	SI_vInitSystem();
	IIC_vInit();
	
	for(;;) 
	{	  
		if(u8RW == 0)
		{
			u8Data = IIC_u8Read(0xAF, u8Reg);	
		}
		else
		{
			IIC_vWrite(0xAE, u8Reg, u8DataTx);
		}
		asm("nop");
	}
	return 0;
}



