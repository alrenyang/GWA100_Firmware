/*
 * usb_cdc.h
 *
 *  Created on: Dec 1, 2023
 *      Author: alren
 */

#ifndef INCLUDE_USB_CDC__H_
#define INCLUDE_USB_CDC__H_

#include "def.h"
#include "usbd_core.h"
#include "usbd_desc.h"

#if HW_USE_CDC == 1
#include "usbd_cdc.h"
#include "usbd_cdc_if.h"
#endif

typedef enum UsbMode
{
  USB_NON_MODE,
  USB_CDC_MODE,
  USB_MSC_MODE
} UsbMode_t;

typedef enum UsbType
{
  USB_CON_CDC = 0,
  USB_CON_CLI = 1,
  USB_CON_CAN = 2,
  USB_CON_ESP = 3,
} UsbType_t;


bool usbInit(void);
bool usbBegin(UsbMode_t usb_mode);
void usbDeInit(void);
bool usbIsOpen(void);
bool usbIsConnect(void);

UsbMode_t usbGetMode(void);
UsbType_t usbGetType(void);


#endif /* INCLUDE_USB_CDC__H_ */
