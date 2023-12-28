################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/src/adc_Dma.c \
../APP/src/cJSON.c \
../APP/src/cli.c \
../APP/src/eeprom.c \
../APP/src/i2c.c \
../APP/src/led.c \
../APP/src/log.c \
../APP/src/sonic.c \
../APP/src/spi.c \
../APP/src/swtimer.c \
../APP/src/uart.c \
../APP/src/usb_cdc_.c \
../APP/src/util.c \
../APP/src/w5500.c \
../APP/src/wdg.c 

OBJS += \
./APP/src/adc_Dma.o \
./APP/src/cJSON.o \
./APP/src/cli.o \
./APP/src/eeprom.o \
./APP/src/i2c.o \
./APP/src/led.o \
./APP/src/log.o \
./APP/src/sonic.o \
./APP/src/spi.o \
./APP/src/swtimer.o \
./APP/src/uart.o \
./APP/src/usb_cdc_.o \
./APP/src/util.o \
./APP/src/w5500.o \
./APP/src/wdg.o 

C_DEPS += \
./APP/src/adc_Dma.d \
./APP/src/cJSON.d \
./APP/src/cli.d \
./APP/src/eeprom.d \
./APP/src/i2c.d \
./APP/src/led.d \
./APP/src/log.d \
./APP/src/sonic.d \
./APP/src/spi.d \
./APP/src/swtimer.d \
./APP/src/uart.d \
./APP/src/usb_cdc_.d \
./APP/src/util.d \
./APP/src/w5500.d \
./APP/src/wdg.d 


# Each subdirectory must supply rules for building sources it contributes
APP/src/%.o APP/src/%.su APP/src/%.cyclo: ../APP/src/%.c APP/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/GWA100_Firmware/APP/include" -I"D:/GWA100_Firmware/APP/src" -I"D:/GWA100_Firmware/APP" -I"D:/GWA100_Firmware/ioLibrary_Driver" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application/loopback" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application/multicast" -I"D:/GWA100_Firmware/ioLibrary_Driver/Ethernet" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet/httpServer" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet/MQTT" -I"D:/GWA100_Firmware/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"D:/GWA100_Firmware/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"D:/GWA100_Firmware/USB_DEVICE/App" -I"D:/GWA100_Firmware/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP-2f-src

clean-APP-2f-src:
	-$(RM) ./APP/src/adc_Dma.cyclo ./APP/src/adc_Dma.d ./APP/src/adc_Dma.o ./APP/src/adc_Dma.su ./APP/src/cJSON.cyclo ./APP/src/cJSON.d ./APP/src/cJSON.o ./APP/src/cJSON.su ./APP/src/cli.cyclo ./APP/src/cli.d ./APP/src/cli.o ./APP/src/cli.su ./APP/src/eeprom.cyclo ./APP/src/eeprom.d ./APP/src/eeprom.o ./APP/src/eeprom.su ./APP/src/i2c.cyclo ./APP/src/i2c.d ./APP/src/i2c.o ./APP/src/i2c.su ./APP/src/led.cyclo ./APP/src/led.d ./APP/src/led.o ./APP/src/led.su ./APP/src/log.cyclo ./APP/src/log.d ./APP/src/log.o ./APP/src/log.su ./APP/src/sonic.cyclo ./APP/src/sonic.d ./APP/src/sonic.o ./APP/src/sonic.su ./APP/src/spi.cyclo ./APP/src/spi.d ./APP/src/spi.o ./APP/src/spi.su ./APP/src/swtimer.cyclo ./APP/src/swtimer.d ./APP/src/swtimer.o ./APP/src/swtimer.su ./APP/src/uart.cyclo ./APP/src/uart.d ./APP/src/uart.o ./APP/src/uart.su ./APP/src/usb_cdc_.cyclo ./APP/src/usb_cdc_.d ./APP/src/usb_cdc_.o ./APP/src/usb_cdc_.su ./APP/src/util.cyclo ./APP/src/util.d ./APP/src/util.o ./APP/src/util.su ./APP/src/w5500.cyclo ./APP/src/w5500.d ./APP/src/w5500.o ./APP/src/w5500.su ./APP/src/wdg.cyclo ./APP/src/wdg.d ./APP/src/wdg.o ./APP/src/wdg.su

.PHONY: clean-APP-2f-src

