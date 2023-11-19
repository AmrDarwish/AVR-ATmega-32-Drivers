/*
 * MEXTI_program.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"
#include "MEXTI_register.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"




void MEXTI0_voidInit(){
	/*check Interrupt sense */
	#if INT0_SENSE_MODE == RISING
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	#elif INT0_SENSE_MODE == FALLING
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	#elif INT0_SENSE_MODE == LOGIC_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	#elif INT0_SENSE_MODE == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	#else
	#error "INT0 sense control invalid mode"

	#endif
	SET_BIT(GICR,GICR_INT0);

}

void (*sendISR0)(void);

void MEXTI0_CallBack(void (*pf) (void)){
	 sendISR0 = pf;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void) {
	sendISR0();
}


void MEXTI1_voidInit(){
#if INT1_SENSE_MODE == RISING
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT1_SENSE_MODE == FALLING
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT1_SENSE_MODE == LOGIC_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT1_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#else
#error "INT1 has invalid sense mode"
#endif
SET_BIT(GICR,GICR_INT1);

}

void (*send_ISR1)(void);
void MEXTI1_CallBack(void (*pt) (void)){
	send_ISR1 = pt;
}
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	send_ISR1();
}



void MEXTI2_voidInit(){
#if INT2_SENSE_MODE == RISING
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#elif INT2_SENSE_MODE == FALLING
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "INT2 has invalid sense mode"
#endif
	SET_BIT(GICR,GICR_INT2);
}
void (*send_ISR2)(void);
void MEXTI2_CallBack(void (*pr) (void)){
	send_ISR2 = pr;
}
void __vector_3 (void) __attribute((signal));
void __vector_3(void){

	send_ISR2();
}
