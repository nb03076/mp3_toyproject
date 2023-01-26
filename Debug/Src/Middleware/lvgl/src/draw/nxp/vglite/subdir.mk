################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.c \
../Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.c \
../Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.c \
../Src/Middleware/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.c 

OBJS += \
./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o \
./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o \
./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o \
./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.o 

C_DEPS += \
./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d \
./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d \
./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d \
./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/draw/nxp/vglite/%.o Src/Middleware/lvgl/src/draw/nxp/vglite/%.su: ../Src/Middleware/lvgl/src/draw/nxp/vglite/%.c Src/Middleware/lvgl/src/draw/nxp/vglite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/lvgl" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite:
	-$(RM) ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.su ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.su ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.su ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.d ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.o ./Src/Middleware/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

