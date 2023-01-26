################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/misc/lv_anim.c \
../Src/Middleware/lvgl/src/misc/lv_anim_timeline.c \
../Src/Middleware/lvgl/src/misc/lv_area.c \
../Src/Middleware/lvgl/src/misc/lv_async.c \
../Src/Middleware/lvgl/src/misc/lv_bidi.c \
../Src/Middleware/lvgl/src/misc/lv_color.c \
../Src/Middleware/lvgl/src/misc/lv_fs.c \
../Src/Middleware/lvgl/src/misc/lv_gc.c \
../Src/Middleware/lvgl/src/misc/lv_ll.c \
../Src/Middleware/lvgl/src/misc/lv_log.c \
../Src/Middleware/lvgl/src/misc/lv_lru.c \
../Src/Middleware/lvgl/src/misc/lv_malloc_builtin.c \
../Src/Middleware/lvgl/src/misc/lv_math.c \
../Src/Middleware/lvgl/src/misc/lv_mem.c \
../Src/Middleware/lvgl/src/misc/lv_memcpy_builtin.c \
../Src/Middleware/lvgl/src/misc/lv_printf.c \
../Src/Middleware/lvgl/src/misc/lv_style.c \
../Src/Middleware/lvgl/src/misc/lv_style_gen.c \
../Src/Middleware/lvgl/src/misc/lv_templ.c \
../Src/Middleware/lvgl/src/misc/lv_timer.c \
../Src/Middleware/lvgl/src/misc/lv_tlsf.c \
../Src/Middleware/lvgl/src/misc/lv_txt.c \
../Src/Middleware/lvgl/src/misc/lv_txt_ap.c \
../Src/Middleware/lvgl/src/misc/lv_utils.c 

OBJS += \
./Src/Middleware/lvgl/src/misc/lv_anim.o \
./Src/Middleware/lvgl/src/misc/lv_anim_timeline.o \
./Src/Middleware/lvgl/src/misc/lv_area.o \
./Src/Middleware/lvgl/src/misc/lv_async.o \
./Src/Middleware/lvgl/src/misc/lv_bidi.o \
./Src/Middleware/lvgl/src/misc/lv_color.o \
./Src/Middleware/lvgl/src/misc/lv_fs.o \
./Src/Middleware/lvgl/src/misc/lv_gc.o \
./Src/Middleware/lvgl/src/misc/lv_ll.o \
./Src/Middleware/lvgl/src/misc/lv_log.o \
./Src/Middleware/lvgl/src/misc/lv_lru.o \
./Src/Middleware/lvgl/src/misc/lv_malloc_builtin.o \
./Src/Middleware/lvgl/src/misc/lv_math.o \
./Src/Middleware/lvgl/src/misc/lv_mem.o \
./Src/Middleware/lvgl/src/misc/lv_memcpy_builtin.o \
./Src/Middleware/lvgl/src/misc/lv_printf.o \
./Src/Middleware/lvgl/src/misc/lv_style.o \
./Src/Middleware/lvgl/src/misc/lv_style_gen.o \
./Src/Middleware/lvgl/src/misc/lv_templ.o \
./Src/Middleware/lvgl/src/misc/lv_timer.o \
./Src/Middleware/lvgl/src/misc/lv_tlsf.o \
./Src/Middleware/lvgl/src/misc/lv_txt.o \
./Src/Middleware/lvgl/src/misc/lv_txt_ap.o \
./Src/Middleware/lvgl/src/misc/lv_utils.o 

