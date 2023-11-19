/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	:  H7SEG	********/
/********************	Module	:  7sement	********/
/********************	Version : 1.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/***************************************************/
#include "STD_TYPES.h"
#include "util/delay.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "H7SEG_interface.h"
#include "H7SEG_private.h"
#include "H7SEG_config.h"

void void_SegWrite(u8 num){
	MDIO_ErrorS_SetPortValue(SEG7_PORT,num);
}
void void_SegClear(u8 num){
	MDIO_ErrorS_SetPortValue(SEG7_PORT,0);
}

