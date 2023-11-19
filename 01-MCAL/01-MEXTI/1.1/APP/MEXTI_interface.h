/*
 * MEXTI_interface.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Amr-a
 */

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

#define EXINT_RISING 		1
#define EXINT_FALLING   	2
#define EXINT_LOW_LEVEL 	4
#define EXINT_LOGIC_CHANGE	3

void MEXTI0_CallBack(void (*pf) (void));
void MEXTI1_CallBack(void (*pt) (void));
void MEXTI2_CallBack(void (*pr) (void));

void MEXTI0_voidInit();
void MEXTI1_voidInit();
void MEXTI2_voidInit();

Error_State_t MEXTI0_voidCangeSense(u8 sense);
Error_State_t MEXTI1_voidCangeSense(u8 sense);
Error_State_t MEXTI2_voidCangeSense(u8 sense);


#endif /* MEXTI_INTERFACE_H_ */
