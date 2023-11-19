/*
 * main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"
#include "MGIE_interface.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"


int main(void){
	Port_voidInit();
	MEXTI0_voidInit();
	MEXTI1_voidInit();
	MEXTI2_voidInit();

	MGIE_voidEnable();
	MEXTI0_CallBack(ISR_EXTI0);
	MEXTI1_CallBack(ISR_EXTI1);
	MEXTI2_CallBack(ISR_EXTI2);
	while(1){
		MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN5,DIO_HIGH);
		_delay_ms(2000);
		MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW);
		_delay_ms(2000);
	}
}

void ISR_EXTI0(void){

}
void ISR_EXTI1(void){

}
void ISR_EXTI2(void){

}
