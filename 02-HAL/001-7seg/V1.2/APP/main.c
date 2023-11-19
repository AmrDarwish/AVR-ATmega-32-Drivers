/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Amr-a
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MDIO_interface.h"
#include "H7SEG_interface.h"
#include "util/delay.h"
int main (){
	Port_voidInit();
	while(1){
		MDIO_ErrorS_TogPinValue(DIO_PORTA,DIO_PIN7);
		H7SEG_voidWrite(7,DIO_PORTA);
		_delay_ms(10);
		MDIO_ErrorS_TogPinValue(DIO_PORTA,DIO_PIN7);
		H7SEG_voidWrite(6,DIO_PORTA);
		_delay_ms(10);
	}
}
