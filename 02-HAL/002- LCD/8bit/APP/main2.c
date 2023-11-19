#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "util/delay.h"

int main (){
	Port_voidInit();
	HLCD_voidInit();

	HLCD_voidSendData('y');
	HLCD_voidSendData('A');
	HLCD_voidSendData('A');
	HLCD_voidSendData('A');
	HLCD_voidSendData('M');
	HLCD_voidSendData('R');
	while(1){


	}


}
