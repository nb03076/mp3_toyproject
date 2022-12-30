################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/widgets/btnmatrix/lv_btnmatrix.c 

OBJS += \
./Src/Middleware/lvgl/src/widgets/btnmatrix/lv_btnmatrix.o 

C_DEPS += \
./Src/Middleware/lvgl/src/widgets/btnmatrix/lv_btnmatrix.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/widgets/btnmatrix/%.o Src/Middleware/lvgl/src/widgets/btnmatrix/%.su: ../Src/Middleware/lvgl/src/widgets/btnmatrix/%.c Src/Middleware/lvgl/src/widgets/btnmatrix/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32F429xx -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/kang/stm_workspace/ll_mp3_project/conf" -I"/home/kang/stm_workspace/ll_mp3_project/Src/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/core" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Drivers" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-widgets-2f-btnmatrix

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-widgets-2f-btnmatrix:
	-$(RM) ./Src/Middleware/lvgl/src/widgets/btnmatrix/lv_btnmatrix.d ./Src/Middleware/lvgl/src/widgets/btnmatrix/lv_btnmatrix.o ./Src/Middleware/lvgl/src/widgets/btnmatrix/lv_btnmatrix.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-widgets-2f-btnmatrix

