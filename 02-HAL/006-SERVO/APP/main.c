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
#include "MADC_interface.h"
#include "MTIMER_interface.h"
#include "HLCD_interface.h"
#include "HServo_interface.h"
s32 Mapping(s32 X_MAX,s32 X_MIN,s32 Y_MAX,s32 Y_MIN,s32 Y);

int main (){

	u16 ADC_u16Reading;
	s32 ADC_s32Mapped_Lux;
	s32 ADC_s32Mapped_Servo;
	HLCD_voidInit();
	Port_voidInit();
	HLCD_voidInit();

	MADC_ErrorStateInit(ADC_VREF_VCC,ADC_PRESCALER_DIV32,ADC_RIGHT_ADJUSTMENT);

	MTIMER1_voidInit(FAST_PWM_NON_INVERTING, TOP_FPWM_ICR1,DIV_8);
	MTIMER1_voidSetTopValue(20000,TOP_FPWM_ICR1);


	while(1){
		ADC_u16Reading    	= MADC_u16GetValue(ADC_ChANNEL3);
		ADC_s32Mapped_Lux 	= Mapping(10000,1,1023,0,ADC_u16Reading);
		ADC_s32Mapped_Servo = Mapping(90,-90,1023,0,ADC_u16Reading);
		HServo_voidSetAngleSimulation(ADC_s32Mapped_Servo);
		HLCD_voidSendString("    LUX:");
		HLCD_voidSendInt(10000-	ADC_s32Mapped_Lux);
		HLCD_voidSendString(" ");
		HLCD_voidSetCursorPosition(2,0);
		HLCD_voidSendString("Servo Angel:");
		HLCD_voidSendInt(ADC_s32Mapped_Servo);
		HLCD_voidSendString("  ");
		HLCD_voidReturnHome();
	}
}
s32 Mapping(s32 X_MAX,s32 X_MIN,s32 Y_MAX,s32 Y_MIN,s32 Y)
{
	f64 X;
	X = ( (f64) (  (f64) (X_MAX - X_MIN) * ((Y-Y_MIN) )/ (f64)(Y_MAX-Y_MIN)) + X_MIN) + 1;
	return X ;
}