C_DEPS += \
./Src/Middleware/lvgl/src/misc/lv_anim.d \
./Src/Middleware/lvgl/src/misc/lv_anim_timeline.d \
./Src/Middleware/lvgl/src/misc/lv_area.d \
./Src/Middleware/lvgl/src/misc/lv_async.d \
./Src/Middleware/lvgl/src/misc/lv_bidi.d \
./Src/Middleware/lvgl/src/misc/lv_color.d \
./Src/Middleware/lvgl/src/misc/lv_fs.d \
./Src/Middleware/lvgl/src/misc/lv_gc.d \
./Src/Middleware/lvgl/src/misc/lv_ll.d \
./Src/Middleware/lvgl/src/misc/lv_log.d \
./Src/Middleware/lvgl/src/misc/lv_lru.d \
./Src/Middleware/lvgl/src/misc/lv_malloc_builtin.d \
./Src/Middleware/lvgl/src/misc/lv_math.d \
./Src/Middleware/lvgl/src/misc/lv_mem.d \
./Src/Middleware/lvgl/src/misc/lv_memcpy_builtin.d \
./Src/Middleware/lvgl/src/misc/lv_printf.d \
./Src/Middleware/lvgl/src/misc/lv_style.d \
./Src/Middleware/lvgl/src/misc/lv_style_gen.d \
./Src/Middleware/lvgl/src/misc/lv_templ.d \
./Src/Middleware/lvgl/src/misc/lv_timer.d \
./Src/Middleware/lvgl/src/misc/lv_tlsf.d \
./Src/Middleware/lvgl/src/misc/lv_txt.d \
./Src/Middleware/lvgl/src/misc/lv_txt_ap.d \
./Src/Middleware/lvgl/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/misc/%.o Src/Middleware/lvgl/src/misc/%.su: ../Src/Middleware/lvgl/src/misc/%.c Src/Middleware/lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/lvgl" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-misc

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./Src/Middleware/lvgl/src/misc/lv_anim.d ./Src/Middleware/lvgl/src/misc/lv_anim.o ./Src/Middleware/lvgl/src/misc/lv_anim.su ./Src/Middleware/lvgl/src/misc/lv_anim_timeline.d ./Src/Middleware/lvgl/src/misc/lv_anim_timeline.o ./Src/Middleware/lvgl/src/misc/lv_anim_timeline.su ./Src/Middleware/lvgl/src/misc/lv_area.d ./Src/Middleware/lvgl/src/misc/lv_area.o ./Src/Middleware/lvgl/src/misc/lv_area.su ./Src/Middleware/lvgl/src/misc/lv_async.d ./Src/Middleware/lvgl/src/misc/lv_async.o ./Src/Middleware/lvgl/src/misc/lv_async.su ./Src/Middleware/lvgl/src/misc/lv_bidi.d ./Src/Middleware/lvgl/src/misc/lv_bidi.o ./Src/Middleware/lvgl/src/misc/lv_bidi.su ./Src/Middleware/lvgl/src/misc/lv_color.d ./Src/Middleware/lvgl/src/misc/lv_color.o ./Src/Middleware/lvgl/src/misc/lv_color.su ./Src/Middleware/lvgl/src/misc/lv_fs.d ./Src/Middleware/lvgl/src/misc/lv_fs.o ./Src/Middleware/lvgl/src/misc/lv_fs.su ./Src/Middleware/lvgl/src/misc/lv_gc.d ./Src/Middleware/lvgl/src/misc/lv_gc.o ./Src/Middleware/lvgl/src/misc/lv_gc.su ./Src/Middleware/lvgl/src/misc/lv_ll.d ./Src/Middleware/lvgl/src/misc/lv_ll.o ./Src/Middleware/lvgl/src/misc/lv_ll.su ./Src/Middleware/lvgl/src/misc/lv_log.d ./Src/Middleware/lvgl/src/misc/lv_log.o ./Src/Middleware/lvgl/src/misc/lv_log.su ./Src/Middleware/lvgl/src/misc/lv_lru.d ./Src/Middleware/lvgl/src/misc/lv_lru.o ./Src/Middleware/lvgl/src/misc/lv_lru.su ./Src/Middleware/lvgl/src/misc/lv_malloc_builtin.d ./Src/Middleware/lvgl/src/misc/lv_malloc_builtin.o ./Src/Middleware/lvgl/src/misc/lv_malloc_builtin.su ./Src/Middleware/lvgl/src/misc/lv_math.d ./Src/Middleware/lvgl/src/misc/lv_math.o ./Src/Middleware/lvgl/src/misc/lv_math.su ./Src/Middleware/lvgl/src/misc/lv_mem.d ./Src/Middleware/lvgl/src/misc/lv_mem.o ./Src/Middleware/lvgl/src/misc/lv_mem.su ./Src/Middleware/lvgl/src/misc/lv_memcpy_builtin.d ./Src/Middleware/lvgl/src/misc/lv_memcpy_builtin.o ./Src/Middleware/lvgl/src/misc/lv_memcpy_builtin.su ./Src/Middleware/lvgl/src/misc/lv_printf.d ./Src/Middleware/lvgl/src/misc/lv_printf.o ./Src/Middleware/lvgl/src/misc/lv_printf.su ./Src/Middleware/lvgl/src/misc/lv_style.d ./Src/Middleware/lvgl/src/misc/lv_style.o ./Src/Middleware/lvgl/src/misc/lv_style.su ./Src/Middleware/lvgl/src/misc/lv_style_gen.d ./Src/Middleware/lvgl/src/misc/lv_style_gen.o ./Src/Middleware/lvgl/src/misc/lv_style_gen.su ./Src/Middleware/lvgl/src/misc/lv_templ.d ./Src/Middleware/lvgl/src/misc/lv_templ.o ./Src/Middleware/lvgl/src/misc/lv_templ.su ./Src/Middleware/lvgl/src/misc/lv_timer.d ./Src/Middleware/lvgl/src/misc/lv_timer.o ./Src/Middleware/lvgl/src/misc/lv_timer.su ./Src/Middleware/lvgl/src/misc/lv_tlsf.d ./Src/Middleware/lvgl/src/misc/lv_tlsf.o ./Src/Middleware/lvgl/src/misc/lv_tlsf.su ./Src/Middleware/lvgl/src/misc/lv_txt.d ./Src/Middleware/lvgl/src/misc/lv_txt.o ./Src/Middleware/lvgl/src/misc/lv_txt.su ./Src/Middleware/lvgl/src/misc/lv_txt_ap.d ./Src/Middleware/lvgl/src/misc/lv_txt_ap.o ./Src/Middleware/lvgl/src/misc/lv_txt_ap.su ./Src/Middleware/lvgl/src/misc/lv_utils.d ./Src/Middleware/lvgl/src/misc/lv_utils.o ./Src/Middleware/lvgl/src/misc/lv_utils.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-misc

