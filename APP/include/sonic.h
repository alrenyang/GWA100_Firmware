/*
 * sonic.h
 *
 *  Created on: Nov 3, 2023
 *      Author: alren
 */

#ifndef INCLUDE_SONIC_H_
#define INCLUDE_SONIC_H_

#include "def.h"

uint32_t ReadDst(void);
uint32_t ReadAvgDst(void);
uint8_t calData(uint32_t* avg,uint8_t cnt);

float KalmanFiltercal(void);

#endif /* INCLUDE_SONIC_H_ */
