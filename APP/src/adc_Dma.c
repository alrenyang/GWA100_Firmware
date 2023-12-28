/*
 * adc.c
 *
 *  Created on: Oct 30, 2023
 *      Author: alren
 */

#include "adc_Dma.h"

extern ADC_HandleTypeDef hadc1;

uint16_t adc_data[3];

bool adcInit(void)
{
  HAL_ADCEx_Calibration_Start(&hadc1);

  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_data, 3);
  //HAL_ADCEx_MultiModeStart_DMA(&hadc1, (uint32_t *)adc_data, 3);

  return true;
}


uint16_t adcRead(uint8_t ch)
{
  uint16_t ret = 0;

  switch(ch)
  {
  case _DEF_CH1:
	  ret = adc_data[ch];
	  break;
  }


  return ret;
}

uint32_t adcReadVoltage(uint8_t ch)
{
  uint32_t ret;
  uint32_t adc_data;


  adc_data = adcRead(ch);

  ret = (330 * adc_data) / 4096;

  return ret;
}

float adcReadTemp(uint8_t ch)
{
	uint32_t adc_data;
	float temp = 0.0;

	adc_data = adcRead(ch);
	//temp = (357.558 - 0.187364 * adc_data);
	temp = ((TEMP_V25 - TEMP_VSENSE * adc_data) / TEMP_AVG_SLOPE) + 25;

	return temp;
}


