/*
 * HEEPROM_interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Amr-a
 */

#ifndef HEEPROM_INTERFACE_H_
#define HEEPROM_INTERFACE_H_

void EEPROM_voidWrite(u8 Copy_u8Data, u8 Copy_u7EEPROMAddress,u8 Copy_u8DataAddress);
void EEPROM_voidRead(u8 Copy_u7EEPROMAddress,u8 Copy_u8DataAddress, u8* Copy_pt8Data);


#endif /* HEEPROM_INTERFACE_H_ */
