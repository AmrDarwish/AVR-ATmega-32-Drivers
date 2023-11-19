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

#include "MUART_interface.h"

int main (){
	Port_voidInit();
	MUART_voidInit();
	s8* data = "amr";

	while(1){
		MUART_voidTransmitString(data);
		_delay_ms(1500);
	}
}
