################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/u8g2/u8g2_bitmap.c \
../Src/Middleware/u8g2/u8g2_box.c \
../Src/Middleware/u8g2/u8g2_buffer.c \
../Src/Middleware/u8g2/u8g2_circle.c \
../Src/Middleware/u8g2/u8g2_cleardisplay.c \
../Src/Middleware/u8g2/u8g2_d_memory.c \
../Src/Middleware/u8g2/u8g2_d_setup.c \
../Src/Middleware/u8g2/u8g2_font.c \
../Src/Middleware/u8g2/u8g2_fonts.c \
../Src/Middleware/u8g2/u8g2_hvline.c \
../Src/Middleware/u8g2/u8g2_input_value.c \
../Src/Middleware/u8g2/u8g2_intersection.c \
../Src/Middleware/u8g2/u8g2_kerning.c \
../Src/Middleware/u8g2/u8g2_line.c \
../Src/Middleware/u8g2/u8g2_ll_hvline.c \
../Src/Middleware/u8g2/u8g2_message.c \
../Src/Middleware/u8g2/u8g2_polygon.c \
../Src/Middleware/u8g2/u8g2_selection_list.c \
../Src/Middleware/u8g2/u8g2_setup.c \
../Src/Middleware/u8g2/u8log.c \
../Src/Middleware/u8g2/u8log_u8g2.c \
../Src/Middleware/u8g2/u8log_u8x8.c \
../Src/Middleware/u8g2/u8x8_8x8.c \
../Src/Middleware/u8g2/u8x8_byte.c \
../Src/Middleware/u8g2/u8x8_cad.c \
../Src/Middleware/u8g2/u8x8_d_a2printer.c \
../Src/Middleware/u8g2/u8x8_d_il3820_296x128.c \
../Src/Middleware/u8g2/u8x8_d_ist3020.c \
../Src/Middleware/u8g2/u8x8_d_ks0108.c \
../Src/Middleware/u8g2/u8x8_d_lc7981.c \
../Src/Middleware/u8g2/u8x8_d_ld7032_60x32.c \
../Src/Middleware/u8g2/u8x8_d_ls013b7dh03.c \
../Src/Middleware/u8g2/u8x8_d_max7219.c \
../Src/Middleware/u8g2/u8x8_d_pcd8544_84x48.c \
../Src/Middleware/u8g2/u8x8_d_pcf8812.c \
../Src/Middleware/u8g2/u8x8_d_pcf8814_hx1230.c \
../Src/Middleware/u8g2/u8x8_d_sbn1661.c \
../Src/Middleware/u8g2/u8x8_d_sed1330.c \
../Src/Middleware/u8g2/u8x8_d_sh1106_64x32.c \
../Src/Middleware/u8g2/u8x8_d_sh1106_72x40.c \
../Src/Middleware/u8g2/u8x8_d_sh1107.c \
../Src/Middleware/u8g2/u8x8_d_sh1108.c \
../Src/Middleware/u8g2/u8x8_d_sh1122.c \
../Src/Middleware/u8g2/u8x8_d_ssd1305.c \
../Src/Middleware/u8g2/u8x8_d_ssd1306_128x32.c \
../Src/Middleware/u8g2/u8x8_d_ssd1306_128x64_noname.c \
../Src/Middleware/u8g2/u8x8_d_ssd1306_48x64.c \
../Src/Middleware/u8g2/u8x8_d_ssd1306_64x32.c \
../Src/Middleware/u8g2/u8x8_d_ssd1306_64x48.c \
../Src/Middleware/u8g2/u8x8_d_ssd1306_96x16.c \
../Src/Middleware/u8g2/u8x8_d_ssd1309.c \
../Src/Middleware/u8g2/u8x8_d_ssd1317.c \
../Src/Middleware/u8g2/u8x8_d_ssd1318.c \
../Src/Middleware/u8g2/u8x8_d_ssd1322.c \
../Src/Middleware/u8g2/u8x8_d_ssd1325.c \
../Src/Middleware/u8g2/u8x8_d_ssd1326.c \
../Src/Middleware/u8g2/u8x8_d_ssd1327.c \
../Src/Middleware/u8g2/u8x8_d_ssd1329.c \
../Src/Middleware/u8g2/u8x8_d_ssd1606_172x72.c \
../Src/Middleware/u8g2/u8x8_d_ssd1607_200x200.c \
../Src/Middleware/u8g2/u8x8_d_st75256.c \
../Src/Middleware/u8g2/u8x8_d_st7565.c \
../Src/Middleware/u8g2/u8x8_d_st7567.c \
../Src/Middleware/u8g2/u8x8_d_st7586s_erc240160.c \
../Src/Middleware/u8g2/u8x8_d_st7586s_s028hn118a.c \
../Src/Middleware/u8g2/u8x8_d_st7588.c \
../Src/Middleware/u8g2/u8x8_d_st7920.c \
../Src/Middleware/u8g2/u8x8_d_stdio.c \
../Src/Middleware/u8g2/u8x8_d_t6963.c \
../Src/Middleware/u8g2/u8x8_d_uc1601.c \
../Src/Middleware/u8g2/u8x8_d_uc1604.c \
../Src/Middleware/u8g2/u8x8_d_uc1608.c \
../Src/Middleware/u8g2/u8x8_d_uc1610.c \
../Src/Middleware/u8g2/u8x8_d_uc1611.c \
../Src/Middleware/u8g2/u8x8_d_uc1617.c \
../Src/Middleware/u8g2/u8x8_d_uc1638.c \
../Src/Middleware/u8g2/u8x8_d_uc1701_dogs102.c \
../Src/Middleware/u8g2/u8x8_d_uc1701_mini12864.c \
../Src/Middleware/u8g2/u8x8_debounce.c \
../Src/Middleware/u8g2/u8x8_display.c \
../Src/Middleware/u8g2/u8x8_fonts.c \
../Src/Middleware/u8g2/u8x8_gpio.c \
../Src/Middleware/u8g2/u8x8_input_value.c \
../Src/Middleware/u8g2/u8x8_message.c \
../Src/Middleware/u8g2/u8x8_selection_list.c \
../Src/Middleware/u8g2/u8x8_setup.c \
../Src/Middleware/u8g2/u8x8_string.c \
../Src/Middleware/u8g2/u8x8_u16toa.c \
../Src/Middleware/u8g2/u8x8_u8toa.c 

