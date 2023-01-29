################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/FreeRTOS-Kernel/croutine.c \
../Src/Middleware/FreeRTOS-Kernel/event_groups.c \
../Src/Middleware/FreeRTOS-Kernel/heap_4.c \
../Src/Middleware/FreeRTOS-Kernel/list.c \
../Src/Middleware/FreeRTOS-Kernel/port.c \
../Src/Middleware/FreeRTOS-Kernel/queue.c \
../Src/Middleware/FreeRTOS-Kernel/stream_buffer.c \
../Src/Middleware/FreeRTOS-Kernel/tasks.c \
../Src/Middleware/FreeRTOS-Kernel/timers.c 

OBJS += \
./Src/Middleware/FreeRTOS-Kernel/croutine.o \
./Src/Middleware/FreeRTOS-Kernel/event_groups.o \
./Src/Middleware/FreeRTOS-Kernel/heap_4.o \
./Src/Middleware/FreeRTOS-Kernel/list.o \
./Src/Middleware/FreeRTOS-Kernel/port.o \
./Src/Middleware/FreeRTOS-Kernel/queue.o \
./Src/Middleware/FreeRTOS-Kernel/stream_buffer.o \
./Src/Middleware/FreeRTOS-Kernel/tasks.o \
./Src/Middleware/FreeRTOS-Kernel/timers.o 

C_DEPS += \
./Src/Middleware/FreeRTOS-Kernel/croutine.d \
./Src/Middleware/FreeRTOS-Kernel/event_groups.d \
./Src/Middleware/FreeRTOS-Kernel/heap_4.d \
./Src/Middleware/FreeRTOS-Kernel/list.d \
./Src/Middleware/FreeRTOS-Kernel/port.d \
./Src/Middleware/FreeRTOS-Kernel/queue.d \
./Src/Middleware/FreeRTOS-Kernel/stream_buffer.d \
./Src/Middleware/FreeRTOS-Kernel/tasks.d \
./Src/Middleware/FreeRTOS-Kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/FreeRTOS-Kernel/%.o Src/Middleware/FreeRTOS-Kernel/%.su: ../Src/Middleware/FreeRTOS-Kernel/%.c Src/Middleware/FreeRTOS-Kernel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/application/event" -I"/home/kang/space/ll_mp3_project/Src/application" -I"/home/kang/space/ll_mp3_project/Src/Middleware/u8g2" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-FreeRTOS-2d-Kernel

clean-Src-2f-Middleware-2f-FreeRTOS-2d-Kernel:
	-$(RM) ./Src/Middleware/FreeRTOS-Kernel/croutine.d ./Src/Middleware/FreeRTOS-Kernel/croutine.o ./Src/Middleware/FreeRTOS-Kernel/croutine.su ./Src/Middleware/FreeRTOS-Kernel/event_groups.d ./Src/Middleware/FreeRTOS-Kernel/event_groups.o ./Src/Middleware/FreeRTOS-Kernel/event_groups.su ./Src/Middleware/FreeRTOS-Kernel/heap_4.d ./Src/Middleware/FreeRTOS-Kernel/heap_4.o ./Src/Middleware/FreeRTOS-Kernel/heap_4.su ./Src/Middleware/FreeRTOS-Kernel/list.d ./Src/Middleware/FreeRTOS-Kernel/list.o ./Src/Middleware/FreeRTOS-Kernel/list.su ./Src/Middleware/FreeRTOS-Kernel/port.d ./Src/Middleware/FreeRTOS-Kernel/port.o ./Src/Middleware/FreeRTOS-Kernel/port.su ./Src/Middleware/FreeRTOS-Kernel/queue.d ./Src/Middleware/FreeRTOS-Kernel/queue.o ./Src/Middleware/FreeRTOS-Kernel/queue.su ./Src/Middleware/FreeRTOS-Kernel/stream_buffer.d ./Src/Middleware/FreeRTOS-Kernel/stream_buffer.o ./Src/Middleware/FreeRTOS-Kernel/stream_buffer.su ./Src/Middleware/FreeRTOS-Kernel/tasks.d ./Src/Middleware/FreeRTOS-Kernel/tasks.o ./Src/Middleware/FreeRTOS-Kernel/tasks.su ./Src/Middleware/FreeRTOS-Kernel/timers.d ./Src/Middleware/FreeRTOS-Kernel/timers.o ./Src/Middleware/FreeRTOS-Kernel/timers.su

.PHONY: clean-Src-2f-Middleware-2f-FreeRTOS-2d-Kernel

