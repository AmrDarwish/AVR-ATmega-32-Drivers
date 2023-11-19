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
#include "HLCD_interface.h"
#include "MGIE_interface.h"
#include "MTIMER_interface.h"
u16 preloadTime;
u16 onTime;

u16 read1 ;
u16 read2 ;
u16 read3 ;
void ISR_ICU();


int main (){
	Port_voidInit();
	HLCD_voidInit();
	MTIMER1_voidInit(NORMAL_MODE,TOP_NORMAL_0XFF,DIV_8);
	MTIMER1_voidEdgeSelect(RISING_EDGE);
	MTIMER1_voidEnableICUInterrupt();
	MTIMER1_voidSendISR(ISR_ICU);
	MTIMER0_voidInit();
	MGIE_voidEnable();
	while(1){
		MTIMER0_voidSetDutyCycle(100);
		HLCD_voidSetCursorPosition(0,0);
		HLCD_voidSendString(" Period is : ");
		HLCD_voidSendInt(preloadTime);

		HLCD_voidSetCursorPosition(2,1);
		HLCD_voidSendString(" On time : ");
		HLCD_voidSendInt(onTime);
		_delay_ms(1000);

	}
}
void ISR_ICU(){

	static u8 counter = 0;
	counter ++;
	if (counter == 1){
			read1 = MTIMER1_u16GetICUValue();
		}
	else if (counter == 2){
		read2 = MTIMER1_u16GetICUValue();
		preloadTime = read2 - read1;
		MTIMER1_voidEdgeSelect(FALLING_EDGE);
	}
	else if (counter == 3){
		read3 = MTIMER1_u16GetICUValue();
		onTime = read3 - read2;
		counter = 0;
		//MTIMER1_voidDisableICUInterrupt();
		MTIMER1_voidEdgeSelect(RISING_EDGE);

	}

}
