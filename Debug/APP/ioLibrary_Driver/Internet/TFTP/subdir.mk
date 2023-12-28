################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/ioLibrary_Driver/Internet/TFTP/netutil.c \
../APP/ioLibrary_Driver/Internet/TFTP/tftp.c 

OBJS += \
./APP/ioLibrary_Driver/Internet/TFTP/netutil.o \
./APP/ioLibrary_Driver/Internet/TFTP/tftp.o 

C_DEPS += \
./APP/ioLibrary_Driver/Internet/TFTP/netutil.d \
./APP/ioLibrary_Driver/Internet/TFTP/tftp.d 


# Each subdirectory must supply rules for building sources it contributes
APP/ioLibrary_Driver/Internet/TFTP/%.o APP/ioLibrary_Driver/Internet/TFTP/%.su APP/ioLibrary_Driver/Internet/TFTP/%.cyclo: ../APP/ioLibrary_Driver/Internet/TFTP/%.c APP/ioLibrary_Driver/Internet/TFTP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/include" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/src" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Internet" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Ethernet" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Application" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Internet/MQTT" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Ethernet/W5500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-TFTP

clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-TFTP:
	-$(RM) ./APP/ioLibrary_Driver/Internet/TFTP/netutil.cyclo ./APP/ioLibrary_Driver/Internet/TFTP/netutil.d ./APP/ioLibrary_Driver/Internet/TFTP/netutil.o ./APP/ioLibrary_Driver/Internet/TFTP/netutil.su ./APP/ioLibrary_Driver/Internet/TFTP/tftp.cyclo ./APP/ioLibrary_Driver/Internet/TFTP/tftp.d ./APP/ioLibrary_Driver/Internet/TFTP/tftp.o ./APP/ioLibrary_Driver/Internet/TFTP/tftp.su

.PHONY: clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-TFTP
