################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.c \
../Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c 

OBJS += \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.o \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.o 

C_DEPS += \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.d \
./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/STM32F4xx_HAL_Driver/Src/%.o Src/HAL/STM32F4xx_HAL_Driver/Src/%.su: ../Src/HAL/STM32F4xx_HAL_Driver/Src/%.c Src/HAL/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/Middleware/u8g2" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-STM32F4xx_HAL_Driver-2f-Src

clean-Src-2f-HAL-2f-STM32F4xx_HAL_Driver-2f-Src:
	-$(RM) ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.su ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.d ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.o ./Src/HAL/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.su

.PHONY: clean-Src-2f-HAL-2f-STM32F4xx_HAL_Driver-2f-Src

