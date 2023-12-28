/*
 * w5500.c
 *
 *  Created on: Oct 31, 2023
 *      Author: alren
 */

#include "w5500.h"

// use tc700
wiz_NetInfo gWIZNETINFO  = {

//	.mac = {0x00, 0x08, 0xdc, 0x77, 0x84, 0xA0},
//	.mac = {0x00, 0x08, 0xdc, 0x77, 0x84, 0xA3},
//	.mac = {0x00, 0x08, 0xdc, 0x77, 0x84, 0xA2},
	.mac = {0x00, 0x08, 0xdc, 0x77, 0x84, 0xA1},	// must be user mac address changed
    .ip = {192,168,39,22},		// user ip address changed....
//	.ip = {192,168,0,16},
    .sn = {255, 255, 255, 0},
    .gw = {192, 168, 39, 1},
//	.gw = {192, 168, 0, 1},

//    .dns = {8, 8, 8, 8},
	.dns = {164, 124, 101, 2},
    .dhcp = NETINFO_STATIC
};

#define ETH_MAX_BUF_SIZE  2048
#define PUBLISH_MYSELF 1

//const uint8_t URL[] = "https://112, 168, 210, 249";
//const uint8_t URL[] = "broker.hivemq.com";
//const uint8_t URL[] = "test.mosquitto.org";
const uint8_t URL[] = "www.google.com";
uint8_t dns_server_ip[4] = {168,126,63,1};
//uint8_t dns_server_ip[4] = {164,124,101,2};
uint8_t dnsclient_ip[4] = {0,};
//uint8_t dnsclient_ip[4] = {112, 168, 210, 249};
unsigned int targetPort = 1883; // mqtt server port

unsigned char targetIP[4] = {112, 168, 210, 249}; // mqtt server IP 112.168.210.249
//unsigned char targetIP[4] = {192, 168, 0, 17}; // mqtt server IP 112.168.210.249

unsigned char ethBuf0[ETH_MAX_BUF_SIZE];
unsigned char ethBuf1[ETH_MAX_BUF_SIZE];
unsigned char ethBuf2[ETH_MAX_BUF_SIZE];
unsigned char ethBuf3[ETH_MAX_BUF_SIZE];

char json[128] = {};

uint8_t IP_TYPE;

const uint8_t MQTT_TOPIC[]="golf/waterlevel/raw/23050002";
//const uint8_t MQTT_TOPIC[]="MY_TOPIC";
unsigned char tempBuffer[1024*2] = {};



struct opts_struct
{
  unsigned char* clientid;
  int nodelimiter;
  unsigned char* delimiter;
  enum QoS qos;
  unsigned char* username;
  unsigned char* password;
  unsigned char* host;
  int port;
  int showtopics;
} opts ={ (unsigned char*)"water02", 0, (unsigned char*)"\n", QOS1, NULL, NULL, targetIP, 1883, 0 };


#define SOCK_HTTPC  0
#define SOCK_DHCP   1
#define SOCK_DNS    2
#define DATA_BUF_SIZE 512

#define SOCKET_LOOP  		2

uint8_t flag_process_dns_success = 0;
uint8_t dns_server[4] = {8, 8, 8, 8};
uint8_t Domain_IP[4]  = {0, };
uint8_t g_send_buf[DATA_BUF_SIZE];
uint8_t g_recv_buf[DATA_BUF_SIZE];

// loopback_tcps data initialize
//uint8_t tcp_loopback_data[DATA_BUF_SIZE];
//
//uint8_t Domain_name[] = "github.com";
//uint8_t URI[] = "/";
//uint8_t flag_sent_http_request = DISABLE;
//
//uint8_t destip[4] = {192, 168, 0, 15};


bool w5500Init(void)
{
	reg_wizchip_cs_cbfunc(wizchip_csEnable,wizchip_csDisable);// CS function register
	HAL_Delay(100);
	reg_wizchip_spi_cbfunc(spiReadByte, spiWriteByte);

	//reg_wizchip_spiburst_cbfunc(spiReadBurst, spiWriteBurst);
	//uartPrintf(_DEF_CH1, "--test-----\r\n");
	HAL_Delay(100);
	wizchip_initialize();

	return true;
}

