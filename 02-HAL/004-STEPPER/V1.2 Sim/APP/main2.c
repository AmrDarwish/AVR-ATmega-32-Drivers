#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "MDIO_interface.h"
#include "HStpper_interface.h"

int main (){
	Port_voidInit();
	//INPUTS ANGLE
	Hstepper_rotate_CW(370);
	Hstepper_Stop();
	//Hstepper_rotate_ACW(20);
	Hstepper_Stop();

	while(1){
		//Hstepper_rotate_ACW(45);

		//Hstepper_rotate_ACW2 (90);
	}


}
