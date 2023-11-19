/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	: MCAL		********/
/********************	Module	: DIO		********/
/********************	Version: 1.00		********/
/********************	Date	: 2/8/2023	********/
/***************************************************/
/**************************************************/
#ifndef _MDIO_PRIVATE_H
#define _MDIO_PRIVATE_H
#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)		CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)	0B##B7##B6##B5##B4##B3##B2##B1##B0

#define PORTA_DIR 							CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR 							CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR 							CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR 							CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

#define PORTA_INITAL_VAL					CONC(PORTA_PIN7_INITAL_VALUE,PORTA_PIN6_INITAL_VALUE,PORTA_PIN5_INITAL_VALUE,PORTA_PIN4_INITAL_VALUE,PORTA_PIN3_INITAL_VALUE,PORTA_PIN2_INITAL_VALUE,PORTA_PIN1_INITAL_VALUE,PORTA_PIN0_INITAL_VALUE)
#define PORTB_INITAL_VAL					CONC(PORTB_PIN7_INITAL_VALUE,PORTB_PIN6_INITAL_VALUE,PORTB_PIN5_INITAL_VALUE,PORTB_PIN4_INITAL_VALUE,PORTB_PIN3_INITAL_VALUE,PORTB_PIN2_INITAL_VALUE,PORTB_PIN1_INITAL_VALUE,PORTB_PIN0_INITAL_VALUE)
#define PORTC_INITAL_VAL					CONC(PORTC_PIN7_INITAL_VALUE,PORTC_PIN6_INITAL_VALUE,PORTC_PIN5_INITAL_VALUE,PORTC_PIN4_INITAL_VALUE,PORTC_PIN3_INITAL_VALUE,PORTC_PIN2_INITAL_VALUE,PORTC_PIN1_INITAL_VALUE,PORTC_PIN0_INITAL_VALUE)
#define PORTD_INITAL_VAL					CONC(PORTD_PIN7_INITAL_VALUE,PORTD_PIN6_INITAL_VALUE,PORTD_PIN5_INITAL_VALUE,PORTD_PIN4_INITAL_VALUE,PORTD_PIN3_INITAL_VALUE,PORTD_PIN2_INITAL_VALUE,PORTD_PIN1_INITAL_VALUE,PORTD_PIN0_INITAL_VALUE)



#endif

