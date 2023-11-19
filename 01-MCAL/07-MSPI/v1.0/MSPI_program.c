/*
 * MSPI_program.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSPI_registers.h"
#include "MSPI_interface.h"
#include "MSPI_private.h"
#include "MSPI_config.h"
void MSPI_voidInit(){
#if MASTER_SLAVE == MASTER
	SET_BIT(SPCR,SPCR_MSTR);
	/* selecting prescaler (frequancy) as dev bt 16 */
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif MASTER_SLAVE == SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#else
#warning "invalid input"
#endif
	/* select data order : least significant */
	SET_BIT(SPCR,SPCR_DORD);

	/* selecting my device is master or slave from config */

	/* choosispcrng clk polarity as: leading edge is rising */
	CLR_BIT(SPCR,SPCR_CPOL);
	/* seceting clock phase as: leading edge is setup */
	CLR_BIT(SPCR,SPCR_CPHA);

	/* enable spi */
	SET_BIT(SPCR,SPCR_SPE);

}
u8 MSPI_u8TransciveByte(u8 Copy_u8Data){
	SPDR = Copy_u8Data;
	/*read SPSR_SPIF then read SPDR*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	
	SET_BIT(SPCR,SPCR_SPIF);
	return SPDR;
}


