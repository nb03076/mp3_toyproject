################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_layer.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_layer.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_layer.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/draw/sdl/%.o Src/Middleware/lvgl/src/draw/sdl/%.su: ../Src/Middleware/lvgl/src/draw/sdl/%.c Src/Middleware/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/lvgl" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_layer.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_layer.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_layer.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./Src/Middleware/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-sdl

