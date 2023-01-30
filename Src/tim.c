#include "tim.h"
#include "stm32f4xx_ll_tim.h"
#include "gpio.h"
#include "resources.h"
#include "cli.h"
#include <stdbool.h>

#define TIM_NUMBER 16

static void tim4_init(void);

static volatile TimInterrupt tim_interrupt[TIM_NUMBER];

static void hal_tim_int_call(uint32_t tim);

void hal_tim_start_it(TimID id) {
	switch(id) {
	case TimId4:
		LL_TIM_EnableCounter(TIM4);
		LL_TIM_EnableIT_UPDATE(TIM4);
		break;
	default:
		break;
	}
}

void hal_tim_stop_it(TimID id) {
	switch(id) {
	case TimId4:
		LL_TIM_DisableCounter(TIM4);
		LL_TIM_DisableIT_UPDATE(TIM4);
	}
}

void tim_init(TimID id) {
	switch(id) {
	case TimId4:
		tim4_init();
	//	LL_TIM_EnableCounter(TIM4);
		LL_TIM_ClearFlag_UPDATE(TIM4);
		hal_cli_printf("tim4 init");
		break;

	default:
		hal_cli_printf("timer init argument error");
		break;
	}
}

bool hal_tim_enable_channel(TimID id, uint32_t channel) {
	bool ret = true;

	switch(id) {
	case TimId4:
		LL_TIM_CC_EnableChannel(TIM4, channel);
		break;
	default:
		hal_cli_printf("timer channel enable failed");
		ret = false;
		break;
	}

	return ret;
}

bool hal_tim_set_channel(TimID id, uint32_t channel, uint32_t value) {
	TIM_TypeDef* tim = NULL;
	bool ret = true;

	switch(id) {
	case TimId4:
		tim = TIM4;
		break;
	default:
		tim = NULL;
		ret = false;
		break;
	}

	if(ret != true)
		return ret;

	switch(channel) {
	case LL_TIM_CHANNEL_CH1:
		LL_TIM_OC_SetCompareCH1(tim, value);
		break;
	case LL_TIM_CHANNEL_CH2:
		LL_TIM_OC_SetCompareCH2(tim, value);
		break;
	case LL_TIM_CHANNEL_CH3:
		LL_TIM_OC_SetCompareCH3(tim, value);
		break;
	case LL_TIM_CHANNEL_CH4:
		LL_TIM_OC_SetCompareCH4(tim, value);
		break;
	default:
		hal_cli_printf("tim%d oc channel set value failed", id);
		break;
	}

	return ret;
}

static void tim4_init(void)
{
	LL_TIM_InitTypeDef TIM_InitStruct = {0};
#if 0
	LL_TIM_OC_InitTypeDef TIM_OC_InitStruct = {0};
#endif

	NVIC_SetPriority(TIM4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(TIM4_IRQn);

	/* tim init period = 20ms */
	TIM_InitStruct.Prescaler = 180;
	TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
	TIM_InitStruct.Autoreload = 20000;
	TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
	LL_TIM_Init(TIM4, &TIM_InitStruct);
	LL_TIM_DisableARRPreload(TIM4);
	LL_TIM_SetClockSource(TIM4, LL_TIM_CLOCKSOURCE_INTERNAL);

/* using for rgb led */
#if 0
	/* channel init */
	LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH1);
	TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
	TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
	TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
	TIM_OC_InitStruct.CompareValue = 0;
	TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
	LL_TIM_OC_Init(TIM4, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
	LL_TIM_OC_DisableFast(TIM4, LL_TIM_CHANNEL_CH1);
	LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH2);
	LL_TIM_OC_Init(TIM4, LL_TIM_CHANNEL_CH2, &TIM_OC_InitStruct);
	LL_TIM_OC_DisableFast(TIM4, LL_TIM_CHANNEL_CH2);
	LL_TIM_OC_EnablePreload(TIM4, LL_TIM_CHANNEL_CH3);
	LL_TIM_OC_Init(TIM4, LL_TIM_CHANNEL_CH3, &TIM_OC_InitStruct);
	LL_TIM_OC_DisableFast(TIM4, LL_TIM_CHANNEL_CH3);
	LL_TIM_SetTriggerOutput(TIM4, LL_TIM_TRGO_RESET);
	LL_TIM_DisableMasterSlaveMode(TIM4);

	/* gpio init */
	hal_gpio_init_alt(
		&gpio_tim4_channel1,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqLow,
		GpioAltFnTim4);

	hal_gpio_init_alt(
		&gpio_tim4_channel2,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqLow,
		GpioAltFnTim4);

	hal_gpio_init_alt(
		&gpio_tim4_channel3,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqLow,
		GpioAltFnTim4);

#endif
}

void hal_tim_add_int_callback(uint32_t tim, TimInterruptCallback cb, void* context) {
	taskENTER_CRITICAL();
	tim_interrupt[tim].callback = cb;
	tim_interrupt[tim].context = context;
	tim_interrupt[tim].ready = true;
	taskEXIT_CRITICAL();
}

static void hal_tim_int_call(uint32_t tim) {
	if(tim_interrupt[tim].callback && tim_interrupt[tim].ready) {
		tim_interrupt[tim].callback(tim_interrupt[tim].context);
	}
}


void TIM4_IRQHandler(void) {
	if(LL_TIM_IsActiveFlag_UPDATE(TIM4)) {
		LL_TIM_ClearFlag_UPDATE(TIM4);
	}

	hal_tim_int_call(4);
}
