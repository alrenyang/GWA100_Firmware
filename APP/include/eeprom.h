/*
 * eeprom.h
 *
 *  Created on: Nov 21, 2023
 *      Author: alren
 */

#ifndef INCLUDE_EEPROM_H_
#define INCLUDE_EEPROM_H_

#include "def.h"

#ifdef _USE_HW_EEPROM
bool     eepromInit();
bool     eepromIsInit(void);
bool     eepromValid(uint32_t addr);
bool     eepromReadByte(uint32_t addr, uint8_t *p_data);
bool     eepromWriteByte(uint32_t addr, uint8_t data_in);
bool     eepromRead(uint32_t addr, uint8_t *p_data, uint32_t length);
bool     eepromWrite(uint32_t addr, uint8_t *p_data, uint32_t length);
uint32_t eepromGetLength(void);
bool     eepromFormat(void);
#endif


#endif /* INCLUDE_EEPROM_H_ */
