/*
 * w5500.h
 *
 *  Created on: Oct 31, 2023
 *      Author: alren
 */

#ifndef INCLUDE_W5500_H_
#define INCLUDE_W5500_H_

#include "def.h"
#include "spi.h"
#include "wizchip_conf.h"
#include "socket.h"
#include "inttypes.h"
#include "Internet/MQTT/MQTTClient.h"
#include "Internet/DNS/dns.h"
#include "sonic.h"
#include "DNS/dns.h"
#include "mqtt_interface.h"
#include "cJSON.h"

bool w5500Init(void);
bool w5500Info(void);
void print_network_information(void);
void DnsInit(void);
void wizchip_initialize(void);
void messageArrived(MessageData* md);
void MqttRun(void);
void MqttSendData(char *data);
void Loopback_Test(void);

#endif /* INCLUDE_W5500_H_ */
