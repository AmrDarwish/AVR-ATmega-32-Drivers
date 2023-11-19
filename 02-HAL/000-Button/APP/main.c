/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "HLED_interface.h"
#include "MDIO_interface.h"
#include "HBUTTON_interface.h"
void button_led(u8 button_case,u8 HLED_PORT_P );
int main (){
	Port_voidInit();
	u8 button1_case = BUTTON_IS_NOT_PRESSED;
	u8 button2_case = BUTTON_IS_NOT_PRESSED;
	u8 button3_case = BUTTON_IS_NOT_PRESSED;
	u8 button4_case = BUTTON_IS_NOT_PRESSED;
	u8 button5_case = BUTTON_IS_NOT_PRESSED;
	u8 button6_case = BUTTON_IS_NOT_PRESSED;
	u8 button7_case = BUTTON_IS_NOT_PRESSED;
	u8 button8_case = BUTTON_IS_NOT_PRESSED;
	u8 button9_case = BUTTON_IS_NOT_PRESSED;
	u8 button10_case = BUTTON_IS_NOT_PRESSED;
	u8 button11_case = BUTTON_IS_NOT_PRESSED;
	u8 button12_case = BUTTON_IS_NOT_PRESSED;
	u8 button13_case = BUTTON_IS_NOT_PRESSED;
	u8 button14_case = BUTTON_IS_NOT_PRESSED;
	u8 button15_case = BUTTON_IS_NOT_PRESSED;
	u8 button16_case = BUTTON_IS_NOT_PRESSED;

	while (1){
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTB_P0,&button1_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTB_P1,&button2_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTB_P2,&button3_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTB_P3,&button4_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTB_P4,&button5_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTB_P5,&button6_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTB_P6,&button7_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTB_P7,&button8_case);

		button_led(button1_case,HLED_PORTA_P0);
		button_led(button2_case,HLED_PORTA_P1);
		button_led(button3_case,HLED_PORTA_P2);
		button_led(button4_case,HLED_PORTA_P3);
		button_led(button5_case,HLED_PORTA_P4);
		button_led(button6_case,HLED_PORTA_P5);
		button_led(button7_case,HLED_PORTA_P6);
		button_led(button8_case,HLED_PORTA_P7);


		HButton_ErrorState_GetButtonCase(HBUTTON_PORTD_P0,&button9_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTD_P1,&button10_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTD_P2,&button11_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTD_P3,&button12_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTD_P4,&button13_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTD_P5,&button14_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTD_P6,&button15_case);
		HButton_ErrorState_GetButtonCase(HBUTTON_PORTD_P7,&button16_case);

		button_led(button9_case,HLED_PORTC_P0);
		//HLED_ErrorState_LEDOn(HLED_PORTC_P0);
		button_led(button10_case,HLED_PORTC_P1);
		button_led(button11_case,HLED_PORTC_P2);
		button_led(button12_case,HLED_PORTC_P3);
		button_led(button13_case,HLED_PORTC_P4);
		button_led(button14_case,HLED_PORTC_P5);
		button_led(button15_case,HLED_PORTC_P6);
		button_led(button16_case,HLED_PORTC_P7);




	}
}
void button_led(u8 button_case,u8 HLED_PORT_P ){
	if (button_case == BUTTON_IS_PRESSED){
		HLED_ErrorState_LEDOn(HLED_PORT_P);
	}
	else if (button_case == BUTTON_IS_NOT_PRESSED){
		HLED_ErrorState_LEDOff(HLED_PORT_P);
	}

}

