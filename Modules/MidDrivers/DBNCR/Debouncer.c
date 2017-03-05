/*	
 * 	Name: PMG
 * 	Mar 1, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: Debouncer.c
 */

#include "Debouncer.h"

static const uint16 u16KeyMask[] = 
{							
	BTN_UP,
	BTN_DOWN,
	BTN_OK,
	BTN_RETURN
};

typedef struct
{
	uint8 u8ButtonState;
	uint8 u8ButtonLastState;
	uint8 u8DriverButtonState;
	uint8 u8Counter;
	uint16 u16Key;
	uint8 u8ButtonBit;
}DBNCR_tenDataStruct;

static DBNCR_tenDataStruct stButtons[TOTAL_BTNS];

void DBNCR_vUpdate ( void )
{
	uint8 u8Change = 0;
	uint8 u8Button = 0;
	uint8 u8Index = 0;
	
	while(u8Index != TOTAL_BTNS)
	{
		stButtons[u8Index].u8ButtonBit = u16KeyMask[u8Index];
		stButtons[u8Index].u16Key = 1 << stButtons[u8Index].u8ButtonBit;
		u8Change = (BTN_PORT & stButtons[u8Index].u16Key) >> stButtons[u8Index].u8ButtonBit;
		u8Change = !u8Change;
		
		if(stButtons[u8Index].u8ButtonLastState ^ u8Change )
		{
			if(stButtons[u8Index].u8Counter)
			{
				stButtons[u8Index].u8Counter--;
			}
			else
			{
				u8Button = (BTN_PORT & stButtons[u8Index].u16Key) >> stButtons[u8Index].u8ButtonBit;
				stButtons[u8Index].u8ButtonState = !u8Button;
				stButtons[u8Index].u8ButtonLastState = stButtons[u8Index].u8ButtonState;
			}
		}
		else
		{
			stButtons[u8Index].u8Counter = BTN_CHANGE_CNT;
		}
		u8Index++;
	}
}

void DBNCR_vMonitor	(void)
{
	DBNCR_vUpdate();
}

uint8 DBNCR_u8ReadButtonState( DBNCR_tenButtons enButton )
{
	uint8 u8ButtonState = 0;
	u8ButtonState = stButtons[enButton].u8ButtonState;
	stButtons[enButton].u8ButtonState = 0;
	return u8ButtonState;
}
