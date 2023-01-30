#include "resources.h"

const GpioPin gpio_led_green = {.port = LED_GREEN_GPIO_PORT, .pin = LED_GREEN_PIN};
const GpioPin gpio_led_red = {.port = LED_RED_GPIO_PORT, .pin = LED_RED_PIN};

const GpioPin gpio_button_left = {.port = BUTTON_LEFT_GPIO_PORT, .pin = BUTTON_LEFT_PIN};
const GpioPin gpio_button_right = {.port = BUTTON_RIGHT_GPIO_PORT, .pin = BUTTON_RIGHT_PIN};
const GpioPin gpio_button_center = {.port = BUTTON_CENTER_GPIO_PORT, .pin = BUTTON_CENTER_PIN};
const GpioPin gpio_button_up = {.port = BUTTON_UP_GPIO_PORT, .pin = BUTTON_UP_PIN};
const GpioPin gpio_button_down = {.port = BUTTON_DOWN_GPIO_PORT, .pin = BUTTON_DOWN_PIN};

const GpioPin gpio_adc1_channel7 = {.port = ADC1_CHANNEL7_GPIO_PORT, .pin = ADC1_CHANNEL7_PIN};

const GpioPin gpio_tim4_channel1 = {.port = TIM4_CHANNEL1_GPIO_PORT, .pin = TIM4_CHANNEL1_PIN};
const GpioPin gpio_tim4_channel2 = {.port = TIM4_CHANNEL2_GPIO_PORT, .pin = TIM4_CHANNEL2_PIN};
const GpioPin gpio_tim4_channel3 = {.port = TIM4_CHANNEL3_GPIO_PORT, .pin = TIM4_CHANNEL3_PIN};

const GpioPin gpio_uart1_tx = {.port = UART1_TX_GPIO_PORT, .pin = UART1_TX_PIN};
const GpioPin gpio_uart1_rx = {.port = UART1_RX_GPIO_PORT, .pin = UART1_RX_PIN};

const GpioPin gpio_i2c1_scl = {.port = I2C1_SCL_GPIO_PORT, .pin = I2C1_SCL_PIN};
const GpioPin gpio_i2c1_sda = {.port = I2C1_SDA_GPIO_PORT, .pin = I2C1_SDA_PIN};
const GpioPin gpio_i2c3_scl = {.port = I2C3_SCL_GPIO_PORT, .pin = I2C3_SCL_PIN};
const GpioPin gpio_i2c3_sda = {.port = I2C3_SDA_GPIO_PORT, .pin = I2C3_SDA_PIN};

const GpioPin gpio_spi2_sck = {.port = SPI2_SCK_GPIO_PORT, .pin = SPI2_SCK_PIN};
const GpioPin gpio_spi2_mosi = {.port = SPI2_MOSI_GPIO_PORT, .pin = SPI2_MOSI_PIN};
const GpioPin gpio_spi4_sck = {.port = SPI4_SCK_GPIO_PORT, .pin = SPI4_SCK_PIN};
const GpioPin gpio_spi4_mosi = {.port = SPI4_MOSI_GPIO_PORT, .pin = SPI4_MOSI_PIN};
const GpioPin gpio_spi4_miso = {.port = SPI4_MISO_GPIO_PORT, .pin = SPI4_MISO_PIN};

const GpioPin gpio_ssd1306_reset = {.port = SSD1306_RESET_GPIO_PORT, .pin = SSD1306_RESET_PIN};
const GpioPin gpio_ssd1306_dc = {.port = SSD1306_DC_GPIO_PORT, .pin = SSD1306_DC_PIN};
const GpioPin gpio_ssd1306_cs = {.port = SSD1306_CS_GPIO_PORT, .pin = SSD1306_CS_PIN};

const GpioPin gpio_vs1053_cs = {.port = VS1053_CS_GPIO_PORT, .pin = VS1053_CS_PIN};
const GpioPin gpio_vs1053_dcs = {.port = VS1053_DCS_GPIO_PORT, .pin = VS1053_DCS_PIN};
const GpioPin gpio_vs1053_rst = {.port = VS1053_RST_GPIO_PORT, .pin = VS1053_RST_PIN};
const GpioPin gpio_vs1053_dreq = {.port = VS1053_DREQ_GPIO_PORT, .pin = VS1053_DREQ_PIN};

const InputPin input_pins[] = {
		{.gpio = &gpio_button_left, .key = InputKeyLeft},
		{.gpio = &gpio_button_right, .key = InputKeyRight},
		{.gpio = &gpio_button_center, .key = InputKeyCenter},
		{.gpio = &gpio_button_up, .key = InputKeyUp},
		{.gpio = &gpio_button_down, .key = InputKeyDown},
};

void hal_resources_init_early(void) {
	/* led */
	hal_gpio_init(&gpio_led_green, GpioModeOutputPushPull, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_led_green, 1);
	hal_gpio_init(&gpio_led_red, GpioModeOutputPushPull, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_led_red, 1);
}

void hal_resources_init(void) {
	/* button */
	hal_gpio_init(&gpio_button_left, GpioModeInterruptFall, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_init(&gpio_button_right, GpioModeInterruptFall, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_init(&gpio_button_center, GpioModeInterruptFall, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_init(&gpio_button_up, GpioModeInterruptFall, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_init(&gpio_button_down, GpioModeInterruptFall, GpioPullUp, GpioSpeedFreqLow);

	NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_SetPriority(EXTI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	NVIC_SetPriority(EXTI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_SetPriority(EXTI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(EXTI4_IRQn);

	/* ssd1306 */
	hal_gpio_init(&gpio_ssd1306_reset, GpioModeOutputPushPull, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_ssd1306_reset, 1);
	hal_gpio_init(&gpio_ssd1306_dc, GpioModeOutputPushPull, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_ssd1306_dc, 1);
	hal_gpio_init(&gpio_ssd1306_cs, GpioModeOutputPushPull, GpioPullUp, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_ssd1306_cs, 1);

	/* vs1053 */
	hal_gpio_init(&gpio_vs1053_cs, GpioModeOutputPushPull, GpioPullNo, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_vs1053_dcs, 1);
	hal_gpio_init(&gpio_vs1053_dcs, GpioModeOutputPushPull, GpioPullNo, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_vs1053_dcs, 1);
	hal_gpio_init(&gpio_vs1053_rst, GpioModeOutputPushPull, GpioPullNo, GpioSpeedFreqLow);
	hal_gpio_write(&gpio_vs1053_rst, 1);
	hal_gpio_init(&gpio_vs1053_dreq, GpioModeInput, GpioPullNo, GpioSpeedFreqLow);
}
