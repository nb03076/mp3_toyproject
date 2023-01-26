#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "gpio.h"

extern const GpioPin gpio_led_green;
extern const GpioPin gpio_led_red;

extern const GpioPin gpio_uart1_tx;
extern const GpioPin gpio_uart1_rx;

extern const GpioPin gpio_adc1_channel7;

extern const GpioPin gpio_i2c1_scl;
extern const GpioPin gpio_i2c1_sda;
extern const GpioPin gpio_i2c3_scl;
extern const GpioPin gpio_i2c3_sda;

extern const GpioPin gpio_spi2_sck;
extern const GpioPin gpio_spi2_mosi;
extern const GpioPin gpio_spi4_sck;
extern const GpioPin gpio_spi4_mosi;
extern const GpioPin gpio_spi4_miso;

extern const GpioPin gpio_ssd1306_reset;
extern const GpioPin gpio_ssd1306_dc ;
extern const GpioPin gpio_ssd1306_cs;

extern const GpioPin gpio_vs1053_cs;
extern const GpioPin gpio_vs1053_dcs;
extern const GpioPin gpio_vs1053_rst;
extern const GpioPin gpio_vs1053_dreq;

/* led */
#define LED_GREEN_GPIO_PORT GPIOG
#define LED_GREEN_PIN LL_GPIO_PIN_13
#define LED_RED_GPIO_PORT GPIOG
#define LED_RED_PIN LL_GPIO_PIN_14

/* adc */
#define ADC1_CHANNEL7_GPIO_PORT GPIOA
#define ADC1_CHANNEL7_PIN LL_GPIO_PIN_7

/* uart1 */
#define UART1_TX_GPIO_PORT GPIOA
#define UART1_TX_PIN LL_GPIO_PIN_9
#define UART1_RX_GPIO_PORT GPIOA
#define UART1_RX_PIN LL_GPIO_PIN_10

/* i2c */
#define I2C1_SCL_GPIO_PORT GPIOB
#define I2C1_SCL_PIN LL_GPIO_PIN_6
#define I2C1_SDA_GPIO_PORT GPIOB
#define I2C1_SDA_PIN LL_GPIO_PIN_7

#define I2C3_SCL_GPIO_PORT GPIOA
#define I2C3_SCL_PIN LL_GPIO_PIN_8
#define I2C3_SDA_GPIO_PORT GPIOC
#define I2C3_SDA_PIN LL_GPIO_PIN_9

/* spi */
#define SPI2_SCK_GPIO_PORT GPIOB
#define SPI2_SCK_PIN LL_GPIO_PIN_10
#define SPI2_MOSI_GPIO_PORT GPIOC
#define SPI2_MOSI_PIN LL_GPIO_PIN_3

#define SPI4_SCK_GPIO_PORT GPIOE
#define SPI4_SCK_PIN LL_GPIO_PIN_2
#define SPI4_MOSI_GPIO_PORT GPIOE
#define SPI4_MOSI_PIN LL_GPIO_PIN_6
#define SPI4_MISO_GPIO_PORT GPIOE
#define SPI4_MISO_PIN LL_GPIO_PIN_5

/* ssd1306 */
#define SSD1306_RESET_GPIO_PORT GPIOC
#define SSD1306_RESET_PIN LL_GPIO_PIN_0
#define SSD1306_DC_GPIO_PORT GPIOC
#define SSD1306_DC_PIN LL_GPIO_PIN_1
#define SSD1306_CS_GPIO_PORT GPIOC
#define SSD1306_CS_PIN LL_GPIO_PIN_2

/* vs1053 */
#define VS1053_CS_GPIO_PORT GPIOG
#define VS1053_CS_PIN LL_GPIO_PIN_5
#define VS1053_DCS_GPIO_PORT GPIOG
#define VS1053_DCS_PIN LL_GPIO_PIN_6
#define VS1053_RST_GPIO_PORT GPIOG
#define VS1053_RST_PIN LL_GPIO_PIN_7
#define VS1053_DREQ_GPIO_PORT GPIOG
#define VS1053_DREQ_PIN LL_GPIO_PIN_8


/* dma1 */
#define DMA_I2C1_TX_STREAM LL_DMA_STREAM_6
#define DMA_I2C1_TX_CHANNEL LL_DMA_CHANNEL_1
#define DMA_I2C1_RX_STREAM LL_DMA_STREAM_0
#define DMA_I2C1_RX_CHANNEL LL_DMA_CHANNEL_1

#define DMA_SPI2_TX_STREAM LL_DMA_STREAM_4
#define DMA_SPI2_TX_CHANNEL LL_DMA_CHANNEL_0

/* dma2 */
#define DMA_USART1_TX_STREAM LL_DMA_STREAM_7
#define DMA_USART1_TX_CHANNEL LL_DMA_CHANNEL_4
#define DMA_USART1_RX_STREAM LL_DMA_STREAM_2
#define DMA_USART1_RX_CHANNEL LL_DMA_CHANNEL_4

#define DMA_SPI4_TX_STREAM LL_DMA_STREAM_1
#define DMA_SPI4_TX_CHANNEL LL_DMA_CHANNEL_4
#define DMA_SPI4_RX_STREAM LL_DMA_STREAM_0
#define DMA_SPI4_RX_CHANNEL LL_DMA_CHANNEL_4

void hal_resources_init_early(void);
void hal_resources_init(void);

#endif /* RESOURCES_H_ */
