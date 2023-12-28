/*
 * usb_cdc.c
 *
 *  Created on: Dec 1, 2023
 *      Author: alren
 */

#include <usb_cdc_.h>
#include "cli.h"

static bool is_init = false;
static UsbMode_t is_usb_mode = USB_NON_MODE;

USBD_HandleTypeDef USBD_Device;
extern PCD_HandleTypeDef hpcd_USB_OTG_HS;


extern USBD_DescriptorsTypeDef MSC_Desc;

bool usbInit(void)
{
  return true;
}


bool usbBegin(UsbMode_t usb_mode)
{
  is_init = true;

  if (usb_mode == USB_CDC_MODE)
  {
    /* Init Device Library */
    USBD_Init(&USBD_Device, &FS_Desc, DEVICE_FS);

    /* Add Supported Class */
    USBD_RegisterClass(&USBD_Device, USBD_CDC_CLASS);

    /* Add CDC Interface Class */
    USBD_CDC_RegisterInterface(&USBD_Device, &USBD_Interface_fops_FS);

    /* Start Device Process */
    USBD_Start(&USBD_Device);

    //HAL_PWREx_EnableUSBVoltageDetector();

    is_usb_mode = USB_CDC_MODE;

    //logPrintf("[OK] usbBegin()\n");
    //logPrintf("     USB_CDC\r\n");
  }
  else if (usb_mode == USB_MSC_MODE)
  {
    #if HW_USE_MSC == 1
    /* Init Device Library */
    USBD_Init(&USBD_Device, &MSC_Desc, DEVICE_FS);

    /* Add Supported Class */
    USBD_RegisterClass(&USBD_Device, USBD_MSC_CLASS);

    /* Add Storage callbacks for MSC Class */
    USBD_MSC_RegisterStorage(&USBD_Device, &USBD_DISK_fops);

    /* Start Device Process */
    USBD_Start(&USBD_Device);

    HAL_PWREx_EnableUSBVoltageDetector();

    is_usb_mode = USB_MSC_MODE;

    logPrintf("[OK] usbBegin()\n");
    logPrintf("     USB_MSC\r\n");
    #endif
  }
  else
  {
    is_init = false;

    //logPrintf("[NG] usbBegin()\n");
  }

  return is_init;
}

void usbDeInit(void)
{
  if (is_init == true)
  {
    USBD_DeInit(&USBD_Device);
  }
}

bool usbIsOpen(void)
{
  return cdcIsConnect();
}

bool usbIsConnect(void)
{
  if (USBD_Device.pClassData == NULL)
  {
    return false;
  }
  if (USBD_Device.dev_state != USBD_STATE_CONFIGURED)
  {
    return false;
  }
  if (USBD_Device.dev_config == 0)
  {
    return false;
  }
  if (USBD_is_connected() == false)
  {
    return false;
  }

  return true;
}


UsbMode_t usbGetMode(void)
{
  return is_usb_mode;
}

UsbType_t usbGetType(void)
{
  return (UsbType_t)cdcGetType();
}

void OTG_HS_IRQHandler(void)
{
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_HS);
}



