/*
 * ap.h
 *
 *  Created on: Oct 30, 2023
 *      Author: alren
 */

#ifndef AP_H_
#define AP_H_


#include "util.h"
#include "led.h"
#include "uart.h"
#include "cli.h"
#include "adc_Dma.h"
#include "spi.h"
#include "w5500.h"
#include "sonic.h"
#include "wdg.h"
#include "swtimer.h"
#include "log.h"
#include "i2c.h"
#include "eeprom.h"
#include "usb_cdc_.h"

void apInit(void);
void apMain(void);

#endif /* AP_H_ */
