/*
 * MWDT_interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Amr-a
 */

#ifndef MWDT_INTERFACE_H_
#define MWDT_INTERFACE_H_

typedef enum {
	WDT_2_1S = 7,
	WDT_1S = 6
}Time_t;


void MWDT_voidStart(Time_t copy_enuTime);
void MWDT_voidStop();

#endif /* MWDT_INTERFACE_H_ */
