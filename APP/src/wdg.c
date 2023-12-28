/*
 * wdg.c
 *
 *  Created on: Nov 9, 2023
 *      Author: alren
 */


#include "wdg.h"

static IWDG_HandleTypeDef hiwdg;

bool wdgInit(void)
{

	return true;
}

bool wdgBegin(uint32_t time_ms)
{
	if(time_ms >= 4095)
	{
		return false;
	}

	hiwdg.Instance = IWDG;
	hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
	hiwdg.Init.Reload = time_ms;
	if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
	{
		return false;
	}

	return true;
}

bool wdgRefresh(void)
{
	HAL_IWDG_Refresh(&hiwdg);
	return true;
}


