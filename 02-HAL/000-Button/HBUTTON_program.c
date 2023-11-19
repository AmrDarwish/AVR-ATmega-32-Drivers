/*
 * HBUTTON_program.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDIO_interface.h"
#include "HBUTTON_interface.h"
#include "HBUTTON_private.h"
#include "HBUTTON_config.h"

Error_State_t HButton_ErrorState_GetButtonCase(u8 copy_u8ButtonNum, u8* Copy_ptResult){
	Error_State_t errorState = return_Ok;
	switch(copy_u8ButtonNum){
	case HBUTTON_PORTA_P0 : *Copy_ptResult = get_button(DIO_PORTA,DIO_PIN0,BUTTON_PORTA_P0_PULL) ;	break;
	case HBUTTON_PORTA_P1 : *Copy_ptResult = get_button(DIO_PORTA,DIO_PIN1,BUTTON_PORTA_P1_PULL) ;	break;
	case HBUTTON_PORTA_P2 : *Copy_ptResult = get_button(DIO_PORTA,DIO_PIN2,BUTTON_PORTA_P2_PULL) ;	break;
	case HBUTTON_PORTA_P3 : *Copy_ptResult = get_button(DIO_PORTA,DIO_PIN3,BUTTON_PORTA_P3_PULL) ;	break;
	case HBUTTON_PORTA_P4 : *Copy_ptResult = get_button(DIO_PORTA,DIO_PIN4,BUTTON_PORTA_P4_PULL) ;	break;
	case HBUTTON_PORTA_P5 : *Copy_ptResult = get_button(DIO_PORTA,DIO_PIN5,BUTTON_PORTA_P5_PULL) ;	break;
	case HBUTTON_PORTA_P6 : *Copy_ptResult = get_button(DIO_PORTA,DIO_PIN6,BUTTON_PORTA_P6_PULL) ;	break;
	case HBUTTON_PORTA_P7 : *Copy_ptResult = get_button(DIO_PORTA,DIO_PIN7,BUTTON_PORTA_P7_PULL) ;	break;

	case HBUTTON_PORTB_P0 : *Copy_ptResult = get_button(DIO_PORTB,DIO_PIN0,BUTTON_PORTB_P0_PULL) ;	break;
	case HBUTTON_PORTB_P1 : *Copy_ptResult = get_button(DIO_PORTB,DIO_PIN1,BUTTON_PORTB_P1_PULL) ;	break;
	case HBUTTON_PORTB_P2 : *Copy_ptResult = get_button(DIO_PORTB,DIO_PIN2,BUTTON_PORTB_P2_PULL) ;	break;
	case HBUTTON_PORTB_P3 : *Copy_ptResult = get_button(DIO_PORTB,DIO_PIN3,BUTTON_PORTB_P3_PULL) ;	break;
	case HBUTTON_PORTB_P4 : *Copy_ptResult = get_button(DIO_PORTB,DIO_PIN4,BUTTON_PORTB_P4_PULL) ;	break;
	case HBUTTON_PORTB_P5 : *Copy_ptResult = get_button(DIO_PORTB,DIO_PIN5,BUTTON_PORTB_P5_PULL) ;	break;
	case HBUTTON_PORTB_P6 : *Copy_ptResult = get_button(DIO_PORTB,DIO_PIN6,BUTTON_PORTB_P6_PULL) ;	break;
	case HBUTTON_PORTB_P7 : *Copy_ptResult = get_button(DIO_PORTB,DIO_PIN7,BUTTON_PORTB_P7_PULL) ;	break;

	case HBUTTON_PORTC_P0 : *Copy_ptResult = get_button(DIO_PORTC,DIO_PIN0,BUTTON_PORTC_P0_PULL) ;	break;
	case HBUTTON_PORTC_P1 : *Copy_ptResult = get_button(DIO_PORTC,DIO_PIN1,BUTTON_PORTC_P1_PULL) ;	break;
	case HBUTTON_PORTC_P2 : *Copy_ptResult = get_button(DIO_PORTC,DIO_PIN2,BUTTON_PORTC_P2_PULL) ;	break;
	case HBUTTON_PORTC_P3 : *Copy_ptResult = get_button(DIO_PORTC,DIO_PIN3,BUTTON_PORTC_P3_PULL) ;	break;
	case HBUTTON_PORTC_P4 : *Copy_ptResult = get_button(DIO_PORTC,DIO_PIN4,BUTTON_PORTC_P4_PULL) ;	break;
	case HBUTTON_PORTC_P5 : *Copy_ptResult = get_button(DIO_PORTC,DIO_PIN5,BUTTON_PORTC_P5_PULL) ;	break;
	case HBUTTON_PORTC_P6 : *Copy_ptResult = get_button(DIO_PORTC,DIO_PIN6,BUTTON_PORTC_P6_PULL) ;	break;
	case HBUTTON_PORTC_P7 : *Copy_ptResult = get_button(DIO_PORTC,DIO_PIN7,BUTTON_PORTC_P7_PULL) ;	break;

	case HBUTTON_PORTD_P0 : *Copy_ptResult = get_button(DIO_PORTD,DIO_PIN0,BUTTON_PORTD_P0_PULL) ;	break;
	case HBUTTON_PORTD_P1 : *Copy_ptResult = get_button(DIO_PORTD,DIO_PIN1,BUTTON_PORTD_P1_PULL) ;	break;
	case HBUTTON_PORTD_P2 : *Copy_ptResult = get_button(DIO_PORTD,DIO_PIN2,BUTTON_PORTD_P2_PULL) ;	break;
	case HBUTTON_PORTD_P3 : *Copy_ptResult = get_button(DIO_PORTD,DIO_PIN3,BUTTON_PORTD_P3_PULL) ;	break;
	case HBUTTON_PORTD_P4 : *Copy_ptResult = get_button(DIO_PORTD,DIO_PIN4,BUTTON_PORTD_P4_PULL) ;	break;
	case HBUTTON_PORTD_P5 : *Copy_ptResult = get_button(DIO_PORTD,DIO_PIN5,BUTTON_PORTD_P5_PULL) ;	break;
	case HBUTTON_PORTD_P6 : *Copy_ptResult = get_button(DIO_PORTD,DIO_PIN6,BUTTON_PORTD_P6_PULL) ;	break;
	case HBUTTON_PORTD_P7 : *Copy_ptResult = get_button(DIO_PORTD,DIO_PIN7,BUTTON_PORTD_P7_PULL) ;	break;
	default				  :  errorState = return_Nok;

	}
	return errorState;
}

u8 get_button(u8 portNum, u8 copy_u8ButtonNum,u8 pull_type){
	u8 value = 3 ;
	MDIO_ErrorS_GetPinValue(portNum,copy_u8ButtonNum,&value);
	if (pull_type == PULL_DOWN){
		if (value == DIO_HIGH){
			value = 1;
		}
		else {
			value = 0;
		}
	}
	else if (pull_type == PULL_UP){
		if (value == DIO_HIGH){
			value = 0;
		}
		else {
			value = 1;
		}
	}
	return value;
}