OBJS += \
./Src/Middleware/u8g2/u8g2_bitmap.o \
./Src/Middleware/u8g2/u8g2_box.o \
./Src/Middleware/u8g2/u8g2_buffer.o \
./Src/Middleware/u8g2/u8g2_circle.o \
./Src/Middleware/u8g2/u8g2_cleardisplay.o \
./Src/Middleware/u8g2/u8g2_d_memory.o \
./Src/Middleware/u8g2/u8g2_d_setup.o \
./Src/Middleware/u8g2/u8g2_font.o \
./Src/Middleware/u8g2/u8g2_fonts.o \
./Src/Middleware/u8g2/u8g2_hvline.o \
./Src/Middleware/u8g2/u8g2_input_value.o \
./Src/Middleware/u8g2/u8g2_intersection.o \
./Src/Middleware/u8g2/u8g2_kerning.o \
./Src/Middleware/u8g2/u8g2_line.o \
./Src/Middleware/u8g2/u8g2_ll_hvline.o \
./Src/Middleware/u8g2/u8g2_message.o \
./Src/Middleware/u8g2/u8g2_polygon.o \
./Src/Middleware/u8g2/u8g2_selection_list.o \
./Src/Middleware/u8g2/u8g2_setup.o \
./Src/Middleware/u8g2/u8log.o \
./Src/Middleware/u8g2/u8log_u8g2.o \
./Src/Middleware/u8g2/u8log_u8x8.o \
./Src/Middleware/u8g2/u8x8_8x8.o \
./Src/Middleware/u8g2/u8x8_byte.o \
./Src/Middleware/u8g2/u8x8_cad.o \
./Src/Middleware/u8g2/u8x8_d_a2printer.o \
./Src/Middleware/u8g2/u8x8_d_il3820_296x128.o \
./Src/Middleware/u8g2/u8x8_d_ist3020.o \
./Src/Middleware/u8g2/u8x8_d_ks0108.o \
./Src/Middleware/u8g2/u8x8_d_lc7981.o \
./Src/Middleware/u8g2/u8x8_d_ld7032_60x32.o \
./Src/Middleware/u8g2/u8x8_d_ls013b7dh03.o \
./Src/Middleware/u8g2/u8x8_d_max7219.o \
./Src/Middleware/u8g2/u8x8_d_pcd8544_84x48.o \
./Src/Middleware/u8g2/u8x8_d_pcf8812.o \
./Src/Middleware/u8g2/u8x8_d_pcf8814_hx1230.o \
./Src/Middleware/u8g2/u8x8_d_sbn1661.o \
./Src/Middleware/u8g2/u8x8_d_sed1330.o \
./Src/Middleware/u8g2/u8x8_d_sh1106_64x32.o \
./Src/Middleware/u8g2/u8x8_d_sh1106_72x40.o \
./Src/Middleware/u8g2/u8x8_d_sh1107.o \
./Src/Middleware/u8g2/u8x8_d_sh1108.o \
./Src/Middleware/u8g2/u8x8_d_sh1122.o \
./Src/Middleware/u8g2/u8x8_d_ssd1305.o \
./Src/Middleware/u8g2/u8x8_d_ssd1306_128x32.o \
./Src/Middleware/u8g2/u8x8_d_ssd1306_128x64_noname.o \
./Src/Middleware/u8g2/u8x8_d_ssd1306_48x64.o \
./Src/Middleware/u8g2/u8x8_d_ssd1306_64x32.o \
./Src/Middleware/u8g2/u8x8_d_ssd1306_64x48.o \
./Src/Middleware/u8g2/u8x8_d_ssd1306_96x16.o \
./Src/Middleware/u8g2/u8x8_d_ssd1309.o \
./Src/Middleware/u8g2/u8x8_d_ssd1317.o \
./Src/Middleware/u8g2/u8x8_d_ssd1318.o \
./Src/Middleware/u8g2/u8x8_d_ssd1322.o \
./Src/Middleware/u8g2/u8x8_d_ssd1325.o \
./Src/Middleware/u8g2/u8x8_d_ssd1326.o \
./Src/Middleware/u8g2/u8x8_d_ssd1327.o \
./Src/Middleware/u8g2/u8x8_d_ssd1329.o \
./Src/Middleware/u8g2/u8x8_d_ssd1606_172x72.o \
./Src/Middleware/u8g2/u8x8_d_ssd1607_200x200.o \
./Src/Middleware/u8g2/u8x8_d_st75256.o \
./Src/Middleware/u8g2/u8x8_d_st7565.o \
./Src/Middleware/u8g2/u8x8_d_st7567.o \
./Src/Middleware/u8g2/u8x8_d_st7586s_erc240160.o \
./Src/Middleware/u8g2/u8x8_d_st7586s_s028hn118a.o \
./Src/Middleware/u8g2/u8x8_d_st7588.o \
./Src/Middleware/u8g2/u8x8_d_st7920.o \
./Src/Middleware/u8g2/u8x8_d_stdio.o \
./Src/Middleware/u8g2/u8x8_d_t6963.o \
./Src/Middleware/u8g2/u8x8_d_uc1601.o \
./Src/Middleware/u8g2/u8x8_d_uc1604.o \
./Src/Middleware/u8g2/u8x8_d_uc1608.o \
./Src/Middleware/u8g2/u8x8_d_uc1610.o \
./Src/Middleware/u8g2/u8x8_d_uc1611.o \
./Src/Middleware/u8g2/u8x8_d_uc1617.o \
./Src/Middleware/u8g2/u8x8_d_uc1638.o \
./Src/Middleware/u8g2/u8x8_d_uc1701_dogs102.o \
./Src/Middleware/u8g2/u8x8_d_uc1701_mini12864.o \
./Src/Middleware/u8g2/u8x8_debounce.o \
./Src/Middleware/u8g2/u8x8_display.o \
./Src/Middleware/u8g2/u8x8_fonts.o \
./Src/Middleware/u8g2/u8x8_gpio.o \
./Src/Middleware/u8g2/u8x8_input_value.o \
./Src/Middleware/u8g2/u8x8_message.o \
./Src/Middleware/u8g2/u8x8_selection_list.o \
./Src/Middleware/u8g2/u8x8_setup.o \
./Src/Middleware/u8g2/u8x8_string.o \
./Src/Middleware/u8g2/u8x8_u16toa.o \
./Src/Middleware/u8g2/u8x8_u8toa.o 

