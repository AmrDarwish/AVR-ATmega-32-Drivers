#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HLCD_interface.h"
#include "MDIO_interface.h"
#include "HKeyPad_interface.h"
#include "util/delay.h"
u32 operate (u32 op1 , u32 op2 , u8 operation);
int main (){
	Port_voidInit();
	HLCD_voidInit();
	u8 flag = 1;
	u32 op1 = 0;
	u32 op2 = 0;
	u8 operation =0;
	while(1){
		u8 result =  HKeyPad_u8GetKey();

		if(result != NO_KEY){
			if (((flag == 1)||(flag == 2)) && (result != '+' && result != '-' && result != '/' && result != '*' && result != '=' && result != '#')){
							op1*=10;
							op1 += result-48;
							HLCD_voidSendData(result);
							flag = 2;
						}

			else if (flag == 2 && (result == '+' || result == '-' || result == '/' || result == '*')  ){
				operation = result;
				flag = 3;
				HLCD_voidSendData(result);
		}
			else if (flag == 3 && (result != '+' && result != '-' && result != '/' && result != '*' && result != '=' && result != '#')){
				op2 *= 10;
				op2 += result-48;
				HLCD_voidSendData(result);
				//HLCD_voidClearDisplay();

				//result = operate(op1,op2,operation);

				//HLCD_voidSendInt(result);
			}
			else if (flag == 3 && result == '=' ){
				HLCD_voidSendData(result);
				result = operate(op1,op2,operation);
				HLCD_voidSendInt(result);

				_delay_ms(500);
				HLCD_voidClearDisplay();
				op1 = 0;
				op2 = 0;
				flag = 1;
				result = 0;
				operation = 0;
			}
			else if(result == '#') {
				HLCD_voidClearDisplay();
				op1 = 0;
				op2 = 0;
				flag = 1;
				result = 0;
				operation = 0;
			}
			else{

			}


		}
		result = NO_KEY;

	}

}

u32 operate (u32 op1 , u32 op2 , u8 operation){
	int result;
	u32 op11 = (u32) op1;
	u32 op22 = (u32) op2;

	switch (operation) {
	case '+' : result = op11+op22; break;
	case '-' : result = op11-op22; break;
	case '*' : result = op11*op22; break;
	case '/' : result = op11/op22; break;
	default	 : break;

	}
	return result;
}
