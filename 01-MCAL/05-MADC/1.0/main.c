/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Amr-a
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "HLCD_interface.h"
#include "util/delay.h"

u16 Mapping(u32 X_MAX,u32 X_MIN,u32 Y_MAX,u32 Y_MIN,u32 Y);
int main (){
	Port_voidInit();
	HLCD_voidInit();
	MADC_ErrorStateInit(ADC_VREF_VCC,ADC_PRESCALER_DIV32,ADC_RIGHT_ADJUSTMENT);
	//MADC_voidInitDefault();
	u16 ADC_u16Reading;
	u16 ADC_u16Mapped;
	while (1){
		ADC_u16Reading  = MADC_u16GetValue(ADC_ChANNEL1);
		ADC_u16Mapped	= Mapping(10000,1,1023,0,ADC_u16Reading);
		HLCD_voidReturnHome();
		HLCD_voidSendInt(ADC_u16Reading);
		HLCD_voidSetCursorPosition(2,0);
		HLCD_voidSendInt(ADC_u16Mapped);
		HLCD_voidSendString("  ");

	}
}

u16 Mapping(u32 X_MAX,u32 X_MIN,u32 Y_MAX,u32 Y_MIN,u32 Y)
{
	f64 X;
	X = ( (f64) (  (f64) (X_MAX - X_MIN) * ((Y-Y_MIN) )/ (f64)(Y_MAX-Y_MIN)) + X_MIN) + 1;
	return X ;
}
