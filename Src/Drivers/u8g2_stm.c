#include "u8g2_stm.h"
#include "u8g2.h"
#include "resources.h"
#include "spi.h"
#include "delay.h"

#define SSD1306_TIMEOUT		100
#define SSD1306_SPIDRV		&spi2drv

// u8g2 gpio & delay control callback
uint8_t u8x8_stm32_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  /* STM32 supports HW SPI, Remove unused cases like U8X8_MSG_DELAY_XXX & U8X8_MSG_GPIO_XXX */
  switch(msg)
  {
  case U8X8_MSG_GPIO_AND_DELAY_INIT:
    /* Insert codes for initialization */
    break;
  case U8X8_MSG_DELAY_MILLI:
    /* ms Delay */
	hal_delay_us(10*arg_int);
    break;
  case U8X8_MSG_GPIO_CS:
    /* Insert codes for SS pin control */
    if(arg_int) {
      LL_GPIO_SetOutputPin(SSD1306_CS_GPIO_PORT, LL_GPIO_PIN_2);
    } else {
      LL_GPIO_ResetOutputPin(SSD1306_CS_GPIO_PORT, LL_GPIO_PIN_2);
    }
    break;
  case U8X8_MSG_GPIO_DC:
    /* Insert codes for DC pin control */
    if(arg_int) {
      LL_GPIO_SetOutputPin(SSD1306_DC_GPIO_PORT, SSD1306_DC_PIN);
    } else {
      LL_GPIO_ResetOutputPin(SSD1306_DC_GPIO_PORT, SSD1306_DC_PIN);
    }
    break;
  case U8X8_MSG_GPIO_RESET:
    /* Insert codes for RST pin control */
    if(arg_int) {
      LL_GPIO_SetOutputPin(SSD1306_RESET_GPIO_PORT, SSD1306_RESET_PIN);
    } else {
      LL_GPIO_ResetOutputPin(SSD1306_RESET_GPIO_PORT, SSD1306_RESET_PIN);
    }
    break;
  }
  return 1;
}

uint8_t u8x8_byte_stm32_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  uint8_t* data = arg_ptr;

  switch(msg) {
  case U8X8_MSG_BYTE_SEND:
    /* Insert codes to transmit data */
	hal_spi_transfer(SSD1306_SPIDRV, data, arg_int, SSD1306_TIMEOUT);
    break;
  case U8X8_MSG_BYTE_INIT:
    /* Insert codes to begin SPI transmission */
    break;
  case U8X8_MSG_BYTE_SET_DC:
    /* Control DC pin, U8X8_MSG_GPIO_DC will be called */
    u8x8_gpio_SetDC(u8x8, arg_int);
    break;
  case U8X8_MSG_BYTE_START_TRANSFER:
    /* Select slave, U8X8_MSG_GPIO_CS will be called */
    u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_enable_level);
    hal_delay_us(100);
    break;
  case U8X8_MSG_BYTE_END_TRANSFER:
	hal_delay_us(100);
    /* Insert codes to end SPI transmission */
    u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_disable_level);
    break;
  default:
    return 0;
  }
  return 1;
}
