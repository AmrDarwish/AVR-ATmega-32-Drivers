/*
 * HBUTTON_interface.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Amr-a
 */

#ifndef HBUTTON_INTERFACE_H_
#define HBUTTON_INTERFACE_H_

/*copy_u8ButtonNum:
			 * HBUTTON_PORTA_P0
			 * ...
			 * HBUTTON_PORTB_P0
			 * ...
			 * HBUTTON_PORTC_P0
			 * ...
			 * HBUTTON_PORTD_P0
			 * ...
			 *
 * */

Error_State_t HButton_ErrorState_GetButtonCase(u8 copy_u8ButtonNum, u8* Copy_ptResult);

#define BUTTON_IS_PRESSED		1
#define BUTTON_IS_NOT_PRESSED	0


#define HBUTTON_PORTA_P0	1
#define HBUTTON_PORTA_P1	2
#define HBUTTON_PORTA_P2	3
#define HBUTTON_PORTA_P3	4
#define HBUTTON_PORTA_P4	5
#define HBUTTON_PORTA_P5	6
#define HBUTTON_PORTA_P6	7
#define HBUTTON_PORTA_P7	8

#define HBUTTON_PORTB_P0	9
#define HBUTTON_PORTB_P1	10
#define HBUTTON_PORTB_P2	11
#define HBUTTON_PORTB_P3	12
#define HBUTTON_PORTB_P4	13
#define HBUTTON_PORTB_P5	14
#define HBUTTON_PORTB_P6	15
#define HBUTTON_PORTB_P7	16

#define HBUTTON_PORTC_P0	17
#define HBUTTON_PORTC_P1	18
#define HBUTTON_PORTC_P2	19
#define HBUTTON_PORTC_P3	20
#define HBUTTON_PORTC_P4	21
#define HBUTTON_PORTC_P5	22
#define HBUTTON_PORTC_P6	23
#define HBUTTON_PORTC_P7	24

#define HBUTTON_PORTD_P0	25
#define HBUTTON_PORTD_P1	26
#define HBUTTON_PORTD_P2	27
#define HBUTTON_PORTD_P3	28
#define HBUTTON_PORTD_P4	29
#define HBUTTON_PORTD_P5	30
#define HBUTTON_PORTD_P6	31
#define HBUTTON_PORTD_P7	32


#endif /* HBUTTON_INTERFACE_H_ */
