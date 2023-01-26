#include "FreeRTOS.h"
#include "cli.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_dma.h"
#include <stdarg.h>
#include <stdio.h>
#include "uart.h"
#include "task.h"
#include "semphr.h"


#define UART_MUTEX_TIME 1000

static SemaphoreHandle_t uart_mutex;

UartLogBuf_t logbuf;

void hal_cli_menuprint() {
	//hal_cli_printf
}


static void print_boottime() {
	uint32_t tick = xTaskGetTickCount();
	unsigned int decimal, fraction;
	int length;

	decimal = tick / 1000;
	fraction = tick % 1000;

	length = sprintf((char*)logbuf.wd_buf, "[ %u.%u ] ", decimal, fraction);
	hal_uart_transfer(UartIdUSART1, logbuf.wd_buf, length);
}

void hal_cli_bufferprint(void) {

}

void hal_cli_printf(const char* fmt, ...) {
	int length;
	va_list valist;

	if(xSemaphoreTake(uart_mutex, 1000) != pdPASS) {
		return;
	}

	print_boottime();

	va_start(valist, fmt);
	length = vsprintf((char*)logbuf.wd_buf, (char*)fmt, valist);
	va_end(valist);

	hal_uart_transfer(UartIdUSART1, logbuf.wd_buf, length);
	hal_uart_transfer(UartIdUSART1, (uint8_t*)"\r\n", 2);

	xSemaphoreGive(uart_mutex);
}

void hal_cli_init(void) {
	logbuf.head = 0;
	logbuf.tail = 0;
	logbuf.is_over_rd = false;

	uart_mutex = xSemaphoreCreateMutex();

	/* configuration USART1 DMA RX channel */

	LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_2, (uint32_t)logbuf.rd_buf);
	LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_2, (uint32_t)&USART1->DR);
	LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_2, LOG_BUF_SIZE);
	LL_USART_EnableDMAReq_RX(USART1);

	LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_2);

	LL_USART_EnableIT_IDLE(USART1);
}

void hal_cli_putbufbyte(uint8_t data) {
	logbuf.rd_buf[logbuf.tail++] = data;

	logbuf.tail = logbuf.tail % LOG_BUF_SIZE;
}

uint8_t hal_cli_getbufbyte(void) {
	uint8_t data;
	data = logbuf.rd_buf[logbuf.head++];
	logbuf.head %= LOG_BUF_SIZE;
	return data;
}


