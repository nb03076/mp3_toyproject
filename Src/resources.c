#include "resources.h"

const GpioPin gpio_led_green = {.port = LED_GREEN_GPIO_PORT, .pin = LED_GREEN_PIN};
const GpioPin gpio_led_red = {.port = LED_RED_GPIO_PORT, .pin = LED_RED_PIN};

const GpioPin gpio_uart1_tx = {.port = UART1_TX_GPIO_PORT, .pin = UART1_TX_PIN};
const GpioPin gpio_uart1_rx = {.port = UART1_RX_GPIO_PORT, .pin = UART1_RX_PIN};

void hal_resources_init_early(void) {
	hal_gpio_init(&gpio_led_green, GpioModeOutputPushPull, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_led_green, 1);

	hal_gpio_init(&gpio_led_red, GpioModeOutputPushPull, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_led_red, 1);

}
