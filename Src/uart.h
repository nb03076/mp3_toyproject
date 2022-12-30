#ifndef UART_H_
#define UART_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_ll_usart.h"
#include <stddef.h>

typedef enum {
	UartIdUSART1
}UartId;


void hal_uart_init(UartId ch, uint32_t baud);
void hal_uart_set_baud(UartId ch, uint32_t baud);
void hal_uart_deinit(UartId ch);

void hal_uart_resume(UartId ch);
void hal_usart_suspend(UartId ch);

void hal_uart_transfer(UartId ch, uint8_t* buf, size_t size);

void USART1_IRQHandler(void);
void DMA2_Stream2_IRQHandler(void);
void DMA2_Stream7_IRQHandler(void);

#ifdef __cplusplus
}
#endif
#endif /* UART_H_ */
