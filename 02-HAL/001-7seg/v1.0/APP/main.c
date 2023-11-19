#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "H7SEG_interface.h"
#include "util/delay.h"

int main (){
	Port_voidInit();
	int values[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	int i = 0;
	while(1){

		void_SegWrite(values[i]);
		i++;
		i %= 10 ;
		_delay_ms(500);


	}
}
