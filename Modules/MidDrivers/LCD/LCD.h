/*	
 * 	Name: PMG
 * 	Mar 4, 2017
 * 	e-mail: paul-mg@hotmail.com
 * 	phone: 3318920660
 * 	Header File
 * 	filename: LCD.h
 */

#ifndef LCD_H_
#define LCD_H_

#include "Typedef.h"
#include "derivative.h"

#define LCD_SIZE_Y				2
#define LCD_SIZE_X				16

#define LCD_nENABLE_ON			(GPIOC_PDOR |=  (1 << 0))
#define LCD_nENABLE_OFF			(GPIOC_PDOR &= ~(1 << 0))

#define LCD_nRS_ON				(GPIOC_PDOR |=  (1 << 7))
#define LCD_nRS_OFF				(GPIOC_PDOR &= ~(1 << 7))

#define LCD_nSET_D0				(GPIOA_PDOR |=  (1 << 1))
#define LCD_nCLEAR_D0			(GPIOA_PDOR &= ~(1 << 1))

#define LCD_nSET_D1				(GPIOA_PDOR |=  (1 << 2))
#define LCD_nCLEAR_D1			(GPIOA_PDOR &= ~(1 << 2))

#define LCD_nSET_D2				(GPIOD_PDOR |=  (1 << 4))
#define LCD_nCLEAR_D2			(GPIOD_PDOR &= ~(1 << 4))

#define LCD_nSET_D3				(GPIOA_PDOR |=  (1 << 12))
#define LCD_nCLEAR_D3			(GPIOA_PDOR &= ~(1 << 12))

#define LCD_nSET_D4				(GPIOC_PDOR |=  (1 << 3))
#define LCD_nCLEAR_D4			(GPIOC_PDOR &= ~(1 << 3))

#define LCD_nSET_D5				(GPIOA_PDOR |=  (1 << 5))
#define LCD_nCLEAR_D5			(GPIOA_PDOR &= ~(1 << 5))

#define LCD_nSET_D6				(GPIOC_PDOR |=  (1 << 8))
#define LCD_nCLEAR_D6			(GPIOC_PDOR &= ~(1 << 8))

#define LCD_nSET_D7				(GPIOC_PDOR |=  (1 << 9))
#define LCD_nCLEAR_D7			(GPIOC_PDOR &= ~(1 << 9))

typedef enum
{
	LCD_enIdle = 0,
	LCD_enSelectTypeOfData,
	LCD_enWriteData,
	LCD_enEnable,
	LCD_enDisable
}LCD_tenStates;

typedef enum
{
	LCD_enCMD = 0,
	LCD_enData
}LCD_tenCMDorData;

extern void LCD_vInit ( void );
extern void LCD_vDriver ( void );

#endif /* LCD_H_ */
