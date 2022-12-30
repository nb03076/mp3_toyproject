################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/core/lv_disp.c \
../Src/Middleware/lvgl/src/core/lv_event.c \
../Src/Middleware/lvgl/src/core/lv_group.c \
../Src/Middleware/lvgl/src/core/lv_indev.c \
../Src/Middleware/lvgl/src/core/lv_indev_scroll.c \
../Src/Middleware/lvgl/src/core/lv_obj.c \
../Src/Middleware/lvgl/src/core/lv_obj_class.c \
../Src/Middleware/lvgl/src/core/lv_obj_draw.c \
../Src/Middleware/lvgl/src/core/lv_obj_pos.c \
../Src/Middleware/lvgl/src/core/lv_obj_scroll.c \
../Src/Middleware/lvgl/src/core/lv_obj_style.c \
../Src/Middleware/lvgl/src/core/lv_obj_style_gen.c \
../Src/Middleware/lvgl/src/core/lv_obj_tree.c \
../Src/Middleware/lvgl/src/core/lv_refr.c \
../Src/Middleware/lvgl/src/core/lv_theme.c 

OBJS += \
./Src/Middleware/lvgl/src/core/lv_disp.o \
./Src/Middleware/lvgl/src/core/lv_event.o \
./Src/Middleware/lvgl/src/core/lv_group.o \
./Src/Middleware/lvgl/src/core/lv_indev.o \
./Src/Middleware/lvgl/src/core/lv_indev_scroll.o \
./Src/Middleware/lvgl/src/core/lv_obj.o \
./Src/Middleware/lvgl/src/core/lv_obj_class.o \
./Src/Middleware/lvgl/src/core/lv_obj_draw.o \
./Src/Middleware/lvgl/src/core/lv_obj_pos.o \
./Src/Middleware/lvgl/src/core/lv_obj_scroll.o \
./Src/Middleware/lvgl/src/core/lv_obj_style.o \
./Src/Middleware/lvgl/src/core/lv_obj_style_gen.o \
./Src/Middleware/lvgl/src/core/lv_obj_tree.o \
./Src/Middleware/lvgl/src/core/lv_refr.o \
./Src/Middleware/lvgl/src/core/lv_theme.o 

C_DEPS += \
./Src/Middleware/lvgl/src/core/lv_disp.d \
./Src/Middleware/lvgl/src/core/lv_event.d \
./Src/Middleware/lvgl/src/core/lv_group.d \
./Src/Middleware/lvgl/src/core/lv_indev.d \
./Src/Middleware/lvgl/src/core/lv_indev_scroll.d \
./Src/Middleware/lvgl/src/core/lv_obj.d \
./Src/Middleware/lvgl/src/core/lv_obj_class.d \
./Src/Middleware/lvgl/src/core/lv_obj_draw.d \
./Src/Middleware/lvgl/src/core/lv_obj_pos.d \
./Src/Middleware/lvgl/src/core/lv_obj_scroll.d \
./Src/Middleware/lvgl/src/core/lv_obj_style.d \
./Src/Middleware/lvgl/src/core/lv_obj_style_gen.d \
./Src/Middleware/lvgl/src/core/lv_obj_tree.d \
./Src/Middleware/lvgl/src/core/lv_refr.d \
./Src/Middleware/lvgl/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/core/%.o Src/Middleware/lvgl/src/core/%.su: ../Src/Middleware/lvgl/src/core/%.c Src/Middleware/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32F429xx -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/kang/stm_workspace/ll_mp3_project/conf" -I"/home/kang/stm_workspace/ll_mp3_project/Src/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/core" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Drivers" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-core

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-core:
	-$(RM) ./Src/Middleware/lvgl/src/core/lv_disp.d ./Src/Middleware/lvgl/src/core/lv_disp.o ./Src/Middleware/lvgl/src/core/lv_disp.su ./Src/Middleware/lvgl/src/core/lv_event.d ./Src/Middleware/lvgl/src/core/lv_event.o ./Src/Middleware/lvgl/src/core/lv_event.su ./Src/Middleware/lvgl/src/core/lv_group.d ./Src/Middleware/lvgl/src/core/lv_group.o ./Src/Middleware/lvgl/src/core/lv_group.su ./Src/Middleware/lvgl/src/core/lv_indev.d ./Src/Middleware/lvgl/src/core/lv_indev.o ./Src/Middleware/lvgl/src/core/lv_indev.su ./Src/Middleware/lvgl/src/core/lv_indev_scroll.d ./Src/Middleware/lvgl/src/core/lv_indev_scroll.o ./Src/Middleware/lvgl/src/core/lv_indev_scroll.su ./Src/Middleware/lvgl/src/core/lv_obj.d ./Src/Middleware/lvgl/src/core/lv_obj.o ./Src/Middleware/lvgl/src/core/lv_obj.su ./Src/Middleware/lvgl/src/core/lv_obj_class.d ./Src/Middleware/lvgl/src/core/lv_obj_class.o ./Src/Middleware/lvgl/src/core/lv_obj_class.su ./Src/Middleware/lvgl/src/core/lv_obj_draw.d ./Src/Middleware/lvgl/src/core/lv_obj_draw.o ./Src/Middleware/lvgl/src/core/lv_obj_draw.su ./Src/Middleware/lvgl/src/core/lv_obj_pos.d ./Src/Middleware/lvgl/src/core/lv_obj_pos.o ./Src/Middleware/lvgl/src/core/lv_obj_pos.su ./Src/Middleware/lvgl/src/core/lv_obj_scroll.d ./Src/Middleware/lvgl/src/core/lv_obj_scroll.o ./Src/Middleware/lvgl/src/core/lv_obj_scroll.su ./Src/Middleware/lvgl/src/core/lv_obj_style.d ./Src/Middleware/lvgl/src/core/lv_obj_style.o ./Src/Middleware/lvgl/src/core/lv_obj_style.su ./Src/Middleware/lvgl/src/core/lv_obj_style_gen.d ./Src/Middleware/lvgl/src/core/lv_obj_style_gen.o ./Src/Middleware/lvgl/src/core/lv_obj_style_gen.su ./Src/Middleware/lvgl/src/core/lv_obj_tree.d ./Src/Middleware/lvgl/src/core/lv_obj_tree.o ./Src/Middleware/lvgl/src/core/lv_obj_tree.su ./Src/Middleware/lvgl/src/core/lv_refr.d ./Src/Middleware/lvgl/src/core/lv_refr.o ./Src/Middleware/lvgl/src/core/lv_refr.su ./Src/Middleware/lvgl/src/core/lv_theme.d ./Src/Middleware/lvgl/src/core/lv_theme.o ./Src/Middleware/lvgl/src/core/lv_theme.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-core

