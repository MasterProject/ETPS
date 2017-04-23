///*	
// * 	Name: PMG
// * 	Mar 4, 2017
// * 	e-mail: paul-mg@hotmail.com
// * 	phone: 3318920660
// * 	Header File
// * 	filename: LCD.c
// */

#include "LCD.h"

typedef struct
{
	uint8* pu8CurrentData;
	uint8 u8RowDataCounter;
	uint8 u8TotalDataCounter;
	LCD_tenStates enCurrentState;
	LCD_tenStates enNextState;
	LCD_tenCMDorData enTypeOfData;
	uint8 u8CMDDelay;
}LCD_stStateMachine;

static LCD_stStateMachine _stLCDDriver;

static const uint8 au8LCDConfig[] = 
{
		LCD_INIT_CMD0,
		LCD_INIT_CMD1,
		LCD_INIT_CMD2
};


uint8 au8LCDBuffer[LCD_SIZE_Y][LCD_SIZE_X+1];

void _vIdle ( void );
void _vWriteCMD ( void );
void _vWriteData ( void );
void _vEnable ( void );
void _vDisable ( void );
void _vDelayCMD ( void );

void (* vpaStates[])(void) =
{
	(void (*)(void))_vIdle,
	(void (*)(void))_vWriteCMD,
	(void (*)(void))_vWriteData,
	(void (*)(void))_vEnable,
	(void (*)(void))_vDisable,
	(void (*)(void))_vDelayCMD
};

void LCD_vWriteData ( uint8 u8Data )
{
	
	if( u8Data & (1 << 0) )
	{
		LCD_nSET_D0;	
	}
	else
	{
		LCD_nCLEAR_D0;
	}
	
	if( u8Data & (1 << 1) )
	{
		LCD_nSET_D1;
	}
	else
	{
		LCD_nCLEAR_D1;
	}
	
	if( u8Data & (1 << 2) )
	{
		LCD_nSET_D2;
	}
	else
	{
		LCD_nCLEAR_D2;
	}
	
	if( u8Data & (1 << 3) )
	{
		LCD_nSET_D3;
	}
	else
	{
		LCD_nCLEAR_D3;
	}
	
	if( u8Data & (1 << 4) )
	{
		LCD_nSET_D4;
	}
	else
	{
		LCD_nCLEAR_D4;
	}
	
	if( u8Data & (1 << 5) )
	{
		LCD_nSET_D5;
	}
	else
	{
		LCD_nCLEAR_D5;
	}
	
	if( u8Data & (1 << 6) )
	{
		LCD_nSET_D6;
	}
	else
	{
		LCD_nCLEAR_D6;
	}
	
	if( u8Data & (1 << 7) )
	{
		LCD_nSET_D7;
	}
	else
	{
		LCD_nCLEAR_D7;
	}
}


void LCD_vInit ( void )
{
	_stLCDDriver.u8TotalDataCounter = 3;
	_stLCDDriver.pu8CurrentData = &au8LCDConfig[0];
	_stLCDDriver.enCurrentState = LCD_enWriteCMD;
}

void LCD_vDriver ( void )
{
	vpaStates[_stLCDDriver.enCurrentState]();
}

void _vIdle ( void )
{
	/*!Nothing to do*/
}

void _vWriteCMD ( void )
{
	if(_stLCDDriver.u8TotalDataCounter-- != 0)
	{
		LCD_nRS_OFF;
		LCD_vWriteData(*(_stLCDDriver.pu8CurrentData++));
		_stLCDDriver.enCurrentState = LCD_enEnable;
		_stLCDDriver.enNextState = LCD_enDelayCMD;
		_stLCDDriver.u8CMDDelay = 1;
	}
	else
	{
		_stLCDDriver.enCurrentState = LCD_enIdle;
	}
}

void _vWriteData ( void )
{
	if(_stLCDDriver.u8TotalDataCounter-- != 0)
	{
		if(_stLCDDriver.u8RowDataCounter-- != 0)
		{
			LCD_nRS_ON;
			LCD_vWriteData(*(_stLCDDriver.pu8CurrentData));
			(_stLCDDriver.pu8CurrentData)++;
		}
		else
		{
			_stLCDDriver.u8RowDataCounter = 18;
			LCD_nRS_OFF;
			_stLCDDriver.pu8CurrentData++;
			_stLCDDriver.pu8CurrentData++;
			_stLCDDriver.pu8CurrentData++;
			LCD_vWriteData(LCD_JUMPLINE_CMD);
			
		}
		_stLCDDriver.enCurrentState = LCD_enEnable;
		_stLCDDriver.enNextState = LCD_enWriteData;
	}
	else
	{
		_stLCDDriver.enCurrentState = LCD_enIdle;
	}
	
}

void _vEnable ( void )
{
	LCD_nENABLE_ON;
	_stLCDDriver.enCurrentState = LCD_enDisable;
}

void _vDisable ( void )
{
	LCD_nENABLE_OFF;
	_stLCDDriver.enCurrentState = _stLCDDriver.enNextState;
}

void _vDelayCMD ( void )
{
	if(_stLCDDriver.u8CMDDelay-- == 0 )
	{
		_stLCDDriver.enCurrentState =  LCD_enWriteCMD;
	}
	else
	{
		/*Nothing to do*/
	}
}

void LCD_vUpdateScreen ( uint8* pu8NewScreen )
{
	if(_stLCDDriver.enCurrentState == LCD_enIdle)
	{
		_stLCDDriver.pu8CurrentData = pu8NewScreen;
		_stLCDDriver.u8TotalDataCounter = 33;
		_stLCDDriver.u8RowDataCounter = 16;
		_stLCDDriver.enCurrentState = LCD_enWriteData;
	}
	else
	{
		/*Nothing to do*/
	}
}

void LCD_vClearScreen ( void )
{
	_stLCDDriver.enCurrentState = LCD_enWriteCMD;
	_stLCDDriver.u8TotalDataCounter = 0x1;
	_stLCDDriver.pu8CurrentData = &au8LCDConfig[2];
}

uint8 LCD_u8IsBusy ( void )
{
	uint8 u8State = 0;
	if(_stLCDDriver.enCurrentState == LCD_enIdle)
	{
		u8State = 1;
	}
	else
	{
		/*Nothing to do*/
	}
	return u8State;
}

