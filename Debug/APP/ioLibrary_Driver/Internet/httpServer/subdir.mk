################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/ioLibrary_Driver/Internet/httpServer/httpParser.c \
../APP/ioLibrary_Driver/Internet/httpServer/httpServer.c \
../APP/ioLibrary_Driver/Internet/httpServer/httpUtil.c 

OBJS += \
./APP/ioLibrary_Driver/Internet/httpServer/httpParser.o \
./APP/ioLibrary_Driver/Internet/httpServer/httpServer.o \
./APP/ioLibrary_Driver/Internet/httpServer/httpUtil.o 

C_DEPS += \
./APP/ioLibrary_Driver/Internet/httpServer/httpParser.d \
./APP/ioLibrary_Driver/Internet/httpServer/httpServer.d \
./APP/ioLibrary_Driver/Internet/httpServer/httpUtil.d 


# Each subdirectory must supply rules for building sources it contributes
APP/ioLibrary_Driver/Internet/httpServer/%.o APP/ioLibrary_Driver/Internet/httpServer/%.su APP/ioLibrary_Driver/Internet/httpServer/%.cyclo: ../APP/ioLibrary_Driver/Internet/httpServer/%.c APP/ioLibrary_Driver/Internet/httpServer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/include" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/src" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Internet" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Ethernet" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Application" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Internet/MQTT" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Ethernet/W5500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-httpServer

clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-httpServer:
	-$(RM) ./APP/ioLibrary_Driver/Internet/httpServer/httpParser.cyclo ./APP/ioLibrary_Driver/Internet/httpServer/httpParser.d ./APP/ioLibrary_Driver/Internet/httpServer/httpParser.o ./APP/ioLibrary_Driver/Internet/httpServer/httpParser.su ./APP/ioLibrary_Driver/Internet/httpServer/httpServer.cyclo ./APP/ioLibrary_Driver/Internet/httpServer/httpServer.d ./APP/ioLibrary_Driver/Internet/httpServer/httpServer.o ./APP/ioLibrary_Driver/Internet/httpServer/httpServer.su ./APP/ioLibrary_Driver/Internet/httpServer/httpUtil.cyclo ./APP/ioLibrary_Driver/Internet/httpServer/httpUtil.d ./APP/ioLibrary_Driver/Internet/httpServer/httpUtil.o ./APP/ioLibrary_Driver/Internet/httpServer/httpUtil.su

.PHONY: clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-httpServer

