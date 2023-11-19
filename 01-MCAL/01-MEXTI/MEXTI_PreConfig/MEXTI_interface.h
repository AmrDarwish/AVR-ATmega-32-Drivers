/*
 * MEXTI_interface.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Amr-a
 */

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_
void ISR_EXTI0(void);
void ISR_EXTI1(void);
void ISR_EXTI2(void);

void MEXTI0_CallBack(void (*pf) (void));
void MEXTI1_CallBack(void (*pt) (void));
void MEXTI2_CallBack(void (*pr) (void));

void MEXTI0_voidInit();
void MEXTI1_voidInit();
void MEXTI2_voidInit();


#endif /* MEXTI_INTERFACE_H_ */