void wizchip_initialize(void)
{
  uint8_t W5x00_AdrSet[2][8] = {{2, 2, 2, 2, 2, 2, 2, 2},{2, 2, 2, 2, 2, 2, 2, 2},};
  //uint8_t tmp1, tmp2;
  int8_t phy_link =0;
  intr_kind temp= IK_DEST_UNREACH;

  wizchip_reset();
  HAL_Delay(200);
  if (ctlwizchip(CW_INIT_WIZCHIP, (void*)W5x00_AdrSet) == -1)
	  uartPrintf(_DEF_CH1,">>>>W5100s memory initialization failed\r\n");
  HAL_Delay(200);

  if(ctlwizchip(CW_SET_INTRMASK,&temp) == -1)
	  uartPrintf(_DEF_CH1,"W5100S interrupt\r\n");
  HAL_Delay(200);


  if(getVERSIONR() != 0x04){
	  uartPrintf(_DEF_CH1,">>>>Access ERR: VERSION != 0x04, value = %02x\r\n", getVERSIONR());
	  NVIC_SystemReset();
  }else{
	  uartPrintf(_DEF_CH1,"---------------------------------------------------\r\n");
	  uartPrintf(_DEF_CH1,"[ Access Get: VERSION = %02x ]\r\n", getVERSIONR());\
	  uartPrintf(_DEF_CH1,"---------------------------------------------------\r\n");
	  uartPrintf(_DEF_CH1,"\r\n");
  }

  do{//check phy status.
  		if(ctlwizchip(CW_GET_PHYLINK,&phy_link) == -1){
  			uartPrintf(_DEF_CH1,"Unknown PHY link status.\r\n");
  			delay(10);
  			NVIC_SystemReset();
  		}

  	}while(phy_link == PHY_LINK_OFF);

//  while(1)
//  {
//    ctlwizchip(CW_GET_PHYLINK, &phy_link );
//    HAL_Delay(4000);
//    ctlwizchip(CW_GET_PHYLINK, &tmp2 );
//    HAL_Delay(4000);
//    if(tmp1==PHY_LINK_ON && tmp2==PHY_LINK_ON)
//	{
//    	uartPrintf(_DEF_CH1,">>>>W5x00s done initialization....\r\n");
//		break;
//	}
//    else{
//    	uartPrintf(_DEF_CH1,">>>>W5x00s done initialization failed....\r\n");
//    	NVIC_SystemReset();
//    }
//  }
}


void Loopback_Test(void)
{
	uint32_t ret;

//	if(ret = loopback_tcps(SOCKET_LOOP,&tcp_loopback_data,5000) < 0)
//	{
//		uartPrintf(_DEF_CH1,"Error %d\r\n",ret);
//	}
//	loopback_tcps(0,&tcp_loopback_data,5000);
	//loopback_tcpc(0,&tcp_loopback_data, destip, 5000 );
}


bool w5500Info(void)
{
//	uint8_t mac[6];
//	memset(&mac,0,sizeof(mac));
//	getSHAR(mac);
//	uartPrintf(_DEF_CH1, "==========================================\n\r");
//	//uartPrintf(_DEF_CH1,"MAC Address : %02x:%02x:%02x:%02x:%02x:%02x\n\r",gWIZNETINFO.mac[0],gWIZNETINFO.mac[1],gWIZNETINFO.mac[2],gWIZNETINFO.mac[3],gWIZNETINFO.mac[4],gWIZNETINFO.mac[5]);
//	uartPrintf(_DEF_CH1,"MAC Address : %02x:%02x:%02x:%02x:%02x:%02x\n\r",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
//	uartPrintf(_DEF_CH1, "==========================================\n\r");
	wizchip_setnetinfo(&gWIZNETINFO);

	return true;
}

