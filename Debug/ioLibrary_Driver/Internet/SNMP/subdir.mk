################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ioLibrary_Driver/Internet/SNMP/snmp.c \
../ioLibrary_Driver/Internet/SNMP/snmp_custom.c 

OBJS += \
./ioLibrary_Driver/Internet/SNMP/snmp.o \
./ioLibrary_Driver/Internet/SNMP/snmp_custom.o 

C_DEPS += \
./ioLibrary_Driver/Internet/SNMP/snmp.d \
./ioLibrary_Driver/Internet/SNMP/snmp_custom.d 


# Each subdirectory must supply rules for building sources it contributes
ioLibrary_Driver/Internet/SNMP/%.o ioLibrary_Driver/Internet/SNMP/%.su ioLibrary_Driver/Internet/SNMP/%.cyclo: ../ioLibrary_Driver/Internet/SNMP/%.c ioLibrary_Driver/Internet/SNMP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/GWA100_Firmware/APP/include" -I"D:/GWA100_Firmware/APP/src" -I"D:/GWA100_Firmware/APP" -I"D:/GWA100_Firmware/ioLibrary_Driver" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application/loopback" -I"D:/GWA100_Firmware/ioLibrary_Driver/Application/multicast" -I"D:/GWA100_Firmware/ioLibrary_Driver/Ethernet" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet/httpServer" -I"D:/GWA100_Firmware/ioLibrary_Driver/Internet/MQTT" -I"D:/GWA100_Firmware/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"D:/GWA100_Firmware/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"D:/GWA100_Firmware/USB_DEVICE/App" -I"D:/GWA100_Firmware/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ioLibrary_Driver-2f-Internet-2f-SNMP

clean-ioLibrary_Driver-2f-Internet-2f-SNMP:
	-$(RM) ./ioLibrary_Driver/Internet/SNMP/snmp.cyclo ./ioLibrary_Driver/Internet/SNMP/snmp.d ./ioLibrary_Driver/Internet/SNMP/snmp.o ./ioLibrary_Driver/Internet/SNMP/snmp.su ./ioLibrary_Driver/Internet/SNMP/snmp_custom.cyclo ./ioLibrary_Driver/Internet/SNMP/snmp_custom.d ./ioLibrary_Driver/Internet/SNMP/snmp_custom.o ./ioLibrary_Driver/Internet/SNMP/snmp_custom.su

.PHONY: clean-ioLibrary_Driver-2f-Internet-2f-SNMP

