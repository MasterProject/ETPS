/*	
 * 	Name: PMG
 * 	Apr 9, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: HMI.c
 */
#include "HMI.h"
#include "Debouncer.h"
#include "BZR.h"

static HMI_enStateMachine _stHMISM;
static uint8 au8TransferBuffer[LCD_SIZE_Y][LCD_SIZE_X];
static uint8 u8ScreenUpdated = 0;

static uint8 u8FreqValue = 0;
static uint8 u8IntsValue = 0;

static uint8 u8EmergencyStop = 0;
static uint8 u8CorrectPassword = 0;


static uint8 u8EmergencyActive = 0;

void _vWelcomeScreen ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "  ETPS Welcome  ");
		sprintf ( &au8TransferBuffer[1][0], "  Press OK But. ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
		u8EmergencyActive = 0;
		u8EmergencyStop = 0;
		BZR_vDeactivateBuzzer();
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enTherapySelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vTherapySelectedScreen ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "->ElectroTherapy");
		sprintf ( &au8TransferBuffer[1][0], "  Pressure      ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
	}
	else
	{
		/*Nothing to do*/
	}	

	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enFreqSelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enDown))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPressureSelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vPressureSelectedScreen ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "  ElectroTherapy");
		sprintf ( &au8TransferBuffer[1][0], "->Pressure      ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enUp))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enTherapySelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPressureValueScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vFreqSelectedScreen ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "->Frequency     ");
		sprintf ( &au8TransferBuffer[1][0], "  Intensity     ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enFreqValueScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enReturn))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enTherapySelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enDown))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enIntsSelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}

}

void _vIntsSelectedScreen ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "  Frequency     ");
		sprintf ( &au8TransferBuffer[1][0], "->Intensity     ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enInstValueScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enReturn))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enTherapySelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enUp))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enFreqSelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}	
}

void _vFreqValueScreen ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "Adjust Frequency");
		sprintf ( &au8TransferBuffer[1][0], "      %d Hz       ", u8FreqValue);
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enReturn))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enFreqSelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enUp))
	{
		if(u8FreqValue < 100)
		{
			u8FreqValue += 5;
			_stHMISM.enCurrentState = HMI_enClearScreen;
			_stHMISM.enNextState = HMI_enFreqValueScreen;
			u8ScreenUpdated = 0;
		}
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enDown))
	{
		if(u8FreqValue > 0)
		{
			u8FreqValue -= 5;
			_stHMISM.enCurrentState = HMI_enClearScreen;
			_stHMISM.enNextState = HMI_enFreqValueScreen;
			u8ScreenUpdated = 0;
		}
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vIntsValueScreen ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "Adjust Intensity");
		sprintf ( &au8TransferBuffer[1][0], "      %d %        ", u8IntsValue);
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enReturn))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enIntsSelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enUp))
	{
		if(u8IntsValue < 100)
		{
			u8IntsValue++;
			_stHMISM.enCurrentState = HMI_enClearScreen;
			_stHMISM.enNextState = HMI_enInstValueScreen;
			u8ScreenUpdated = 0;
		}
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enDown))
	{
		if(u8IntsValue > 0)
		{
			u8IntsValue --;
			_stHMISM.enCurrentState = HMI_enClearScreen;
			_stHMISM.enNextState = HMI_enInstValueScreen;
			u8ScreenUpdated = 0;
		}
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vPressureValueScreen ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "    Pressure    ");
		sprintf ( &au8TransferBuffer[1][0], "     Value      ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
	}
	else
	{
		/*Nothing to do*/
	}

	if(DBNCR_u8ReadButtonState(DBNCR_enReturn))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPressureSelectedScreen;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vClearScreen ( void )
{
	if(LCD_u8IsBusy())
	{
		LCD_vClearScreen();
		_stHMISM.enCurrentState = _stHMISM.enNextState;
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vEmergencyState ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "Emergency State ");
		sprintf ( &au8TransferBuffer[1][0], "    Press Ok    ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
		_stHMISM.enCurrentState = HMI_enEmergencyState;
		BZR_vActivateBuzzer();
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState0;
		u8ScreenUpdated = 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
}

/*Right Password UP, DOWN, RETURN*/

void _vPswrdState0 ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "  Set Password  ");
		sprintf ( &au8TransferBuffer[1][0], "                ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
		_stHMISM.enCurrentState = HMI_enPswrdState0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState1;
		u8ScreenUpdated = 0;
		u8CorrectPassword = 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enUp))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState1;
		u8ScreenUpdated = 0;
		u8CorrectPassword = 1;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enDown))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState1;
		u8ScreenUpdated = 0;
		u8CorrectPassword = 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enReturn))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState1;
		u8ScreenUpdated = 0;
		u8CorrectPassword = 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
}

