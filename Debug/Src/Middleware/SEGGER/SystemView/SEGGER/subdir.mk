################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT.c \
../Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_printf.c \
../Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
../Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT.o \
./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_printf.o \
./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT.d \
./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_printf.d \
./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/SEGGER/SystemView/SEGGER/%.o Src/Middleware/SEGGER/SystemView/SEGGER/%.su: ../Src/Middleware/SEGGER/SystemView/SEGGER/%.c Src/Middleware/SEGGER/SystemView/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DSTM32F429xx -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/kang/stm_workspace/ll_mp3_project/conf" -I"/home/kang/stm_workspace/ll_mp3_project/Src/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/lvgl" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/stm_workspace/ll_mp3_project/Src/core" -I"/home/kang/stm_workspace/ll_mp3_project/Src/Drivers" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/stm_workspace/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/Middleware/SEGGER/SystemView/SEGGER/%.o: ../Src/Middleware/SEGGER/SystemView/SEGGER/%.S Src/Middleware/SEGGER/SystemView/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Src-2f-Middleware-2f-SEGGER-2f-SystemView-2f-SEGGER

clean-Src-2f-Middleware-2f-SEGGER-2f-SystemView-2f-SEGGER:
	-$(RM) ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT.d ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT.o ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT.su ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_printf.d ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_printf.o ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_RTT_printf.su ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_SYSVIEW.d ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_SYSVIEW.o ./Src/Middleware/SEGGER/SystemView/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-Src-2f-Middleware-2f-SEGGER-2f-SystemView-2f-SEGGER