void print_network_information(void)
{
	memset(&gWIZNETINFO,0,sizeof(gWIZNETINFO));
#ifdef _USE_DBG_
	wizchip_getnetinfo(&gWIZNETINFO);
	uartPrintf(_DEF_CH1, "==========================================\n\r");
	uartPrintf(_DEF_CH1,"MAC Address : %02x:%02x:%02x:%02x:%02x:%02x\n\r",gWIZNETINFO.mac[0],gWIZNETINFO.mac[1],gWIZNETINFO.mac[2],gWIZNETINFO.mac[3],gWIZNETINFO.mac[4],gWIZNETINFO.mac[5]);
	uartPrintf(_DEF_CH1,"IP  Address : %d.%d.%d.%d\n\r",gWIZNETINFO.ip[0],gWIZNETINFO.ip[1],gWIZNETINFO.ip[2],gWIZNETINFO.ip[3]);
	uartPrintf(_DEF_CH1,"Subnet Mask : %d.%d.%d.%d\n\r",gWIZNETINFO.sn[0],gWIZNETINFO.sn[1],gWIZNETINFO.sn[2],gWIZNETINFO.sn[3]);
	uartPrintf(_DEF_CH1,"Gateway     : %d.%d.%d.%d\n\r",gWIZNETINFO.gw[0],gWIZNETINFO.gw[1],gWIZNETINFO.gw[2],gWIZNETINFO.gw[3]);
	uartPrintf(_DEF_CH1,"DNS Server  : %d.%d.%d.%d\n\r",gWIZNETINFO.dns[0],gWIZNETINFO.dns[1],gWIZNETINFO.dns[2],gWIZNETINFO.dns[3]);
	uartPrintf(_DEF_CH1, "==========================================\n\r");
	uartPrintf(_DEF_CH1, "\n\r");
#endif
	if(gWIZNETINFO.mac[0] == 0xFF)
	{
		while(1)
		{
			////forever loop wdg call
			NVIC_SystemReset();
		}
	}
}

void DnsInit(void)
{
	DNS_init(0,ethBuf0);
	IP_TYPE = 0x1c;
    while (DNS_run(dns_server_ip, URL, dnsclient_ip) != 1);

#ifdef _USE_DBG_
    uartPrintf(_DEF_CH1, "==========================================\n\r");
    uartPrintf(_DEF_CH1, ">>>>W5x00s DNS Init done initialization\n\r");
    uartPrintf(_DEF_CH1, "==========================================\n\r");
#endif
}

void messageArrived(MessageData* md)
{
  unsigned char testbuffer[100];
  uint32_t rd_size;
  uint32_t rd_pt;
  uint32_t rdmore_size;

  MQTTMessage* message = md->message;
  MQTTString* topic = md->topicName;

  //unsigned char data[50];


  rdmore_size = (int)topic->lenstring.len;
  rd_pt = 0;

  while(rdmore_size != 0)
  {
    if(rdmore_size > sizeof(testbuffer) - 1)
    {
      rd_size = sizeof(testbuffer) - 1;
    }
    else
    {
      rd_size = rdmore_size;
    }

    memset(testbuffer, 0, rd_size + 1);

    memcpy(testbuffer, ((char*)topic->lenstring.data) + rd_pt, rd_size);
    uartPrintf(_DEF_CH1,"SubScribe Topic : %s\r\n", testbuffer);

    rd_pt += rd_size;
    rdmore_size -= rd_size;
  }

  if (opts.nodelimiter)
  {
	  uartPrintf(_DEF_CH1,"Message1 : %.*s\r\n", (int)message->payloadlen, (char*)message->payload);
  }
  else
  {
	  uartPrintf(_DEF_CH1,"Message2 : %.*s%s\r\n", (int)message->payloadlen, (char*)message->payload, opts.delimiter);
	  //unsigned char data = (char*)message->payload;
	  uartPrintf(_DEF_CH1,"me--> %s\r\n", (char*)message->payload);

  }
}

