/*
 * adc.h
 *
 *  Created on: Oct 30, 2023
 *      Author: alren
 */

#ifndef INCLUDE_ADC_DMA_H_
#define INCLUDE_ADC_DMA_H_

#include "def.h"

bool adcInit(void);
uint16_t adcRead(uint8_t ch);
uint32_t adcReadVoltage(uint8_t ch);
float adcReadTemp(uint8_t ch);

#endif /* INCLUDE_ADC_DMA_H_ */
