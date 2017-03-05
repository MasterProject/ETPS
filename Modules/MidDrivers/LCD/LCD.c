///*	
// * 	Name: PMG
// * 	Mar 4, 2017
// * 	e-mail: paul-mg@hotmail.com
// * 	phone: 3318920660
// * 	Header File
// * 	filename: LCD.c
// */
//
//#include "LCD.h"
//
//typedef struct
//{
//	LCD_tenStates enCurrentState;
//	LCD_tenStates enNextState;
//	LCD_tenCMDorData enTypeOfData;
//}LCD_stStateMachine;
//
//static LCD_stStateMachine _stLCDDriver;
//
//uint8 au8LCDBuffer[LCD_SIZE_Y][LCD_SIZE_X+1];
//
//void _vIdle ( void );
//void _SelectTypeOfData ( void );
//void _WriteData ( void );
//void _vEnable ( void );
//void _vDisable ( void );
//
//void (* vpaStates[])(void) =
//{
//	(void (*)(void))_vIdle,
//	(void (*)(void))_vSelectTypeOfData,
//	(void (*)(void))_vWriteData,
//	(void (*)(void))_vEnable,
//	(void (*)(void))_vDisable,
//};
//
//void LCD_vWriteData ( uint8 u8Data )
//{
//	if( u8Data & (1 << 0) )
//	{
//		LCD_nSET_D0;	
//	}
//	else
//	{
//		LCD_nCLEAR_D0;
//	}
//	
//	if( u8Data & (1 << 1) )
//	{
//		LCD_nSET_D1;
//	}
//	else
//	{
//		LCD_nCLEAR_D1;
//	}
//	
//	if( u8Data & (1 << 2) )
//	{
//		LCD_nSET_D2;
//	}
//	else
//	{
//		LCD_nCLEAR_D2;
//	}
//	
//	if( u8Data & (1 << 3) )
//	{
//		LCD_nSET_D3;
//	}
//	else
//	{
//		LCD_nCLEAR_D3;
//	}
//	
//	if( u8Data & (1 << 4) )
//	{
//		LCD_nSET_D4;
//	}
//	else
//	{
//		LCD_nCLEAR_D4;
//	}
//	
//	if( u8Data & (1 << 5) )
//	{
//		LCD_nSET_D5;
//	}
//	else
//	{
//		LCD_nCLEAR_D5;
//	}
//	
//	if( u8Data & (1 << 6) )
//	{
//		LCD_nSET_D6;
//	}
//	else
//	{
//		LCD_nCLEAR_D6;
//	}
//	
//	if( u8Data & (1 << 7) )
//	{
//		LCD_nSET_D7;
//	}
//	else
//	{
//		LCD_nCLEAR_D7;
//	}
//}
//
//void LCD_vInit ( void )
//{
//	/*uint32 u8Delay = DELAY;
//
//	LCD_vWriteData(0x38);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//		
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0xF);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0x1);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_nRS_ON;
//	
//	LCD_vWriteData(0x44);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0x6F);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0x67);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0x6F);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0x50);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0x75);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0x74);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;
//	
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	
//	LCD_vWriteData(0x6F);
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_ON;
//	while(!u8Delay--);
//	u8Delay = DELAY;
//	LCD_nENABLE_OFF;*/
//}
//
//void LCD_vDriver ( void )
//{
//	vpaStates[_stLCDDriver.enCurrentState]();
//}
//
//void _vIdle ( void )
//{
//	/*!Nothing to do*/
//}
//
//void _SelectTypeOfData ( void )
//{
//	if(_stLCDDriver.enTypeOfData == LCD_enCMD)
//	{
//		LCD_nRS_OFF;
//		_stLCDDriver.enCurrentState = LCD_enWriteData;
//	}
//	else if(_stLCDDriver.enCurrentState == LCD_enData)
//	{
//		LCD_nRS_ON;
//		_stLCDDriver.enCurrentState = LCD_enWriteData;
//	}
//	else
//	{
//		_stLCDDriver.enCurrentState = LCD_enIdle;
//	}
//}
//
//void _WriteData ( void )
//{
//	
//}
//
//void _vEnable ( void )
//{
//	
//}
//
//void _vDisable ( void )
//{
//	
//}
