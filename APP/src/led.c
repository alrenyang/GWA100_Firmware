/*
 * led.c
 *
 *  Created on: Oct 30, 2023
 *      Author: alren
 */

#include "led.h"


bool ledInit(void)
{
	bool ret = true;

	return ret;
}

void ledOn(uint8_t ch)
{
	HAL_GPIO_WritePin(LedPort, LedPin, RESET);
}

void ledOff(uint8_t ch)
{
	HAL_GPIO_WritePin(LedPort, LedPin, SET);
}

void ledToggle(uint8_t ch)
{
	HAL_GPIO_TogglePin(LedPort, LedPin);
}
