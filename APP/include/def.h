/*
 * def.h
 *
 *  Created on: Oct 30, 2023
 *      Author: alren
 */

#ifndef INCLUDE_DEF_H_
#define INCLUDE_DEF_H_

#include <stdbool.h>
#include <stdint.h>

#include <stdarg.h>
#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include "util.h"

#include "main.h"

#define _DEF_FIRMWATRE_VERSION    "V231121R1"
#define _DEF_BOARD_NAME           "STM32F103"

#define TEMP_AVG_SLOPE 0.0043
#define TEMP_V25       1.43
#define TEMP_VSENSE    3.3/4096

//#define _USE_WSDG_
#define _USE_DBG_

#define _DEF_CH1          0
#define _DEF_CH2          1
#define _DEF_CH3          2
#define _DEF_CH4          3

#define _DEF_UART1            0
#define _DEF_UART2            1
#define _DEF_UART3            2
#define _DEF_UART4            3

#define _DEF_SPI1             0
#define _DEF_SPI2             1
#define _DEF_SPI3             2
#define _DEF_SPI4             3

#define _DEF_I2C1             0
#define _DEF_I2C2             1
#define _DEF_I2C3             2
#define _DEF_I2C4             3

#define _DEF_PWM1             0
#define _DEF_PWM2             1
#define _DEF_PWM3             2
#define _DEF_PWM4             3

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

//#define _USE_HW_EEPROM
#define      HW_EEPROM_MAX_SIZE     (1*1024)

//#define _USE_HW_I2C
#define      HW_I2C_MAX_CH          1
#define      HW_I2C_CH_EEPROM       _DEF_I2C1

//#define _USE_HW_LOG
#define      HW_LOG_CH              _DEF_UART1
#define      HW_LOG_BOOT_BUF_MAX    1024*2
#define      HW_LOG_LIST_BUF_MAX    2048*2

#define _USE_HW_USB
#define _USE_HW_CDC
#define      HW_USE_CDC             1
#define      HW_USE_MSC             0

#define HW_UART_MAX_CH		  2

#define _USE_HW_CLI

#define LedPort			      GPIOA				//LED PORT
#define LedPin 			      GPIO_PIN_5		//LED PIN

#define Spi_CS_Port		      GPIOB				//SPI CE PORT
#define Spi_CS			      GPIO_PIN_12		//


#define Spi_Reseet_Port		  GPIOB				//SPI Reset Port
#define Spi_Reset			  GPIO_PIN_11		//

#define Spi_Rdy_Port		  GPIOB				//SPI Ready Port
#define Spi_Rdy			  GPIO_PIN_7		//

#endif /* INCLUDE_DEF_H_ */
