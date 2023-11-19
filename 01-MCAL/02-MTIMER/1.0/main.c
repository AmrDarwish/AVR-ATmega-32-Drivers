/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "MTIMER_interface.h"
#include "MGIE_interface.h"
#include "MDIO_interface.h"


int main (){
	Port_voidInit();
	MTIMER0_voidInit();
	MGIE_voidEnable();
	MTIMER0_voidSetPreload(192);
	while (1){
		_delay_ms(1000);
		MDIO_ErrorS_TogPinValue(DIO_PORTA,DIO_PIN0);
	}
}

/*
 * ISR FOR TIMER0 OVERFLOW
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 counter = 0;
	counter++;
	if (counter == 4000)
	{
		MDIO_ErrorS_TogPinValue(DIO_PORTA,DIO_PIN7);
	//	MTIMER0_voidSetPreload(192);
		counter = 0;
		MTIMER0_voidSetPreload(192);
	}
}
*/


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 counter = 0;
	counter++;
	if (counter == 4000)
	{
		MDIO_ErrorS_TogPinValue(DIO_PORTA,DIO_PIN7);
	//	MTIMER0_voidSetPreload(192);
		counter = 0;
	}
}
