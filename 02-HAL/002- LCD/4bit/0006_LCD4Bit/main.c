/*
 * main.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "util/delay.h"



int main (){

	Port_voidInit();
	HLCD_voidInit();
	HLCD_voidSendInt(123);
while(1){


}
}
