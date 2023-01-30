################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Drivers/ds3231.c \
../Src/Drivers/icon.c \
../Src/Drivers/ssd1306_theme.c \
../Src/Drivers/u8g2_stm.c \
../Src/Drivers/vs1053.c 

OBJS += \
./Src/Drivers/ds3231.o \
./Src/Drivers/icon.o \
./Src/Drivers/ssd1306_theme.o \
./Src/Drivers/u8g2_stm.o \
./Src/Drivers/vs1053.o 

C_DEPS += \
./Src/Drivers/ds3231.d \
./Src/Drivers/icon.d \
./Src/Drivers/ssd1306_theme.d \
./Src/Drivers/u8g2_stm.d \
./Src/Drivers/vs1053.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Drivers/%.o Src/Drivers/%.su: ../Src/Drivers/%.c Src/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/application/event" -I"/home/kang/space/ll_mp3_project/Src/application" -I"/home/kang/space/ll_mp3_project/Src/Middleware/u8g2" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Drivers

clean-Src-2f-Drivers:
	-$(RM) ./Src/Drivers/ds3231.d ./Src/Drivers/ds3231.o ./Src/Drivers/ds3231.su ./Src/Drivers/icon.d ./Src/Drivers/icon.o ./Src/Drivers/icon.su ./Src/Drivers/ssd1306_theme.d ./Src/Drivers/ssd1306_theme.o ./Src/Drivers/ssd1306_theme.su ./Src/Drivers/u8g2_stm.d ./Src/Drivers/u8g2_stm.o ./Src/Drivers/u8g2_stm.su ./Src/Drivers/vs1053.d ./Src/Drivers/vs1053.o ./Src/Drivers/vs1053.su

.PHONY: clean-Src-2f-Drivers

