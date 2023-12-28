################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ioLibrary_Driver/Ethernet/W5500/w5500.c 

OBJS += \
./ioLibrary_Driver/Ethernet/W5500/w5500.o 

C_DEPS += \
./ioLibrary_Driver/Ethernet/W5500/w5500.d 


# Each subdirectory must supply rules for building sources it contributes
ioLibrary_Driver/Ethernet/W5500/%.o ioLibrary_Driver/Ethernet/W5500/%.su ioLibrary_Driver/Ethernet/W5500/%.cyclo: ../ioLibrary_Driver/Ethernet/W5500/%.c ioLibrary_Driver/Ethernet/W5500/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/GWA100_Firmware/APP/include" -I"D:/GWA100_Firmware/APP/src" -I"D:/GWA100_Firmware/APP" -I"D:/GWA100_Firmware/ioLibrary_Driver" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application/loopback" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application/multicast" -I"D:/GWA100_Firmware/ioLibrary_Driver/Ethernet" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet/httpServer" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet/MQTT" -I"D:/GWA100_Firmware/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"D:/GWA100_Firmware/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"D:/GWA100_Firmware/USB_DEVICE/App" -I"D:/GWA100_Firmware/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ioLibrary_Driver-2f-Ethernet-2f-W5500

clean-ioLibrary_Driver-2f-Ethernet-2f-W5500:
	-$(RM) ./ioLibrary_Driver/Ethernet/W5500/w5500.cyclo ./ioLibrary_Driver/Ethernet/W5500/w5500.d ./ioLibrary_Driver/Ethernet/W5500/w5500.o ./ioLibrary_Driver/Ethernet/W5500/w5500.su

.PHONY: clean-ioLibrary_Driver-2f-Ethernet-2f-W5500

