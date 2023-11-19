/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDIO_interface.h"
#include "MSPI_interface.h"


int main (){
	Port_voidInit();
	MSPI_voidInit();

	while (1){

		if (MSPI_u8TransciveByte('3') == '5'){
			MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
		}
	}

}

