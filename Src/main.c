/* middleware */
#include "core.h"
#include "fatfs.h"

/* hal driver */
#include "clock.h"
#include "resources.h"
#include "i2c.h"
#include "spi.h"
#include "gpio.h"
#include "uart.h"
#include "sdio.h"
#include "adc.h"
#include "cli.h"
#include "delay.h"
#include "tim.h"

/* application */
#include "mp3_app.h"
#include "display_app.h"


static void initThread(void* param) {
	hal_cli_printf("enter initThread");

	sdio_init();
	MX_FATFS_Init();

	i2c_init(I2cId1);
	i2c_init(I2cId3);

	spi_init(SpiId2);
	spi_init(SpiId4);

	adc_init(AdcId1);

	tim_init(TimId4);

	hal_resources_init();

	xTaskCreate(mp3Thread, "mp3_app", 512, NULL, 4, NULL);
	xTaskCreate(displayThread, "display", 512, NULL, 3, NULL);

	hal_cli_printf("exit initThread");

	vTaskDelete(NULL);
}

int main(void) {
	HAL_Init();

	hal_bus_init_early();
	hal_clock_init_early();
	hal_dwt_init_early();

	hal_resources_init_early();

	hal_uart_init(UartIdUSART1, 115200);
	hal_cli_init();

	hal_cli_printf("mcu init early finished");

	traceSTART();
	xTaskCreate(initThread, "init", 256, NULL, 3, NULL);
	vTaskStartScheduler();

	for(;;);
}
