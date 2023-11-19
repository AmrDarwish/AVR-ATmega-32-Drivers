/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "HLCD_interface.h"
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "HLM53_interface.h"

int main (){
	Port_voidInit();
	HLCD_voidInit();
	MADC_voidInitDefault();
	//MADC_ErrorStateInit(ADC_VREF_VCC,ADC_PRESCALER_DIV32,ADC_RIGHT_ADJUSTMENT);
	s16 temprature;
	while (1){
		temprature  = HLM35_s16GetRead();
		HLCD_voidReturnHome();
		HLCD_voidSendInt(temprature);
		HLCD_voidSendString("  ");
	}
}
