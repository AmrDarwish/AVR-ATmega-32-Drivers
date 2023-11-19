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
#include "MTWI_interface.h"
#include "HEEPROM_interface.h"

int main (){
	Port_voidInit();
	MTWI_voidInit();

	u8 data = 0;

//	EEPROM_voidWrite('B',0x02);
	EEPROM_voidWrite('B',0x50,0x01);
	_delay_ms(15);
//	EEPROM_voidRead(0x02,&data);
	EEPROM_voidRead(0x50,0x01,&data);
	MDIO_ErrorS_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	while(1){
		if (data == 'A')
			MDIO_ErrorS_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	}
}
