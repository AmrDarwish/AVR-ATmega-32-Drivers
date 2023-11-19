#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HLCD_interface.h"
#include "MDIO_interface.h"
#include "HKeyPad_interface.h"
#include "util/delay.h"

int main (){
	Port_voidInit();
	HLCD_voidInit();

	while(1){

		u8 result =  HKeyPad_u8GetKey();
		if(result != NO_KEY){
			HLCD_voidSendData(result);
			result = NO_KEY;
		}

	}

}


