#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"

#include <stdbool.h>

#include "core.h"


#define GPIO_NUMBER (16U)


typedef void (*GpioExtiCallback)(void* ctx);

typedef struct {
	GPIO_TypeDef* port;
	uint16_t pin;
}GpioPin;

typedef struct {
	GpioExtiCallback callback;
	void* context;
	volatile bool ready;
}GpioInterrupt;

typedef enum {
    GpioModeInput,
    GpioModeOutputPushPull,
    GpioModeOutputOpenDrain,
    GpioModeAltFunctionPushPull,
    GpioModeAltFunctionOpenDrain,
    GpioModeAnalog,
    GpioModeInterruptRise,
    GpioModeInterruptFall,
    GpioModeInterruptRiseFall,
    GpioModeEventRise,
    GpioModeEventFall,
    GpioModeEventRiseFall,
} GpioMode;

typedef enum{
	GpioPullNo,
	GpioPullUp,
	GpioPullDown
}GpioPull;

typedef enum{
	GpioSpeedFreqLow,
	GpioSpeedFreqMedium,
	GpioSpeedFreqHigh,
	GpioSpeedFreqVeryHigh
}GpioSpeed;

typedef enum{
	GpioAltFnUART1 = LL_GPIO_AF_7,
	GpioAltFnI2C1 = LL_GPIO_AF_4,
	GpioAltFnI2C3 = LL_GPIO_AF_4,
	GpioAltFnSpi2 = LL_GPIO_AF_5,
	GpioAltFnSpi4 = LL_GPIO_AF_5,
	GpioAltFnTim4 = LL_GPIO_AF_2,
	GpioAltFnUnused = 16
}GpioAltFn;




void hal_gpio_init(const GpioPin* gpio, const GpioMode mode, const GpioPull pull, const GpioSpeed speed);
void hal_gpio_init_alt(const GpioPin* gpio, const GpioMode mode, const GpioPull pull, const GpioSpeed speed, const GpioAltFn alt_fn);

static inline void hal_gpio_write(const GpioPin* gpio, const bool state) {
    if(state == true) {
        gpio->port->BSRR = gpio->pin;
    } else {
        gpio->port->BSRR = (uint32_t)gpio->pin << GPIO_NUMBER;
    }
}

static inline bool hal_gpio_read(const GpioPin* gpio) {
	if((gpio->port->IDR & gpio->pin) != 0x00U) {
		return true;
	} else {
		return false;
	}
}

static inline uint32_t hal_gpio_readpin(const GpioPin* gpio) {
	return LL_GPIO_IsInputPinSet(gpio->port, gpio->pin);
}

static inline void hal_gpio_toggle(const GpioPin* gpio) {
	uint32_t odr = gpio->port->ODR;
	gpio->port->BSRR = ((odr & gpio->pin) << 16u) | (~odr & gpio->pin);
}

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