void MqttRun(void)
{
	int rc = 0;
	uint8_t buf[100];
	uint8_t pubbuf[200];
	Network n;
	MQTTClient c;
	MQTTMessage m;
	uint32_t ck_timer;
	uint32_t dist;
	uint32_t adc_raw;

	//Json create


	uartPrintf(_DEF_CH1,"---------------------------------------------------\r\n");
	uartPrintf(_DEF_CH1,"Mqtt Run...\r\n");
	uartPrintf(_DEF_CH1,"---------------------------------------------------\r\n");

	NewNetwork(&n, 0);
//	uint8_t Error = ConnectNetwork(&n, dnsclient_ip, targetPort);
	uint8_t Error = ConnectNetwork(&n, targetIP, targetPort);

	if(Error == SOCK_OK)
	{
#ifdef _USE_DBG_
		uartPrintf(_DEF_CH1, "[ ConnectNetwork... ]\n\r");
		uartPrintf(_DEF_CH1, "\r");
#endif
	}
	else
	{
#ifdef _USE_DBG_
		while(1)
		{
			NVIC_SystemReset();
			//forever loop wdg call
		}
#endif
	}


	MQTTClientInit(&c, &n, 1000, buf, sizeof(buf), tempBuffer, sizeof(tempBuffer));

	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
	data.willFlag = 0;
	data.MQTTVersion = 3;
	data.clientID.cstring = opts.clientid;
	data.username.cstring = opts.username;
	data.password.cstring = opts.password;

	data.keepAliveInterval = 60;
	//data.keepAliveInterval = 80;
	data.cleansession = 1;

	rc = MQTTConnect(&c, &data);
	uartPrintf(_DEF_CH1,"[ Connected Mqtt server ]...%d\r\n", rc);
	opts.showtopics = 1;

	uartPrintf(_DEF_CH1,"[ Subscribing to %s ]\r\n", MQTT_TOPIC);
	rc = MQTTSubscribe(&c, MQTT_TOPIC, opts.qos, messageArrived);
	uartPrintf(_DEF_CH1,"[ Subscribed %d ]\r\n", rc);

	#if PUBLISH_MYSELF == 1
	m.qos = QOS0;
	m.retained = 0;
	m.dup = 0;

	ck_timer = millis();
	#endif


	while(1)
	{
		MQTTYield(&c, data.keepAliveInterval);

		#if PUBLISH_MYSELF == 1

		if(ck_timer + 10000 < millis())
		{
			//uartPrintf(_DEF_CH1,"time check to %d\r\n", ck_timer);
			ck_timer = millis();

			uartPrintf(_DEF_CH1,"[ Publishing to %s ]\r\n", MQTT_TOPIC);
			uartPrintf(_DEF_CH1,"-----------------------------------------\r\n");
			uartPrintf(_DEF_CH1,"\r");

//			sprintf(pubbuf, "Test Mqtt message" );
			dist = ReadAvgDst();
			adc_raw = ReadDst();

			cJSON * root = cJSON_CreateObject();
//			cJSON_AddItemToObject(root,"serial_number", cJSON_CreateString("23040002"));
			cJSON_AddItemToObject(root,"type", cJSON_CreateString("new"));
			cJSON_AddItemToObject(root,"value", cJSON_CreateNumber(dist));
			cJSON_AddItemToObject(root,"raw", cJSON_CreateNumber(adc_raw));
			unsigned char *jsonString = cJSON_Print(root);

//			uartPrintf(_DEF_CH1,(uint8_t *)jsonString);

			sprintf(pubbuf, (uint8_t *)jsonString);
			m.payload = pubbuf;
			m.payloadlen = strlen(pubbuf);
//			m.payload = (uint8_t *)jsonString;
//			m.payloadlen = strlen(jsonString);

			rc = MQTTPublish(&c, MQTT_TOPIC, &m);
			uartPrintf(_DEF_CH1,"-----------------------------------------\r\n");
			uartPrintf(_DEF_CH1,"\r");
			uartPrintf(_DEF_CH1,"[ Published result : %d ]\r\n", rc);
			uartPrintf(_DEF_CH1,"\r");

			if(rc == 0){
				ledToggle(_DEF_CH1);
			}


			if(rc == -1){
				uartPrintf(_DEF_CH1,"[ Published failed... ]\r\n");
				MQTTDisconnect(&c);
				NVIC_SystemReset();
			}

			cJSON_Delete(root);
			free(jsonString);
//#ifdef _USE_WDG_
//		wdgRefresh();
//#endif
		}
		#endif
#ifdef _USE_WDG_
		wdgRefresh();
#endif
	}
}

void MqttSendData(char *data)
{

}



