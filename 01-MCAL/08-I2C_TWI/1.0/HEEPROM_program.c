/*
 * HEEPROM_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTWI_interface.h"
#include "HEEPROM_interface.h"

void EEPROM_voidWrite(u8 Copy_u8Data, u8 Copy_u8Address){
	/*start condition*/
	MTWI_voidStart();

	/* sending address 0b1010 0000 with write*/
	MTWI_voidWrite(0xA0);

	/* sending address mlocation inside eeprom*/
	MTWI_voidWrite(Copy_u8Address);

	/* sending data inside eeprom*/
		MTWI_voidWrite(Copy_u8Data);

	/* stop condition */
	MTWI_voidStop();
}

void EEPROM_voidRead(u8 Copy_u8Address, u8* Copy_pt8Data){
		/*start condition*/
		MTWI_voidStart();

		/* sending address 0b1010 0000 with write */
		MTWI_voidWrite(0xA0);

		/* sending address mlocation inside eeprom*/
		MTWI_voidWrite(Copy_u8Address);

		/* Send repeated start */
		MTWI_voidStart();

		/*repeated start condition with read*/
		MTWI_voidWrite(0xA1);

		/* NOW I'm reading one btpe from eeprom*/
		*Copy_pt8Data =  MTWI_u8ReadWithACK();

		/* stop condition */
		MTWI_voidStop();
}
