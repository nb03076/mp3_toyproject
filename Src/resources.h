#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "gpio.h"

extern const GpioPin gpio_led_green;
extern const GpioPin gpio_led_red;

extern const GpioPin gpio_uart1_tx;
extern const GpioPin gpio_uart1_rx;

#define LED_GREEN_GPIO_PORT GPIOG
#define LED_GREEN_PIN LL_GPIO_PIN_13

#define LED_RED_GPIO_PORT GPIOG
#define LED_RED_PIN LL_GPIO_PIN_14

#define UART1_TX_GPIO_PORT GPIOA
#define UART1_TX_PIN LL_GPIO_PIN_9

#define UART1_RX_GPIO_PORT GPIOA
#define UART1_RX_PIN LL_GPIO_PIN_10


#define DMA_USART1_TX_STREAM LL_DMA_STREAM_7
#define DMA_USART1_TX_CHANNEL LL_DMA_CHANNEL_4

#define DMA_USART1_RX_STREAM LL_DMA_STREAM_2
#define DMA_USART1_RX_CHANNEL LL_DMA_CHANNEL_4

void hal_resources_init_early(void);

#endif /* RESOURCES_H_ */
