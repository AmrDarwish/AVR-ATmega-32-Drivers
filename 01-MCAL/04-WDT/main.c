/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"
#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MWDT_interface.h"


int main (){
	Port_voidInit();
	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
		_delay_ms(1000);
	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
	MWDT_voidStart(WDT_1S);
	MWDT_voidStop();
	while(1){


	}
}
