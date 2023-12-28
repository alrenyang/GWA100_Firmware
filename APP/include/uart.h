/*
 * uart.h
 *
 *  Created on: Oct 30, 2023
 *      Author: alren
 */

#ifndef INCLUDE_UART_H_
#define INCLUDE_UART_H_

#include "def.h"

#define UART_MAX_CH           HW_UART_MAX_CH

bool     uartInit(void);
bool     uartDeInit(void);
bool     uartIsInit(void);

uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length);
uint32_t uartAvailable(uint8_t ch);
uint8_t  uartRead(uint8_t ch);
uint32_t uartPrintf(uint8_t ch, const char *fmt, ...);
uint32_t uartVPrintf(uint8_t ch, const char *fmt, va_list arg);


#endif /* INCLUDE_UART_H_ */
