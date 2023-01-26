#include "stm32f4xx_ll_adc.h"
#include "adc.h"
#include "cli.h"
#include "delay.h"
#include "resources.h"
#include <stdbool.h>

#define ADC1_CONVERSION_TIMEOUT 1000

static void adc1_init(void);

void adc_init(AdcID id) {
	switch(id) {
	case AdcId1:
		adc1_init();
		LL_ADC_Enable(ADC1);
		hal_cli_printf("adc1 init");
		break;

	default:
		hal_cli_printf("adc%d not exist",id);
		break;
	}
}

bool hal_adc_getdata(AdcID id, uint32_t* data) {
	coretex_timer timer;
	timer = hal_get_delay_timer(ADC1_CONVERSION_TIMEOUT);

	switch(id) {
		case AdcId1:
			LL_ADC_REG_StartConversionSWStart(ADC1);
			while(!LL_ADC_IsActiveFlag_EOCS(ADC1)) {
				if(hal_delay_timer_is_expired(&timer))
					return false;
			}
			*data = LL_ADC_REG_ReadConversionData12(ADC1);
			break;

		default:
			hal_cli_printf("EINVAL : %s %d",__FILE__,__LINE__);
			return false;
			break;
	}

	return true;
}

static void adc1_init(void)
{
  LL_ADC_InitTypeDef ADC_InitStruct = {0};
  LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = {0};
  LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = {0};

  hal_gpio_init(&gpio_adc1_channel7, GpioModeAnalog, GpioPullNo, GpioSpeedFreqLow);

  ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_12B;
  ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
  ADC_InitStruct.SequencersScanMode = LL_ADC_SEQ_SCAN_DISABLE;
  LL_ADC_Init(ADC1, &ADC_InitStruct);
  ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
  ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_DISABLE;
  ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
  ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
  ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_NONE;
  LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);
  LL_ADC_REG_SetFlagEndOfConversion(ADC1, LL_ADC_REG_FLAG_EOC_UNITARY_CONV);
  ADC_CommonInitStruct.CommonClock = LL_ADC_CLOCK_SYNC_PCLK_DIV4;
  ADC_CommonInitStruct.Multimode = LL_ADC_MULTI_INDEPENDENT;
  LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC1), &ADC_CommonInitStruct);


  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_7);
  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_7, LL_ADC_SAMPLINGTIME_3CYCLES);
}
