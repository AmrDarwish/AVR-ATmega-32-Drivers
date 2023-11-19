/***************************************************/
/********************	Auther	: Amr 		********/

/********************	Layer 	:  HLCD		********/
/********************	Module	:  LCD		********/
/********************	Version : 11.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/***************************************************/


#ifndef _HLCD_CONFIG_H
#define _HLCD_CONFIG_H

#define LCD_MODE			HLCD_MODE_4

#define LCD_PORT_DATA 		DIO_PORTD
#define LCD_D0		 		DIO_PIN0
#define LCD_D1		 		DIO_PIN1
#define LCD_D2		 		DIO_PIN2
#define LCD_D3		 		DIO_PIN3

#define LCD_PORT_CTRL 		DIO_PORTC
#define LCD_RS 				0
#define LCD_RW 				1
#define LCD_EN	 			2


#endif
