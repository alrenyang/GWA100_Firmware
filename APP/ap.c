/*
 * ap.c
 *
 *  Created on: Oct 30, 2023
 *      Author: alren
 */

#include "ap.h"


static void infoCli(uint8_t argc, const char **argv);


//float adc_vol_vref = 0.0f;
//float tempture = 0.0f;
//uint32_t distance_ = 0.0f;


void ledISR(void *arg)
{
  //ledToggle(_DEF_CH1);
}

bool CheckRdy(void)
{
	bool ret = false;

	while(1)
	{
		if(HAL_GPIO_ReadPin(Spi_Rdy_Port, Spi_Rdy) == 1)
		{
			break;
		}
	}


	return ret;
}

void apInit(void)
{
//	uint8_t  data;
	HAL_Delay(35000);

#ifdef _USE_WDG_
	wdgInit();
	wdgBegin(4000);
#endif

	cliInit();
	swtimerInit();
	uartInit();
	uartPrintf(_DEF_CH1,"\r\n[ Firmware Begin... ]\r\n");
	uartPrintf(_DEF_CH1,"Booting..Name \t\t: %s\r\n", _DEF_BOARD_NAME);
	uartPrintf(_DEF_CH1,"Booting..Ver  \t\t: %s\r\n", _DEF_FIRMWATRE_VERSION);
	uartPrintf(_DEF_CH1,"Booting..Clock\t\t: %d Mhz\r\n", (int)HAL_RCC_GetSysClockFreq()/1000000);
	uartPrintf(_DEF_CH1,"\n");
	adcInit();
	//i2cInit();
	//eepromInit();
	//eepromWriteByte(0x00, 0x11);
	//eepromReadByte(0x00, &data);
	//usbInit();
    //usbBegin(USB_CDC_MODE);
//	uartPrintf(_DEF_CH1, "addr : %d\t 0x%02X\n", 0x00, data);
	wizchip_reset();

	HAL_Delay(200);
	CheckRdy();

	HAL_Delay(20);
	w5500Init();
//	uartPrintf(_DEF_CH1, "--test-----\r\n");
	cliAdd("info", infoCli);

	uint8_t timer_ch;

	if (swtimerGetCh(&timer_ch) == true)
	{
		swtimerSet(timer_ch,
				   ledISR,
				   NULL,
				   SWTIMER_LOOP,
				   500);
		swtimerStart(timer_ch);
	}
}

void apMain(void)
{
	uint32_t pre_time;

	uartPrintf(_DEF_CH1,"-------------------------------\r\n");
	uartPrintf(_DEF_CH1,"[ Firmware Version %s ]\r\n", _DEF_FIRMWATRE_VERSION);
	uartPrintf(_DEF_CH1,"[ Board Version %s    ]\r\n", _DEF_BOARD_NAME);
	uartPrintf(_DEF_CH1,"-------------------------------\r\n");

    w5500Info();
	HAL_Delay(10);

	print_network_information();
	HAL_Delay(10);
	DnsInit();

	HAL_Delay(10);
	MqttRun();

	while(1)
	{
		//Loopback_Test();

		if (millis()-pre_time >= 500)
		{
		  pre_time = millis();

		  //ledToggle(_DEF_CH1);
		  //adc_vol      = (float)adcReadVoltage(_DEF_CH1) / 100.f;
//		  tempture     = (float)adcReadTemp(_DEF_CH2) / 10.f;
//		  adc_vol_vref = (float)adcReadVoltage(_DEF_CH3) / 100.f;

//		  uartPrintf(_DEF_CH1,"TEMP: %.2f\r\n", tempture);
//		  printf("TEMP: %f\r\n", tempture);
//		  distance_ = ReadAvgDst();


#ifdef _USE_DBG_
//		  uartPrintf(_DEF_CH1,"Distance: %d\r\n", distance_);
#endif
		}

		cliMain();
#ifdef _USE_WDG_
		wdgRefresh();
#endif
	}//end while
}

void infoCli(uint8_t argc, const char **argv)
{
  bool ret = false;


  if (argc == 1 && cliIsStr(argv[0], "test"))
	{
		cliPrintf("infoCli run test\r\n");
		ret = true;
	}

  if (argc == 2 && cliIsStr(argv[0], "print"))
	{
	  uint8_t count;

	count = (uint8_t)cliGetData(argv[1]);
	for (int i=0; i<count; i++)
	{
	  cliPrintf("print %d/%d\r\n", i+1, count);
	}

		ret = true;
	}

  if (argc == 1 && cliIsStr(argv[0], "led_on"))
	{
		ledOn(_DEF_CH1);
		ret = true;
	}

  if (argc == 1 && cliIsStr(argv[0], "led_off"))
	{
		ledOff(_DEF_CH1);
		ret = true;
	}

  if (argc == 1 && cliIsStr(argv[0], "netinfo"))
	{
		print_network_information();
		ret = true;
	}

  if (argc == 1 && cliIsStr(argv[0], "mqttrun"))
  	{
	    MqttRun();
  		ret = true;
  	}

  if (ret == false)
	{
		cliPrintf("info test\r\n");
		cliPrintf("info print 0~10\r\n");
		cliPrintf("info led_on\r\n");
		cliPrintf("info led_off\r\n");
		cliPrintf("info netinfo\r\n");
		cliPrintf("info MQTTRUN\r\n");
	}
}
