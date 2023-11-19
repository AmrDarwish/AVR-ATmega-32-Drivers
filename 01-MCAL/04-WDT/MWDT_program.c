/*
 * MWDT_program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MWDT_interface.h"
#include "MWDT_registers.h"
#include "MWDT_config.h"
#include "MWDT_private.h"

void MWDT_voidStart(Time_t copy_enuTime){
	WDTCR = 0b00000000;
	SET_BIT(WDTCR,WDTCR_WDE);
	WDTCR |= copy_enuTime;
}
void MWDT_voidStop(){
	WDTCR =0B00011000;
	CLR_BIT(WDTCR,WDTCR_WDE);

}

