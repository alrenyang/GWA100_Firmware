################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ioLibrary_Driver/Application/loopback/loopback.c 

OBJS += \
./ioLibrary_Driver/Application/loopback/loopback.o 

C_DEPS += \
./ioLibrary_Driver/Application/loopback/loopback.d 


# Each subdirectory must supply rules for building sources it contributes
ioLibrary_Driver/Application/loopback/%.o ioLibrary_Driver/Application/loopback/%.su ioLibrary_Driver/Application/loopback/%.cyclo: ../ioLibrary_Driver/Application/loopback/%.c ioLibrary_Driver/Application/loopback/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/GWA100_Firmware/APP/include" -I"D:/GWA100_Firmware/APP/src" -I"D:/GWA100_Firmware/APP" -I"D:/GWA100_Firmware/ioLibrary_Driver" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application/loopback" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application/multicast" -I"D:/GWA100_Firmware/ioLibrary_Driver/Ethernet" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet/httpServer" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet/MQTT" -I"D:/GWA100_Firmware/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"D:/GWA100_Firmware/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"D:/GWA100_Firmware/USB_DEVICE/App" -I"D:/GWA100_Firmware/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ioLibrary_Driver-2f-Application-2f-loopback

clean-ioLibrary_Driver-2f-Application-2f-loopback:
	-$(RM) ./ioLibrary_Driver/Application/loopback/loopback.cyclo ./ioLibrary_Driver/Application/loopback/loopback.d ./ioLibrary_Driver/Application/loopback/loopback.o ./ioLibrary_Driver/Application/loopback/loopback.su

.PHONY: clean-ioLibrary_Driver-2f-Application-2f-loopback

