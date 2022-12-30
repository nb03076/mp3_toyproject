#include "uart.h"
#include "gpio.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_rcc.h"
#include "resources.h"



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

	/* USART1_RX Init */
	LL_DMA_SetChannelSelection(DMA2, DMA_USART1_RX_STREAM, DMA_USART1_RX_CHANNEL);
	LL_DMA_SetDataTransferDirection(DMA2, DMA_USART1_RX_STREAM, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	LL_DMA_SetStreamPriorityLevel(DMA2, DMA_USART1_RX_STREAM, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA2, DMA_USART1_RX_STREAM, LL_DMA_MODE_NORMAL);
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

	LL_USART_EnableIT_RXNE(USART1);

	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(USART1_IRQn);
}

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



void hal_uart_init(UartId ch, uint32_t baud)
{
	if(ch == UartIdUSART1)
		hal_uart1_init(baud);
}

void hal_uart_deinit(UartId ch) {
//    furi_hal_uart_set_irq_cb(ch, NULL, NULL);
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



void USART1_IRQHandler(void) {

}

void DMA2_Stream2_IRQHandler(void)
{

}

void DMA2_Stream7_IRQHandler(void)
{

}