void _vPswrdState1 ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "  Set Password  ");
		sprintf ( &au8TransferBuffer[1][0], "       *        ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
		_stHMISM.enCurrentState = HMI_enPswrdState1;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState2;
		u8ScreenUpdated = 0;
		u8CorrectPassword &= 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enUp))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState2;
		u8ScreenUpdated = 0;
		u8CorrectPassword &= 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enDown))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState2;
		u8ScreenUpdated = 0;
		u8CorrectPassword &= 1;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enReturn))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState2;
		u8ScreenUpdated = 0;
		u8CorrectPassword &= 0;
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vPswrdState2 ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "  Set Password  ");
		sprintf ( &au8TransferBuffer[1][0], "       **       ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
		_stHMISM.enCurrentState = HMI_enPswrdState2;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState3;
		u8ScreenUpdated = 0;
		u8CorrectPassword &= 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enUp))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState3;
		u8ScreenUpdated = 0;
		u8CorrectPassword &= 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enDown))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState3;
		u8ScreenUpdated = 0;
		u8CorrectPassword &= 0;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enReturn))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState3;
		u8ScreenUpdated = 0;
		u8CorrectPassword &= 1;
	}
	else
	{
		/*Nothing to do*/
	}
}

void _vPswrdState3 ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "  Set Password  ");
		sprintf ( &au8TransferBuffer[1][0], "       ***      ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
		_stHMISM.enCurrentState = HMI_enPswrdState3;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(u8CorrectPassword == 1)
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enWelcomeScreen;
		u8ScreenUpdated = 0 ;
	}
	else
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState4;
		u8ScreenUpdated = 0;
	}
}

void _vPswrdState4 ( void )
{
	if(LCD_u8IsBusy() && u8ScreenUpdated == 0)
	{
		sprintf ( &au8TransferBuffer[0][0], "Wrong Password  ");
		sprintf ( &au8TransferBuffer[1][0], "    Press Ok    ");
		LCD_vUpdateScreen(&au8TransferBuffer[0][0]);
		u8ScreenUpdated = 1;
		_stHMISM.enCurrentState = HMI_enPswrdState4;
	}
	else
	{
		/*Nothing to do*/
	}
	
	if(DBNCR_u8ReadButtonState(DBNCR_enOk))
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enPswrdState0;
		u8ScreenUpdated = 0;
		u8CorrectPassword = 0;
	}
	else
	{
		/*Nothing to do*/
	}
}

void (* HMI_vpaStates[])(void) =
{
	(void (*)(void))_vWelcomeScreen,
	(void (*)(void))_vTherapySelectedScreen,
	(void (*)(void))_vPressureSelectedScreen,
	(void (*)(void))_vFreqSelectedScreen,
	(void (*)(void))_vIntsSelectedScreen,
	(void (*)(void))_vFreqValueScreen,
	(void (*)(void))_vIntsValueScreen,
	(void (*)(void))_vPressureValueScreen,
	(void (*)(void))_vClearScreen,
	(void (*)(void))_vEmergencyState,
	(void (*)(void))_vPswrdState0,
	(void (*)(void))_vPswrdState1,
	(void (*)(void))_vPswrdState2,
	(void (*)(void))_vPswrdState3,
	(void (*)(void))_vPswrdState4,
};


void HMI_vMain ( void )
{
	if(HMI_vGetEmergencyStop() && u8EmergencyActive == 0)
	{
		_stHMISM.enCurrentState = HMI_enClearScreen;
		_stHMISM.enNextState = HMI_enEmergencyState;
		u8ScreenUpdated = 0;
		u8FreqValue = 0;
		u8IntsValue = 0;
		u8EmergencyActive = 1;
	}
	else
	{
		/*Nothing to do*/
	}

	HMI_vpaStates[_stHMISM.enCurrentState]();
}

void HMI_vSetEmergencyStop ( void )
{
	u8EmergencyStop = 1;
}

uint8 HMI_vGetEmergencyStop ( void )
{
	return u8EmergencyStop;
}

uint8 HMI_u8GetFreqValue ( void )
{
	return u8FreqValue;
}

uint8 HMI_u8GetIntsValue( void )
{
	return u8IntsValue;
}