C_DEPS += \
./Src/Middleware/u8g2/u8g2_bitmap.d \
./Src/Middleware/u8g2/u8g2_box.d \
./Src/Middleware/u8g2/u8g2_buffer.d \
./Src/Middleware/u8g2/u8g2_circle.d \
./Src/Middleware/u8g2/u8g2_cleardisplay.d \
./Src/Middleware/u8g2/u8g2_d_memory.d \
./Src/Middleware/u8g2/u8g2_d_setup.d \
./Src/Middleware/u8g2/u8g2_font.d \
./Src/Middleware/u8g2/u8g2_fonts.d \
./Src/Middleware/u8g2/u8g2_hvline.d \
./Src/Middleware/u8g2/u8g2_input_value.d \
./Src/Middleware/u8g2/u8g2_intersection.d \
./Src/Middleware/u8g2/u8g2_kerning.d \
./Src/Middleware/u8g2/u8g2_line.d \
./Src/Middleware/u8g2/u8g2_ll_hvline.d \
./Src/Middleware/u8g2/u8g2_message.d \
./Src/Middleware/u8g2/u8g2_polygon.d \
./Src/Middleware/u8g2/u8g2_selection_list.d \
./Src/Middleware/u8g2/u8g2_setup.d \
./Src/Middleware/u8g2/u8log.d \
./Src/Middleware/u8g2/u8log_u8g2.d \
./Src/Middleware/u8g2/u8log_u8x8.d \
./Src/Middleware/u8g2/u8x8_8x8.d \
./Src/Middleware/u8g2/u8x8_byte.d \
./Src/Middleware/u8g2/u8x8_cad.d \
./Src/Middleware/u8g2/u8x8_d_a2printer.d \
./Src/Middleware/u8g2/u8x8_d_il3820_296x128.d \
./Src/Middleware/u8g2/u8x8_d_ist3020.d \
./Src/Middleware/u8g2/u8x8_d_ks0108.d \
./Src/Middleware/u8g2/u8x8_d_lc7981.d \
./Src/Middleware/u8g2/u8x8_d_ld7032_60x32.d \
./Src/Middleware/u8g2/u8x8_d_ls013b7dh03.d \
./Src/Middleware/u8g2/u8x8_d_max7219.d \
./Src/Middleware/u8g2/u8x8_d_pcd8544_84x48.d \
./Src/Middleware/u8g2/u8x8_d_pcf8812.d \
./Src/Middleware/u8g2/u8x8_d_pcf8814_hx1230.d \
./Src/Middleware/u8g2/u8x8_d_sbn1661.d \
./Src/Middleware/u8g2/u8x8_d_sed1330.d \
./Src/Middleware/u8g2/u8x8_d_sh1106_64x32.d \
./Src/Middleware/u8g2/u8x8_d_sh1106_72x40.d \
./Src/Middleware/u8g2/u8x8_d_sh1107.d \
./Src/Middleware/u8g2/u8x8_d_sh1108.d \
./Src/Middleware/u8g2/u8x8_d_sh1122.d \
./Src/Middleware/u8g2/u8x8_d_ssd1305.d \
./Src/Middleware/u8g2/u8x8_d_ssd1306_128x32.d \
./Src/Middleware/u8g2/u8x8_d_ssd1306_128x64_noname.d \
./Src/Middleware/u8g2/u8x8_d_ssd1306_48x64.d \
./Src/Middleware/u8g2/u8x8_d_ssd1306_64x32.d \
./Src/Middleware/u8g2/u8x8_d_ssd1306_64x48.d \
./Src/Middleware/u8g2/u8x8_d_ssd1306_96x16.d \
./Src/Middleware/u8g2/u8x8_d_ssd1309.d \
./Src/Middleware/u8g2/u8x8_d_ssd1317.d \
./Src/Middleware/u8g2/u8x8_d_ssd1318.d \
./Src/Middleware/u8g2/u8x8_d_ssd1322.d \
./Src/Middleware/u8g2/u8x8_d_ssd1325.d \
./Src/Middleware/u8g2/u8x8_d_ssd1326.d \
./Src/Middleware/u8g2/u8x8_d_ssd1327.d \
./Src/Middleware/u8g2/u8x8_d_ssd1329.d \
./Src/Middleware/u8g2/u8x8_d_ssd1606_172x72.d \
./Src/Middleware/u8g2/u8x8_d_ssd1607_200x200.d \
./Src/Middleware/u8g2/u8x8_d_st75256.d \
./Src/Middleware/u8g2/u8x8_d_st7565.d \
./Src/Middleware/u8g2/u8x8_d_st7567.d \
./Src/Middleware/u8g2/u8x8_d_st7586s_erc240160.d \
./Src/Middleware/u8g2/u8x8_d_st7586s_s028hn118a.d \
./Src/Middleware/u8g2/u8x8_d_st7588.d \
./Src/Middleware/u8g2/u8x8_d_st7920.d \
./Src/Middleware/u8g2/u8x8_d_stdio.d \
./Src/Middleware/u8g2/u8x8_d_t6963.d \
./Src/Middleware/u8g2/u8x8_d_uc1601.d \
./Src/Middleware/u8g2/u8x8_d_uc1604.d \
./Src/Middleware/u8g2/u8x8_d_uc1608.d \
./Src/Middleware/u8g2/u8x8_d_uc1610.d \
./Src/Middleware/u8g2/u8x8_d_uc1611.d \
./Src/Middleware/u8g2/u8x8_d_uc1617.d \
./Src/Middleware/u8g2/u8x8_d_uc1638.d \
./Src/Middleware/u8g2/u8x8_d_uc1701_dogs102.d \
./Src/Middleware/u8g2/u8x8_d_uc1701_mini12864.d \
./Src/Middleware/u8g2/u8x8_debounce.d \
./Src/Middleware/u8g2/u8x8_display.d \
./Src/Middleware/u8g2/u8x8_fonts.d \
./Src/Middleware/u8g2/u8x8_gpio.d \
./Src/Middleware/u8g2/u8x8_input_value.d \
./Src/Middleware/u8g2/u8x8_message.d \
./Src/Middleware/u8g2/u8x8_selection_list.d \
./Src/Middleware/u8g2/u8x8_setup.d \
./Src/Middleware/u8g2/u8x8_string.d \
./Src/Middleware/u8g2/u8x8_u16toa.d \
./Src/Middleware/u8g2/u8x8_u8toa.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/u8g2/%.o Src/Middleware/u8g2/%.su: ../Src/Middleware/u8g2/%.c Src/Middleware/u8g2/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DUSE_FULL_LL_DRIVER -DSTM32F429xx -c -I"/home/kang/space/ll_mp3_project/conf" -I"/home/kang/space/ll_mp3_project/Src/application/event" -I"/home/kang/space/ll_mp3_project/Src/application" -I"/home/kang/space/ll_mp3_project/Src/Middleware/u8g2" -I"/home/kang/space/ll_mp3_project/Src" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FATFS" -I"/home/kang/space/ll_mp3_project/Src/Middleware/FreeRTOS-Kernel/include" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Config" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/SEGGER" -I"/home/kang/space/ll_mp3_project/Src/Middleware/SEGGER/SystemView/Sample/FreeRTOS" -I"/home/kang/space/ll_mp3_project/Src/core" -I"/home/kang/space/ll_mp3_project/Src/Drivers" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/CMSIS/Include" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/kang/space/ll_mp3_project/Src/HAL/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Middleware-2f-u8g2

