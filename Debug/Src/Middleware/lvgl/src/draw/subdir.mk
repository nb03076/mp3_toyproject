################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/draw/lv_draw.c \
../Src/Middleware/lvgl/src/draw/lv_draw_arc.c \
../Src/Middleware/lvgl/src/draw/lv_draw_img.c \
../Src/Middleware/lvgl/src/draw/lv_draw_label.c \
../Src/Middleware/lvgl/src/draw/lv_draw_layer.c \
../Src/Middleware/lvgl/src/draw/lv_draw_line.c \
../Src/Middleware/lvgl/src/draw/lv_draw_mask.c \
../Src/Middleware/lvgl/src/draw/lv_draw_rect.c \
../Src/Middleware/lvgl/src/draw/lv_draw_transform.c \
../Src/Middleware/lvgl/src/draw/lv_draw_triangle.c \
../Src/Middleware/lvgl/src/draw/lv_img_buf.c \
../Src/Middleware/lvgl/src/draw/lv_img_cache.c \
../Src/Middleware/lvgl/src/draw/lv_img_decoder.c 

OBJS += \
./Src/Middleware/lvgl/src/draw/lv_draw.o \
./Src/Middleware/lvgl/src/draw/lv_draw_arc.o \
./Src/Middleware/lvgl/src/draw/lv_draw_img.o \
./Src/Middleware/lvgl/src/draw/lv_draw_label.o \
./Src/Middleware/lvgl/src/draw/lv_draw_layer.o \
./Src/Middleware/lvgl/src/draw/lv_draw_line.o \
./Src/Middleware/lvgl/src/draw/lv_draw_mask.o \
./Src/Middleware/lvgl/src/draw/lv_draw_rect.o \
./Src/Middleware/lvgl/src/draw/lv_draw_transform.o \
./Src/Middleware/lvgl/src/draw/lv_draw_triangle.o \
./Src/Middleware/lvgl/src/draw/lv_img_buf.o \
./Src/Middleware/lvgl/src/draw/lv_img_cache.o \
./Src/Middleware/lvgl/src/draw/lv_img_decoder.o 

C_DEPS += \
./Src/Middleware/lvgl/src/draw/lv_draw.d \
./Src/Middleware/lvgl/src/draw/lv_draw_arc.d \
./Src/Middleware/lvgl/src/draw/lv_draw_img.d \
./Src/Middleware/lvgl/src/draw/lv_draw_label.d \
./Src/Middleware/lvgl/src/draw/lv_draw_layer.d \
./Src/Middleware/lvgl/src/draw/lv_draw_line.d \
./Src/Middleware/lvgl/src/draw/lv_draw_mask.d \
./Src/Middleware/lvgl/src/draw/lv_draw_rect.d \
./Src/Middleware/lvgl/src/draw/lv_draw_transform.d \
./Src/Middleware/lvgl/src/draw/lv_draw_triangle.d \
./Src/Middleware/lvgl/src/draw/lv_img_buf.d \
./Src/Middleware/lvgl/src/draw/lv_img_cache.d \
./Src/Middleware/lvgl/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/draw/%.o Src/Middleware/lvgl/src/draw/%.su: ../Src/Middleware/lvgl/src/draw/%.c Src/Middleware/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32F429xx -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/kang/stm_workspace/ll_mp3_project/conf" -I"/home/kang/stm_workspace/ll_mp3_project/Src/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/core" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Drivers" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./Src/Middleware/lvgl/src/draw/lv_draw.d ./Src/Middleware/lvgl/src/draw/lv_draw.o ./Src/Middleware/lvgl/src/draw/lv_draw.su ./Src/Middleware/lvgl/src/draw/lv_draw_arc.d ./Src/Middleware/lvgl/src/draw/lv_draw_arc.o ./Src/Middleware/lvgl/src/draw/lv_draw_arc.su ./Src/Middleware/lvgl/src/draw/lv_draw_img.d ./Src/Middleware/lvgl/src/draw/lv_draw_img.o ./Src/Middleware/lvgl/src/draw/lv_draw_img.su ./Src/Middleware/lvgl/src/draw/lv_draw_label.d ./Src/Middleware/lvgl/src/draw/lv_draw_label.o ./Src/Middleware/lvgl/src/draw/lv_draw_label.su ./Src/Middleware/lvgl/src/draw/lv_draw_layer.d ./Src/Middleware/lvgl/src/draw/lv_draw_layer.o ./Src/Middleware/lvgl/src/draw/lv_draw_layer.su ./Src/Middleware/lvgl/src/draw/lv_draw_line.d ./Src/Middleware/lvgl/src/draw/lv_draw_line.o ./Src/Middleware/lvgl/src/draw/lv_draw_line.su ./Src/Middleware/lvgl/src/draw/lv_draw_mask.d ./Src/Middleware/lvgl/src/draw/lv_draw_mask.o ./Src/Middleware/lvgl/src/draw/lv_draw_mask.su ./Src/Middleware/lvgl/src/draw/lv_draw_rect.d ./Src/Middleware/lvgl/src/draw/lv_draw_rect.o ./Src/Middleware/lvgl/src/draw/lv_draw_rect.su ./Src/Middleware/lvgl/src/draw/lv_draw_transform.d ./Src/Middleware/lvgl/src/draw/lv_draw_transform.o ./Src/Middleware/lvgl/src/draw/lv_draw_transform.su ./Src/Middleware/lvgl/src/draw/lv_draw_triangle.d ./Src/Middleware/lvgl/src/draw/lv_draw_triangle.o ./Src/Middleware/lvgl/src/draw/lv_draw_triangle.su ./Src/Middleware/lvgl/src/draw/lv_img_buf.d ./Src/Middleware/lvgl/src/draw/lv_img_buf.o ./Src/Middleware/lvgl/src/draw/lv_img_buf.su ./Src/Middleware/lvgl/src/draw/lv_img_cache.d ./Src/Middleware/lvgl/src/draw/lv_img_cache.o ./Src/Middleware/lvgl/src/draw/lv_img_cache.su ./Src/Middleware/lvgl/src/draw/lv_img_decoder.d ./Src/Middleware/lvgl/src/draw/lv_img_decoder.o ./Src/Middleware/lvgl/src/draw/lv_img_decoder.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw

