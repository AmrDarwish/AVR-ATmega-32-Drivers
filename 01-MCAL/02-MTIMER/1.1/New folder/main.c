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
#include "MTIMER_interface.h"

int main (){
	Port_voidInit();
	MTIMER1_voidInit(FAST_PWM_NON_INVERTING, TOP_FPWM_ICR1,DIV_8);
	MTIMER1_voidSetTopValue(20000,TOP_FPWM_ICR1);
	//u16 duty;
	while(1){

				MTIMER1_voidSetDutyCycle(2530);

	}
}