clean-Src-2f-Middleware-2f-u8g2:
	-$(RM) ./Src/Middleware/u8g2/u8g2_bitmap.d ./Src/Middleware/u8g2/u8g2_bitmap.o ./Src/Middleware/u8g2/u8g2_bitmap.su ./Src/Middleware/u8g2/u8g2_box.d ./Src/Middleware/u8g2/u8g2_box.o ./Src/Middleware/u8g2/u8g2_box.su ./Src/Middleware/u8g2/u8g2_buffer.d ./Src/Middleware/u8g2/u8g2_buffer.o ./Src/Middleware/u8g2/u8g2_buffer.su ./Src/Middleware/u8g2/u8g2_circle.d ./Src/Middleware/u8g2/u8g2_circle.o ./Src/Middleware/u8g2/u8g2_circle.su ./Src/Middleware/u8g2/u8g2_cleardisplay.d ./Src/Middleware/u8g2/u8g2_cleardisplay.o ./Src/Middleware/u8g2/u8g2_cleardisplay.su ./Src/Middleware/u8g2/u8g2_d_memory.d ./Src/Middleware/u8g2/u8g2_d_memory.o ./Src/Middleware/u8g2/u8g2_d_memory.su ./Src/Middleware/u8g2/u8g2_d_setup.d ./Src/Middleware/u8g2/u8g2_d_setup.o ./Src/Middleware/u8g2/u8g2_d_setup.su ./Src/Middleware/u8g2/u8g2_font.d ./Src/Middleware/u8g2/u8g2_font.o ./Src/Middleware/u8g2/u8g2_font.su ./Src/Middleware/u8g2/u8g2_fonts.d ./Src/Middleware/u8g2/u8g2_fonts.o ./Src/Middleware/u8g2/u8g2_fonts.su ./Src/Middleware/u8g2/u8g2_hvline.d ./Src/Middleware/u8g2/u8g2_hvline.o ./Src/Middleware/u8g2/u8g2_hvline.su ./Src/Middleware/u8g2/u8g2_input_value.d ./Src/Middleware/u8g2/u8g2_input_value.o ./Src/Middleware/u8g2/u8g2_input_value.su ./Src/Middleware/u8g2/u8g2_intersection.d ./Src/Middleware/u8g2/u8g2_intersection.o ./Src/Middleware/u8g2/u8g2_intersection.su ./Src/Middleware/u8g2/u8g2_kerning.d ./Src/Middleware/u8g2/u8g2_kerning.o ./Src/Middleware/u8g2/u8g2_kerning.su ./Src/Middleware/u8g2/u8g2_line.d ./Src/Middleware/u8g2/u8g2_line.o ./Src/Middleware/u8g2/u8g2_line.su ./Src/Middleware/u8g2/u8g2_ll_hvline.d ./Src/Middleware/u8g2/u8g2_ll_hvline.o ./Src/Middleware/u8g2/u8g2_ll_hvline.su ./Src/Middleware/u8g2/u8g2_message.d ./Src/Middleware/u8g2/u8g2_message.o ./Src/Middleware/u8g2/u8g2_message.su ./Src/Middleware/u8g2/u8g2_polygon.d ./Src/Middleware/u8g2/u8g2_polygon.o ./Src/Middleware/u8g2/u8g2_polygon.su ./Src/Middleware/u8g2/u8g2_selection_list.d ./Src/Middleware/u8g2/u8g2_selection_list.o ./Src/Middleware/u8g2/u8g2_selection_list.su ./Src/Middleware/u8g2/u8g2_setup.d ./Src/Middleware/u8g2/u8g2_setup.o ./Src/Middleware/u8g2/u8g2_setup.su ./Src/Middleware/u8g2/u8log.d ./Src/Middleware/u8g2/u8log.o ./Src/Middleware/u8g2/u8log.su ./Src/Middleware/u8g2/u8log_u8g2.d ./Src/Middleware/u8g2/u8log_u8g2.o ./Src/Middleware/u8g2/u8log_u8g2.su ./Src/Middleware/u8g2/u8log_u8x8.d ./Src/Middleware/u8g2/u8log_u8x8.o ./Src/Middleware/u8g2/u8log_u8x8.su ./Src/Middleware/u8g2/u8x8_8x8.d ./Src/Middleware/u8g2/u8x8_8x8.o ./Src/Middleware/u8g2/u8x8_8x8.su ./Src/Middleware/u8g2/u8x8_byte.d ./Src/Middleware/u8g2/u8x8_byte.o ./Src/Middleware/u8g2/u8x8_byte.su ./Src/Middleware/u8g2/u8x8_cad.d ./Src/Middleware/u8g2/u8x8_cad.o ./Src/Middleware/u8g2/u8x8_cad.su ./Src/Middleware/u8g2/u8x8_d_a2printer.d ./Src/Middleware/u8g2/u8x8_d_a2printer.o ./Src/Middleware/u8g2/u8x8_d_a2printer.su ./Src/Middleware/u8g2/u8x8_d_il3820_296x128.d ./Src/Middleware/u8g2/u8x8_d_il3820_296x128.o ./Src/Middleware/u8g2/u8x8_d_il3820_296x128.su ./Src/Middleware/u8g2/u8x8_d_ist3020.d ./Src/Middleware/u8g2/u8x8_d_ist3020.o ./Src/Middleware/u8g2/u8x8_d_ist3020.su ./Src/Middleware/u8g2/u8x8_d_ks0108.d ./Src/Middleware/u8g2/u8x8_d_ks0108.o ./Src/Middleware/u8g2/u8x8_d_ks0108.su ./Src/Middleware/u8g2/u8x8_d_lc7981.d ./Src/Middleware/u8g2/u8x8_d_lc7981.o ./Src/Middleware/u8g2/u8x8_d_lc7981.su ./Src/Middleware/u8g2/u8x8_d_ld7032_60x32.d ./Src/Middleware/u8g2/u8x8_d_ld7032_60x32.o ./Src/Middleware/u8g2/u8x8_d_ld7032_60x32.su ./Src/Middleware/u8g2/u8x8_d_ls013b7dh03.d ./Src/Middleware/u8g2/u8x8_d_ls013b7dh03.o ./Src/Middleware/u8g2/u8x8_d_ls013b7dh03.su ./Src/Middleware/u8g2/u8x8_d_max7219.d ./Src/Middleware/u8g2/u8x8_d_max7219.o ./Src/Middleware/u8g2/u8x8_d_max7219.su ./Src/Middleware/u8g2/u8x8_d_pcd8544_84x48.d ./Src/Middleware/u8g2/u8x8_d_pcd8544_84x48.o ./Src/Middleware/u8g2/u8x8_d_pcd8544_84x48.su ./Src/Middleware/u8g2/u8x8_d_pcf8812.d ./Src/Middleware/u8g2/u8x8_d_pcf8812.o ./Src/Middleware/u8g2/u8x8_d_pcf8812.su ./Src/Middleware/u8g2/u8x8_d_pcf8814_hx1230.d ./Src/Middleware/u8g2/u8x8_d_pcf8814_hx1230.o ./Src/Middleware/u8g2/u8x8_d_pcf8814_hx1230.su ./Src/Middleware/u8g2/u8x8_d_sbn1661.d ./Src/Middleware/u8g2/u8x8_d_sbn1661.o ./Src/Middleware/u8g2/u8x8_d_sbn1661.su ./Src/Middleware/u8g2/u8x8_d_sed1330.d ./Src/Middleware/u8g2/u8x8_d_sed1330.o ./Src/Middleware/u8g2/u8x8_d_sed1330.su ./Src/Middleware/u8g2/u8x8_d_sh1106_64x32.d ./Src/Middleware/u8g2/u8x8_d_sh1106_64x32.o ./Src/Middleware/u8g2/u8x8_d_sh1106_64x32.su ./Src/Middleware/u8g2/u8x8_d_sh1106_72x40.d ./Src/Middleware/u8g2/u8x8_d_sh1106_72x40.o ./Src/Middleware/u8g2/u8x8_d_sh1106_72x40.su ./Src/Middleware/u8g2/u8x8_d_sh1107.d ./Src/Middleware/u8g2/u8x8_d_sh1107.o ./Src/Middleware/u8g2/u8x8_d_sh1107.su ./Src/Middleware/u8g2/u8x8_d_sh1108.d ./Src/Middleware/u8g2/u8x8_d_sh1108.o ./Src/Middleware/u8g2/u8x8_d_sh1108.su ./Src/Middleware/u8g2/u8x8_d_sh1122.d ./Src/Middleware/u8g2/u8x8_d_sh1122.o ./Src/Middleware/u8g2/u8x8_d_sh1122.su ./Src/Middleware/u8g2/u8x8_d_ssd1305.d ./Src/Middleware/u8g2/u8x8_d_ssd1305.o ./Src/Middleware/u8g2/u8x8_d_ssd1305.su ./Src/Middleware/u8g2/u8x8_d_ssd1306_128x32.d ./Src/Middleware/u8g2/u8x8_d_ssd1306_128x32.o ./Src/Middleware/u8g2/u8x8_d_ssd1306_128x32.su ./Src/Middleware/u8g2/u8x8_d_ssd1306_128x64_noname.d ./Src/Middleware/u8g2/u8x8_d_ssd1306_128x64_noname.o ./Src/Middleware/u8g2/u8x8_d_ssd1306_128x64_noname.su ./Src/Middleware/u8g2/u8x8_d_ssd1306_48x64.d ./Src/Middleware/u8g2/u8x8_d_ssd1306_48x64.o ./Src/Middleware/u8g2/u8x8_d_ssd1306_48x64.su ./Src/Middleware/u8g2/u8x8_d_ssd1306_64x32.d ./Src/Middleware/u8g2/u8x8_d_ssd1306_64x32.o ./Src/Middleware/u8g2/u8x8_d_ssd1306_64x32.su ./Src/Middleware/u8g2/u8x8_d_ssd1306_64x48.d ./Src/Middleware/u8g2/u8x8_d_ssd1306_64x48.o ./Src/Middleware/u8g2/u8x8_d_ssd1306_64x48.su ./Src/Middleware/u8g2/u8x8_d_ssd1306_96x16.d ./Src/Middleware/u8g2/u8x8_d_ssd1306_96x16.o ./Src/Middleware/u8g2/u8x8_d_ssd1306_96x16.su ./Src/Middleware/u8g2/u8x8_d_ssd1309.d
	-$(RM) ./Src/Middleware/u8g2/u8x8_d_ssd1309.o ./Src/Middleware/u8g2/u8x8_d_ssd1309.su ./Src/Middleware/u8g2/u8x8_d_ssd1317.d ./Src/Middleware/u8g2/u8x8_d_ssd1317.o ./Src/Middleware/u8g2/u8x8_d_ssd1317.su ./Src/Middleware/u8g2/u8x8_d_ssd1318.d ./Src/Middleware/u8g2/u8x8_d_ssd1318.o ./Src/Middleware/u8g2/u8x8_d_ssd1318.su ./Src/Middleware/u8g2/u8x8_d_ssd1322.d ./Src/Middleware/u8g2/u8x8_d_ssd1322.o ./Src/Middleware/u8g2/u8x8_d_ssd1322.su ./Src/Middleware/u8g2/u8x8_d_ssd1325.d ./Src/Middleware/u8g2/u8x8_d_ssd1325.o ./Src/Middleware/u8g2/u8x8_d_ssd1325.su ./Src/Middleware/u8g2/u8x8_d_ssd1326.d ./Src/Middleware/u8g2/u8x8_d_ssd1326.o ./Src/Middleware/u8g2/u8x8_d_ssd1326.su ./Src/Middleware/u8g2/u8x8_d_ssd1327.d ./Src/Middleware/u8g2/u8x8_d_ssd1327.o ./Src/Middleware/u8g2/u8x8_d_ssd1327.su ./Src/Middleware/u8g2/u8x8_d_ssd1329.d ./Src/Middleware/u8g2/u8x8_d_ssd1329.o ./Src/Middleware/u8g2/u8x8_d_ssd1329.su ./Src/Middleware/u8g2/u8x8_d_ssd1606_172x72.d ./Src/Middleware/u8g2/u8x8_d_ssd1606_172x72.o ./Src/Middleware/u8g2/u8x8_d_ssd1606_172x72.su ./Src/Middleware/u8g2/u8x8_d_ssd1607_200x200.d ./Src/Middleware/u8g2/u8x8_d_ssd1607_200x200.o ./Src/Middleware/u8g2/u8x8_d_ssd1607_200x200.su ./Src/Middleware/u8g2/u8x8_d_st75256.d ./Src/Middleware/u8g2/u8x8_d_st75256.o ./Src/Middleware/u8g2/u8x8_d_st75256.su ./Src/Middleware/u8g2/u8x8_d_st7565.d ./Src/Middleware/u8g2/u8x8_d_st7565.o ./Src/Middleware/u8g2/u8x8_d_st7565.su ./Src/Middleware/u8g2/u8x8_d_st7567.d ./Src/Middleware/u8g2/u8x8_d_st7567.o ./Src/Middleware/u8g2/u8x8_d_st7567.su ./Src/Middleware/u8g2/u8x8_d_st7586s_erc240160.d ./Src/Middleware/u8g2/u8x8_d_st7586s_erc240160.o ./Src/Middleware/u8g2/u8x8_d_st7586s_erc240160.su ./Src/Middleware/u8g2/u8x8_d_st7586s_s028hn118a.d ./Src/Middleware/u8g2/u8x8_d_st7586s_s028hn118a.o ./Src/Middleware/u8g2/u8x8_d_st7586s_s028hn118a.su ./Src/Middleware/u8g2/u8x8_d_st7588.d ./Src/Middleware/u8g2/u8x8_d_st7588.o ./Src/Middleware/u8g2/u8x8_d_st7588.su ./Src/Middleware/u8g2/u8x8_d_st7920.d ./Src/Middleware/u8g2/u8x8_d_st7920.o ./Src/Middleware/u8g2/u8x8_d_st7920.su ./Src/Middleware/u8g2/u8x8_d_stdio.d ./Src/Middleware/u8g2/u8x8_d_stdio.o ./Src/Middleware/u8g2/u8x8_d_stdio.su ./Src/Middleware/u8g2/u8x8_d_t6963.d ./Src/Middleware/u8g2/u8x8_d_t6963.o ./Src/Middleware/u8g2/u8x8_d_t6963.su ./Src/Middleware/u8g2/u8x8_d_uc1601.d ./Src/Middleware/u8g2/u8x8_d_uc1601.o ./Src/Middleware/u8g2/u8x8_d_uc1601.su ./Src/Middleware/u8g2/u8x8_d_uc1604.d ./Src/Middleware/u8g2/u8x8_d_uc1604.o ./Src/Middleware/u8g2/u8x8_d_uc1604.su ./Src/Middleware/u8g2/u8x8_d_uc1608.d ./Src/Middleware/u8g2/u8x8_d_uc1608.o ./Src/Middleware/u8g2/u8x8_d_uc1608.su ./Src/Middleware/u8g2/u8x8_d_uc1610.d ./Src/Middleware/u8g2/u8x8_d_uc1610.o ./Src/Middleware/u8g2/u8x8_d_uc1610.su ./Src/Middleware/u8g2/u8x8_d_uc1611.d ./Src/Middleware/u8g2/u8x8_d_uc1611.o ./Src/Middleware/u8g2/u8x8_d_uc1611.su ./Src/Middleware/u8g2/u8x8_d_uc1617.d ./Src/Middleware/u8g2/u8x8_d_uc1617.o ./Src/Middleware/u8g2/u8x8_d_uc1617.su ./Src/Middleware/u8g2/u8x8_d_uc1638.d ./Src/Middleware/u8g2/u8x8_d_uc1638.o ./Src/Middleware/u8g2/u8x8_d_uc1638.su ./Src/Middleware/u8g2/u8x8_d_uc1701_dogs102.d ./Src/Middleware/u8g2/u8x8_d_uc1701_dogs102.o ./Src/Middleware/u8g2/u8x8_d_uc1701_dogs102.su ./Src/Middleware/u8g2/u8x8_d_uc1701_mini12864.d ./Src/Middleware/u8g2/u8x8_d_uc1701_mini12864.o ./Src/Middleware/u8g2/u8x8_d_uc1701_mini12864.su ./Src/Middleware/u8g2/u8x8_debounce.d ./Src/Middleware/u8g2/u8x8_debounce.o ./Src/Middleware/u8g2/u8x8_debounce.su ./Src/Middleware/u8g2/u8x8_display.d ./Src/Middleware/u8g2/u8x8_display.o ./Src/Middleware/u8g2/u8x8_display.su ./Src/Middleware/u8g2/u8x8_fonts.d ./Src/Middleware/u8g2/u8x8_fonts.o ./Src/Middleware/u8g2/u8x8_fonts.su ./Src/Middleware/u8g2/u8x8_gpio.d ./Src/Middleware/u8g2/u8x8_gpio.o ./Src/Middleware/u8g2/u8x8_gpio.su ./Src/Middleware/u8g2/u8x8_input_value.d ./Src/Middleware/u8g2/u8x8_input_value.o ./Src/Middleware/u8g2/u8x8_input_value.su ./Src/Middleware/u8g2/u8x8_message.d ./Src/Middleware/u8g2/u8x8_message.o ./Src/Middleware/u8g2/u8x8_message.su ./Src/Middleware/u8g2/u8x8_selection_list.d ./Src/Middleware/u8g2/u8x8_selection_list.o ./Src/Middleware/u8g2/u8x8_selection_list.su ./Src/Middleware/u8g2/u8x8_setup.d ./Src/Middleware/u8g2/u8x8_setup.o ./Src/Middleware/u8g2/u8x8_setup.su ./Src/Middleware/u8g2/u8x8_string.d ./Src/Middleware/u8g2/u8x8_string.o ./Src/Middleware/u8g2/u8x8_string.su ./Src/Middleware/u8g2/u8x8_u16toa.d ./Src/Middleware/u8g2/u8x8_u16toa.o ./Src/Middleware/u8g2/u8x8_u16toa.su ./Src/Middleware/u8g2/u8x8_u8toa.d ./Src/Middleware/u8g2/u8x8_u8toa.o ./Src/Middleware/u8g2/u8x8_u8toa.su

.PHONY: clean-Src-2f-Middleware-2f-u8g2

