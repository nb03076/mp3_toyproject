#include "uart.h"
#include "gpio.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_rcc.h"
#include "resources.h"

#include "cli.h"
#include "stdlib.h"


static void hal_uart1_init(uint32_t baud);

static void hal_uart1_init(uint32_t baud) {
	hal_gpio_init_alt(
		&gpio_uart1_tx,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqVeryHigh,
		GpioAltFnUART1);
	hal_gpio_init_alt(
		&gpio_uart1_rx,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqVeryHigh,
		GpioAltFnUART1);

	HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);

	HAL_NVIC_SetPriority(DMA2_Stream7_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);

	/* USART1_RX Init */
	LL_DMA_SetChannelSelection(DMA2, DMA_USART1_RX_STREAM, DMA_USART1_RX_CHANNEL);
	LL_DMA_SetDataTransferDirection(DMA2, DMA_USART1_RX_STREAM, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	LL_DMA_SetStreamPriorityLevel(DMA2, DMA_USART1_RX_STREAM, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA2, DMA_USART1_RX_STREAM, LL_DMA_MODE_CIRCULAR);
	LL_DMA_SetPeriphIncMode(DMA2, DMA_USART1_RX_STREAM, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA2, DMA_USART1_RX_STREAM, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA2, DMA_USART1_RX_STREAM, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA2, DMA_USART1_RX_STREAM, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA2, DMA_USART1_RX_STREAM);

	/* USART1_TX Init */
	LL_DMA_SetChannelSelection(DMA2, DMA_USART1_TX_STREAM, DMA_USART1_TX_CHANNEL);
	LL_DMA_SetDataTransferDirection(DMA2, DMA_USART1_TX_STREAM, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
	LL_DMA_SetStreamPriorityLevel(DMA2, DMA_USART1_TX_STREAM, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA2, DMA_USART1_TX_STREAM, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA2, DMA_USART1_TX_STREAM, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA2, DMA_USART1_TX_STREAM, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA2, DMA_USART1_TX_STREAM, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA2, DMA_USART1_TX_STREAM, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA2, DMA_USART1_TX_STREAM);

	LL_USART_InitTypeDef USART_InitStruct;

	/* USART1 configuration */
	USART_InitStruct.BaudRate = baud;
	USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
	USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
	USART_InitStruct.Parity = LL_USART_PARITY_NONE;
	USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
	USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
	USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;

	LL_USART_Init(USART1, &USART_InitStruct);
	LL_USART_ConfigAsyncMode(USART1);
	LL_USART_Enable(USART1);

	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(USART1_IRQn);
}

/*
void hal_uart_set_baud(UartId ch, uint32_t baud) {
	if(ch == UartIdUSART1) {
		if(LL_USART_IsEnabled(USART1)) {
			while(!LL_USART_IsActiveFlag_TC(USART1));
			LL_USART_Disable(USART1);
			uint32_t uart1_clk = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
			LL_USART_SetBaudRate(USART1, uart1_clk, LL_USART_OVERSAMPLING_16, baud);
			LL_USART_Enable(USART1);
		}
	}
}
*/


void hal_uart_init(UartId ch, uint32_t baud)
{
	if(ch == UartIdUSART1)
		hal_uart1_init(baud);
}

void hal_uart_deinit(UartId ch) {
    if(ch == UartIdUSART1) {
        LL_USART_Disable(USART1);
        hal_gpio_init(&gpio_uart1_tx, GpioModeAnalog, GpioPullNo, GpioSpeedFreqLow);
        hal_gpio_init(&gpio_uart1_rx, GpioModeAnalog, GpioPullNo, GpioSpeedFreqLow);
    }
}

void hal_uart_resume(UartId ch) {
	if(ch == UartIdUSART1) {
		LL_USART_Enable(USART1);
	}
}

void hal_usart_suspend(UartId ch) {
	if(ch == UartIdUSART1 && LL_USART_IsEnabled(USART1)) {
		LL_USART_Disable(USART1);
	}
}


/* polling mode */
void hal_uart_transfer(UartId ch, uint8_t* buf, size_t size) {
    if(ch == UartIdUSART1) {
        if(LL_USART_IsEnabled(USART1) == 0) return;

        while(size > 0) {
            while(!LL_USART_IsActiveFlag_TXE(USART1));
            LL_USART_TransmitData8(USART1, *buf);
            buf++;
            size--;
        }
    }
}

void hal_uart_receive_dma(UartId ch, uint8_t* buf, size_t size) {
//	LL_DMA_EnableStream(DMAx, Stream)
}

void USART1_IRQHandler(void) {

	uint32_t size = 0;

	if(LL_USART_IsActiveFlag_IDLE(USART1)) {
		LL_USART_ClearFlag_IDLE(USART1);

		size = abs(logbuf.tail - (LOG_BUF_SIZE - LL_DMA_GetDataLength(DMA2, LL_DMA_STREAM_2)));
		if(size + logbuf.tail >= LOG_BUF_SIZE) {
			logbuf.is_over_rd = true;
		}

	}
}

void DMA2_Stream2_IRQHandler(void)
{

}


void DMA2_Stream7_IRQHandler(void)
{

}
