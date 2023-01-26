#ifndef DRIVERS_U8G2_STM_H_
#define DRIVERS_U8G2_STM_H_

#include "u8g2.h"

#ifdef __cplusplus
 extern "C" {
#endif

uint8_t u8x8_stm32_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8x8_byte_stm32_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);


#ifdef __cplusplus
}
#endif
#endif /* DRIVERS_U8G2_STM_H_ */
