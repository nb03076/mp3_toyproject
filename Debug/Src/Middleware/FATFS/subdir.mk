################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/FATFS/bsp_driver_sd.c \
../Src/Middleware/FATFS/ccsbcs.c \
../Src/Middleware/FATFS/diskio.c \
../Src/Middleware/FATFS/fatfs.c \
../Src/Middleware/FATFS/ff.c \
../Src/Middleware/FATFS/ff_gen_drv.c \
../Src/Middleware/FATFS/sd_diskio.c 

OBJS += \
./Src/Middleware/FATFS/bsp_driver_sd.o \
./Src/Middleware/FATFS/ccsbcs.o \
./Src/Middleware/FATFS/diskio.o \
./Src/Middleware/FATFS/fatfs.o \
./Src/Middleware/FATFS/ff.o \
./Src/Middleware/FATFS/ff_gen_drv.o \
./Src/Middleware/FATFS/sd_diskio.o 

C_DEPS += \
./Src/Middleware/FATFS/bsp_driver_sd.d \
./Src/Middleware/FATFS/ccsbcs.d \
./Src/Middleware/FATFS/diskio.d \
./Src/Middleware/FATFS/fatfs.d \
./Src/Middleware/FATFS/ff.d \
./Src/Middleware/FATFS/ff_gen_drv.d \
./Src/Middleware/FATFS/sd_diskio.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/FATFS/%.o Src/Middleware/FATFS/%.su: ../Src/Middleware/FATFS/%.c Src/Middleware/FATFS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32F429xx -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/kang/stm_workspace/ll_mp3_project/conf" -I"/home/kang/stm_workspace/ll_mp3_project/Src/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/core" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Drivers" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-FATFS

clean-Src-2f-Middleware-2f-FATFS:
	-$(RM) ./Src/Middleware/FATFS/bsp_driver_sd.d ./Src/Middleware/FATFS/bsp_driver_sd.o ./Src/Middleware/FATFS/bsp_driver_sd.su ./Src/Middleware/FATFS/ccsbcs.d ./Src/Middleware/FATFS/ccsbcs.o ./Src/Middleware/FATFS/ccsbcs.su ./Src/Middleware/FATFS/diskio.d ./Src/Middleware/FATFS/diskio.o ./Src/Middleware/FATFS/diskio.su ./Src/Middleware/FATFS/fatfs.d ./Src/Middleware/FATFS/fatfs.o ./Src/Middleware/FATFS/fatfs.su ./Src/Middleware/FATFS/ff.d ./Src/Middleware/FATFS/ff.o ./Src/Middleware/FATFS/ff.su ./Src/Middleware/FATFS/ff_gen_drv.d ./Src/Middleware/FATFS/ff_gen_drv.o ./Src/Middleware/FATFS/ff_gen_drv.su ./Src/Middleware/FATFS/sd_diskio.d ./Src/Middleware/FATFS/sd_diskio.o ./Src/Middleware/FATFS/sd_diskio.su

.PHONY: clean-Src-2f-Middleware-2f-FATFS

