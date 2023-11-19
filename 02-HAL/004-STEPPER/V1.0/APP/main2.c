#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "HStpper_interface.h"

int main (){
	Port_voidInit();
	//INPUTS ANGLE
	Hstepper_rotate(45);

	while(1){
		Hstepper_rotate(45);

	}


}
