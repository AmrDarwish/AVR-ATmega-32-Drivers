/*
 * MWDT_registers.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Amr-a
 */

#ifndef MWDT_REGISTERS_H_
#define MWDT_REGISTERS_H_
#define WDTCR				*((volatile u8*)0x41)
#define WDTCR_WDTOE 		4
#define WDTCR_WDE 			3
#define WDTCR_WDP2 			2
#define WDTCR_WDP1 			1
#define WDTCR_WDP0 			0


#endif /* MWDT_REGISTERS_H_ */
