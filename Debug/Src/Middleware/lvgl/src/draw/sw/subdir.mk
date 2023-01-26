################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_blend.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_dither.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_img.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_layer.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_line.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_polygon.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_rect.c \
../Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_transform.c 

OBJS += \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_blend.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_dither.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_img.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_layer.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_line.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_polygon.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_rect.o \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_transform.o 

C_DEPS += \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_blend.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_dither.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_img.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_layer.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_line.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_polygon.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_rect.d \
./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_transform.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/draw/sw/%.o Src/Middleware/lvgl/src/draw/sw/%.su: ../Src/Middleware/lvgl/src/draw/sw/%.c Src/Middleware/lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/lvgl" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-sw

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_arc.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_arc.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_arc.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_blend.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_blend.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_blend.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_dither.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_dither.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_dither.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_gradient.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_img.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_img.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_img.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_layer.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_layer.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_layer.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_letter.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_letter.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_letter.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_line.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_line.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_line.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_polygon.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_polygon.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_polygon.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_rect.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_rect.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_rect.su ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_transform.d ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_transform.o ./Src/Middleware/lvgl/src/draw/sw/lv_draw_sw_transform.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-sw

