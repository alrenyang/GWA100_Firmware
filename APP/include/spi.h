/*
 * spi.h
 *
 *  Created on: Oct 31, 2023
 *      Author: alren
 */

#ifndef INCLUDE_SPI_H_
#define INCLUDE_SPI_H_

#include "def.h"

bool spiInit(void);
uint8_t spiReadByte(void);
void spiWriteByte(uint8_t writeByte);
void spiReadBurst(uint8_t* pBuf, uint16_t len);
void spiWriteBurst(uint8_t* pBuf, uint16_t len);
void wizchip_csEnable(void);
void wizchip_csDisable(void);
void wizchip_reset(void);

#endif /* INCLUDE_SPI_H_ */
