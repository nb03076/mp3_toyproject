################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/draw/arm2d/lv_gpu_arm2d.c 

OBJS += \
./Src/Middleware/lvgl/src/draw/arm2d/lv_gpu_arm2d.o 

C_DEPS += \
./Src/Middleware/lvgl/src/draw/arm2d/lv_gpu_arm2d.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/draw/arm2d/%.o Src/Middleware/lvgl/src/draw/arm2d/%.su: ../Src/Middleware/lvgl/src/draw/arm2d/%.c Src/Middleware/lvgl/src/draw/arm2d/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/lvgl" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-arm2d

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-arm2d:
	-$(RM) ./Src/Middleware/lvgl/src/draw/arm2d/lv_gpu_arm2d.d ./Src/Middleware/lvgl/src/draw/arm2d/lv_gpu_arm2d.o ./Src/Middleware/lvgl/src/draw/arm2d/lv_gpu_arm2d.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-arm2d
