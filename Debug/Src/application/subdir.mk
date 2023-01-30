################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/application/display_app.c \
../Src/application/input_app.c \
../Src/application/mp3_app.c \
../Src/application/mp3_player.c 

OBJS += \
./Src/application/display_app.o \
./Src/application/input_app.o \
./Src/application/mp3_app.o \
./Src/application/mp3_player.o 

C_DEPS += \
./Src/application/display_app.d \
./Src/application/input_app.d \
./Src/application/mp3_app.d \
./Src/application/mp3_player.d 


# Each subdirectory must supply rules for building sources it contributes
Src/application/%.o Src/application/%.su: ../Src/application/%.c Src/application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/application/event" -I"/home/kang/space/ll_mp3_project/Src/application" -I"/home/kang/space/ll_mp3_project/Src/Middleware/u8g2" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-application

clean-Src-2f-application:
	-$(RM) ./Src/application/display_app.d ./Src/application/display_app.o ./Src/application/display_app.su ./Src/application/input_app.d ./Src/application/input_app.o ./Src/application/input_app.su ./Src/application/mp3_app.d ./Src/application/mp3_app.o ./Src/application/mp3_app.su ./Src/application/mp3_player.d ./Src/application/mp3_player.o ./Src/application/mp3_player.su

.PHONY: clean-Src-2f-application

