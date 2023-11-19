/*
 * MTWI_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Amr-a
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MTWI_interface.h"
#include "MTWI_private.h"
#include "MTWI_registers.h"
#include "MTWI_config.h"

void MTWI_voidInit(void){

	/*	Setting my adderss */
	TWAR = (MY_ADDRESS<<1);

	/*just two bits an other wil be set later*/
	/* setting prescaler value */
#if TWI_PRESCALER == TWI_DIV_1
	TWSR = 0b00000000;
#elif TWI_PRESCALER == TWI_DIV_4
	TWSR = 0b00000001;
#elif TWI_PRESCALER == TWI_DIV_16
	TWSR = 0b00000010;
#elif TWI_PRESCALER == TWI_DIV_64
	TWSR = 0b00000011;
#endif
	/* setting remaining of prescaler */
	TWBR = TWBR_VALUE;
	/* Enabling flag */
	SET_BIT(TWCR,TWCR_TWEN);

}

void MTWI_voidStart(void){
	/*Set TWSTA to start condition*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/* clearig flag be setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/*setting TWEN to enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
	/* busy wait on TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT))==0);

}

void MTWI_voidWrite(u8 Copy_u8Data){
	/* clearing forst bit to enable Write */
	//CLR_BIT();
	/* Assiging value */
	/* bouth are in one instruction */
	TWDR = Copy_u8Data;
	/* CLR start condition */
	CLR_BIT(TWCR,TWCR_TWSTA);
	/* clearig flag be setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/*setting TWEN to enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
	/* busy wait on TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT))==0);

}

u8 MTWI_u8ReadWithACK(void){
	/* CLR start condition */
	CLR_BIT(TWCR,TWCR_TWSTA);
	/* clearig flag be setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/*setting TWEN to enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
	/* busy wait on TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT))==0);
	return TWDR;
}

void MTWI_voidStop(void){
	/* set to Make stop condition */
	SET_BIT(TWCR,TWCR_TWSTO);
	/* clearig flag be setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/*setting TWEN to enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);


}

u8 MTWI_u8GetStatus(void){
	return (TWSR&0xF8);
}
