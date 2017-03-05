/*	
 * 	Name: PMG
 * 	Mar 1, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: Debouncer.h
 */

#ifndef DEBOUNCER_H_
#define DEBOUNCER_H_

#include "Typedef.h"
#include "MKL25Z4.h"

typedef enum
{
	DBNCR_enUp = 0,
	DBNCR_enDown,
	DBNCR_enOk,
	DBNCR_enReturn
}DBNCR_tenButtons;

#define BTN_USE_LOOP

#define BTN_UP				( 8  )
#define	BTN_DOWN			( 9  )
#define BTN_RETURN			( 11 )
#define BTN_OK				( 10 )

#define TOTAL_BTNS	( 4 )

#define	BTN_CHANGE_CNT	( 3 )

#define BTN_PORT	( GPIOB_PDIR )	

extern void DBNCR_vMonitor	(void);
extern uint8 DBNCR_u8ReadButtonState( DBNCR_tenButtons enButton );

#endif /* DEBOUNCER_H_ */
