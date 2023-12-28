################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTFormat.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTPacket.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.c \
../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.c 

OBJS += \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTFormat.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTPacket.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.o \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.o 

C_DEPS += \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTFormat.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTPacket.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.d \
./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.d 


# Each subdirectory must supply rules for building sources it contributes
APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/%.o APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/%.su APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/%.cyclo: ../APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/%.c APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/include" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/src" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Internet" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Ethernet" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Application" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Internet/MQTT" -I"C:/Users/alren/STM32CubeIDE/workspace_1.13.2/GWA100_Firmware/APP/ioLibrary_Driver/Ethernet/W5500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-MQTT-2f-MQTTPacket-2f-src

clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-MQTT-2f-MQTTPacket-2f-src:
	-$(RM) ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTFormat.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTFormat.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTFormat.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTFormat.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTPacket.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTPacket.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTPacket.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTPacket.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.su ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.cyclo ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.d ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.o ./APP/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.su

.PHONY: clean-APP-2f-ioLibrary_Driver-2f-Internet-2f-MQTT-2f-MQTTPacket-2f-src

