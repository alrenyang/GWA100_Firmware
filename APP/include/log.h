/*
 * log.h
 *
 *  Created on: Dec 1, 2023
 *      Author: alren
 */

#ifndef INCLUDE_LOG_H_
#define INCLUDE_LOG_H_

#include "def.h"

#ifdef _USE_HW_LOG

#define LOG_CH            HW_LOG_CH
#define LOG_BOOT_BUF_MAX  HW_LOG_BOOT_BUF_MAX
#define LOG_LIST_BUF_MAX  HW_LOG_LIST_BUF_MAX


bool logInit(void);
void logEnable(void);
void logDisable(void);
bool logOpen(uint8_t ch, uint32_t baud);
bool logIsOpen(void);
void logBoot(uint8_t enable);
void logPrintf(const char *fmt, ...);

#endif

#endif /* INCLUDE_LOG_H_ */
