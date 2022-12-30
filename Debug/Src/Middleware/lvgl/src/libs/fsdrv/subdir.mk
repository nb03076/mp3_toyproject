################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_cbfs.c \
../Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_fatfs.c \
../Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_posix.c \
../Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_stdio.c \
../Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_cbfs.o \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_fatfs.o \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_posix.o \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_stdio.o \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_cbfs.d \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_fatfs.d \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_posix.d \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_stdio.d \
./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/lvgl/src/libs/fsdrv/%.o Src/Middleware/lvgl/src/libs/fsdrv/%.su: ../Src/Middleware/lvgl/src/libs/fsdrv/%.c Src/Middleware/lvgl/src/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32F429xx -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/kang/stm_workspace/ll_mp3_project/conf" -I"/home/kang/stm_workspace/ll_mp3_project/Src/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/core" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Drivers" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-libs-2f-fsdrv

clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-libs-2f-fsdrv:
	-$(RM) ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_cbfs.d ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_cbfs.o ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_cbfs.su ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_fatfs.d ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_fatfs.o ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_fatfs.su ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_posix.d ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_posix.o ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_posix.su ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_stdio.d ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_stdio.o ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_stdio.su ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_win32.d ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_win32.o ./Src/Middleware/lvgl/src/libs/fsdrv/lv_fs_win32.su

.PHONY: clean-Src-2f-Middleware-2f-lvgl-2f-src-2f-libs-2f-fsdrv

