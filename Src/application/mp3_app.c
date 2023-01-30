#include "mp3_app.h"
#include "mp3_player.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "vs1053.h"
#include "timers.h"
#include "adc.h"
#include "cli.h"
#include "tim.h"
#include "gpio.h"
#include "resources.h"

#define VS1053_VOLUME_PERIOD 1000

static TimerHandle_t vs1053_volume_timer;
static TaskHandle_t mp3_taskhandle;
static VolumeLevel prev_volume = VOLUME_OFF;
QueueHandle_t mp3_queuehandle;

static uint8_t convert_volume_level(VolumeLevel vol);

/* sd 카드 api 내부에 있는 hal_delay때문에 ISR 내부에서는 사용못함 */
/* 주기를 30ms 정도로 해도 되나 중간에 화이트 노이즈 때문에 20ms로 두었음 */
/* adafruit 라이브러리는 24ms마다 처리하는걸로 해놨음 */
static void mp3_feed_notify_timcb(void* context) {
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	LL_TIM_ClearFlag_UPDATE(TIM4);
	vTaskNotifyGiveFromISR(mp3_taskhandle, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

static void volume_control_timercb(TimerHandle_t xTimer) {
	uint32_t potentiometer = 0;
	uint8_t volume = 0xFF;

	hal_adc_getdata(1, &potentiometer);
	potentiometer >>= 9; // 12bit adc resolution. only refer to msb 3bit to change the volume

	if(prev_volume != potentiometer) {
		volume = convert_volume_level(potentiometer);
		VS1053_SetVolume(volume, volume);
	}

	prev_volume = potentiometer;
}

static uint8_t convert_volume_level(VolumeLevel vol) {
	uint8_t value;

	switch(vol) {
	case VOLUME_LEVEL_1:
		value = 0x0C;
		break;
	case VOLUME_LEVEL_2:
		value = 0x0A;
		break;
	case VOLUME_LEVEL_3:
		value = 0x08;
		break;
	case VOLUME_LEVEL_4:
		value = 0x06;
		break;
	case VOLUME_LEVEL_5:
		value = 0x04;
		break;
	case VOLUME_LEVEL_6:
		value = 0x02;
		break;
	case VOLUME_LEVEL_7:
		value = 0x00;
		break;
	case VOLUME_OFF:
		value = 0xFF;
		break;
	default:
		value = 0xFF;
		hal_cli_printf("volume level argument error");
		break;
	}

	return value;
}



void mp3Thread(void* param) {
	mp3_taskhandle = xTaskGetCurrentTaskHandle();
	//mp3_queuehandle = xQueueCreate()

	MP3_Init();
	MP3_Play("/mp3/Mercy.mp3");

	vs1053_volume_timer = xTimerCreate(
							"mp3volume",
							pdMS_TO_TICKS(VS1053_VOLUME_PERIOD),
							pdTRUE,
							(void*)0,
							volume_control_timercb);

	if(!vs1053_volume_timer) {
		hal_cli_printf("mp3 volume timer create failed");
		return;
	} else {
		if(xTimerStart(vs1053_volume_timer, 0) != pdPASS) {
			hal_cli_printf("mp3 volume timer start failed");
			return;
		}
	}

	hal_tim_add_int_callback(4, mp3_feed_notify_timcb, NULL);
	hal_tim_start_it(4);

	while(1) {
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		while(!VS1053_IsBusy()) {
			MP3_Feeder();
		}
	}
}
