#include "gpio.h"
#include "core.h"

#define GET_SYSCFG_EXTI_PORT(gpio)					\
	(((gpio) == (GPIOA)) ? LL_SYSCFG_EXTI_PORTA : 	\
	 ((gpio) == (GPIOB)) ? LL_SYSCFG_EXTI_PORTB :	\
	 ((gpio) == (GPIOC)) ? LL_SYSCFG_EXTI_PORTC :	\
	 ((gpio) == (GPIOD)) ? LL_SYSCFG_EXTI_PORTD :	\
	 ((gpio) == (GPIOE)) ? LL_SYSCFG_EXTI_PORTE :	\
	 ((gpio) == (GPIOF)) ? LL_SYSCFG_EXTI_PORTF :	\
	 ((gpio) == (GPIOG)) ? LL_SYSCFG_EXTI_PORTG :	\
			 	 	 	   LL_SYSCFG_EXTI_PORTH)

#define GPIO_PIN_MAP(pin, prefix)				\
	(((pin) == (LL_GPIO_PIN_0))  ? prefix##0  : \
	 ((pin) == (LL_GPIO_PIN_1))  ? prefix##1  : \
	 ((pin) == (LL_GPIO_PIN_2))  ? prefix##2  : \
	 ((pin) == (LL_GPIO_PIN_3))  ? prefix##3  : \
	 ((pin) == (LL_GPIO_PIN_4))  ? prefix##4  : \
	 ((pin) == (LL_GPIO_PIN_5))  ? prefix##5  : \
	 ((pin) == (LL_GPIO_PIN_6))  ? prefix##6  : \
	 ((pin) == (LL_GPIO_PIN_7))  ? prefix##7  : \
	 ((pin) == (LL_GPIO_PIN_8))  ? prefix##8  : \
	 ((pin) == (LL_GPIO_PIN_9))  ? prefix##9  : \
	 ((pin) == (LL_GPIO_PIN_10)) ? prefix##10 : \
	 ((pin) == (LL_GPIO_PIN_11)) ? prefix##11 : \
	 ((pin) == (LL_GPIO_PIN_12)) ? prefix##12 : \
	 ((pin) == (LL_GPIO_PIN_13)) ? prefix##13 : \
	 ((pin) == (LL_GPIO_PIN_14)) ? prefix##14 : \
			 	 	 	 	 	   prefix##15)


#define GET_SYSCFG_EXTI_LINE(pin) GPIO_PIN_MAP(pin, LL_SYSCFG_EXTI_LINE)
#define GET_EXTI_LINE(pin) GPIO_PIN_MAP(pin, LL_EXTI_LINE_)

static volatile GpioInterrupt gpio_interrupt[GPIO_NUMBER];

static uint8_t hal_gpio_get_pin_number(const GpioPin* gpio);
static void hal_gpio_exti_call(uint16_t pin_num);

static uint8_t hal_gpio_get_pin_number(const GpioPin* gpio) {
	uint8_t pin_number;

	for(pin_number = 0; pin_number < GPIO_NUMBER; pin_number++) {
		if(gpio->pin & (1 << pin_number)) break;
	}
	return pin_number;
}

void hal_gpio_init(
    const GpioPin* gpio,
    const GpioMode mode,
    const GpioPull pull,
    const GpioSpeed speed) {
	hal_gpio_init_alt(gpio, mode, pull, speed, GpioAltFnUnused);
}

void hal_gpio_init_alt(
    const GpioPin* gpio,
    const GpioMode mode,
    const GpioPull pull,
    const GpioSpeed speed,
    const GpioAltFn alt_fn) {

	uint32_t syscfg_exti_port = GET_SYSCFG_EXTI_PORT(gpio->port);
	uint32_t syscfg_exti_line = GET_SYSCFG_EXTI_LINE(gpio->pin);
	uint32_t exti_line = GET_EXTI_LINE(gpio->pin);

	switch(speed) {
	case GpioSpeedFreqLow:
		LL_GPIO_SetPinSpeed(gpio->port, gpio->pin, LL_GPIO_SPEED_FREQ_LOW);
		break;
	case GpioSpeedFreqMedium:
		LL_GPIO_SetPinSpeed(gpio->port, gpio->pin, LL_GPIO_SPEED_FREQ_MEDIUM);
		break;
	case GpioSpeedFreqHigh:
		LL_GPIO_SetPinSpeed(gpio->port, gpio->pin, LL_GPIO_SPEED_FREQ_HIGH);
		break;
	case GpioSpeedFreqVeryHigh:
		LL_GPIO_SetPinSpeed(gpio->port, gpio->pin, LL_GPIO_SPEED_FREQ_VERY_HIGH);
		break;
	}

	switch(pull) {
	case GpioPullNo:
		LL_GPIO_SetPinPull(gpio->port, gpio->pin, LL_GPIO_PULL_NO);
		break;
	case GpioPullUp:
		LL_GPIO_SetPinPull(gpio->port, gpio->pin, LL_GPIO_PULL_UP);
		break;
	case GpioPullDown:
		LL_GPIO_SetPinPull(gpio->port, gpio->pin, LL_GPIO_PULL_DOWN);
		break;
	}

	if(mode >= GpioModeInterruptRise) {
		LL_GPIO_SetPinMode(gpio->port, gpio->pin, LL_GPIO_MODE_INPUT);
		LL_SYSCFG_SetEXTISource(syscfg_exti_port, syscfg_exti_line);
		if(mode == GpioModeInterruptRise || mode == GpioModeInterruptRiseFall) {
			LL_EXTI_EnableIT_0_31(exti_line);
			LL_EXTI_EnableRisingTrig_0_31(exti_line);
		}

		if(mode == GpioModeInterruptFall || mode == GpioModeInterruptRiseFall) {
			LL_EXTI_EnableIT_0_31(exti_line);
			LL_EXTI_EnableFallingTrig_0_31(exti_line);
		}

		if(mode == GpioModeEventRise || mode == GpioModeEventRiseFall) {
			LL_EXTI_EnableEvent_0_31(exti_line);
			LL_EXTI_EnableRisingTrig_0_31(exti_line);
		}

		if(mode == GpioModeEventFall || mode == GpioModeEventRiseFall) {
			LL_EXTI_EnableIT_0_31(exti_line);
			LL_EXTI_EnableFallingTrig_0_31(exti_line);
		}
	} else {
		if(LL_SYSCFG_GetEXTISource(syscfg_exti_line) == syscfg_exti_port &&
		   LL_EXTI_IsEnabledIT_0_31(exti_line)) {
			LL_EXTI_DisableIT_0_31(exti_line);
			LL_EXTI_DisableFallingTrig_0_31(exti_line);
			LL_EXTI_DisableRisingTrig_0_31(exti_line);
		}

		if(mode == GpioModeAltFunctionPushPull || mode == GpioModeAltFunctionOpenDrain) {
			if(hal_gpio_get_pin_number(gpio) < 8) {
				LL_GPIO_SetAFPin_0_7(gpio->port, gpio->pin, alt_fn);
			} else {
				LL_GPIO_SetAFPin_8_15(gpio->port, gpio->pin, alt_fn);
			}
		}

		switch(mode) {
		case GpioModeInput:
			LL_GPIO_SetPinMode(gpio->port, gpio->pin, LL_GPIO_MODE_INPUT);
			break;
		case GpioModeOutputPushPull:
			LL_GPIO_SetPinMode(gpio->port, gpio->pin, LL_GPIO_MODE_OUTPUT);
			LL_GPIO_SetPinOutputType(gpio->port, gpio->pin, LL_GPIO_OUTPUT_PUSHPULL);
			break;
		case GpioModeOutputOpenDrain:
			LL_GPIO_SetPinMode(gpio->port, gpio->pin, LL_GPIO_MODE_OUTPUT);
			LL_GPIO_SetPinOutputType(gpio->port, gpio->pin, LL_GPIO_OUTPUT_OPENDRAIN);
			break;
		case GpioModeAltFunctionPushPull:
			LL_GPIO_SetPinMode(gpio->port, gpio->pin, LL_GPIO_MODE_ALTERNATE);
			LL_GPIO_SetPinOutputType(gpio->port, gpio->pin, LL_GPIO_OUTPUT_PUSHPULL);
			break;
		case GpioModeAltFunctionOpenDrain:
			LL_GPIO_SetPinMode(gpio->port, gpio->pin, LL_GPIO_MODE_ALTERNATE);
			LL_GPIO_SetPinOutputType(gpio->port, gpio->pin, LL_GPIO_OUTPUT_OPENDRAIN);
			break;
		case GpioModeAnalog:
			LL_GPIO_SetPinMode(gpio->port, gpio->pin, LL_GPIO_MODE_ANALOG);
			break;
		default:
			break;
		}
	}

}

void hal_gpio_add_exti_callback(const GpioPin* gpio, GpioExtiCallback cb, void* context) {
	uint16_t pin;
	taskENTER_CRITICAL();
	pin = hal_gpio_get_pin_number(gpio);
	gpio_interrupt[pin].callback = cb;
	gpio_interrupt[pin].context = context;
	gpio_interrupt[pin].ready = true;
	taskEXIT_CRITICAL();
}

static void hal_gpio_exti_call(uint16_t pin_num) {
	if(gpio_interrupt[pin_num].callback && gpio_interrupt[pin_num].ready) {
		gpio_interrupt[pin_num].callback(gpio_interrupt[pin_num].context);
	}
}


void EXTI0_IRQHandler(void) {
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_0)) {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
        hal_gpio_exti_call(0);
    }
}

void EXTI1_IRQHandler(void) {
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_1)) {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_1);
        hal_gpio_exti_call(1);
    }
}

void EXTI2_IRQHandler(void) {
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_2)) {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_2);
        hal_gpio_exti_call(2);
    }
}

void EXTI3_IRQHandler(void) {
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3)) {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3);
        hal_gpio_exti_call(3);
    }
}

void EXTI4_IRQHandler(void) {
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_4)) {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_4);
        hal_gpio_exti_call(4);
    }
}


