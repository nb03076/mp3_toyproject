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
#include "input_app.h"
#include "event.h"
#include "fatfs.h"

#define VS1053_VOLUME_PERIOD 1000

static TimerHandle_t vs1053_volume_timer;
static VolumeLevel prev_volume = VOLUME_OFF;
static InputEvent input_rcv, input_send;

static uint8_t convert_volume_level(VolumeLevel vol);

/* sd 카드 api 내부에 있는 hal_delay때문에 ISR 내부에서는 사용못함 */
/* 주기를 20ms로 두었음 */
static void mp3_feed_notify_timcb(void* context) {
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	LL_TIM_ClearFlag_UPDATE(TIM4);
	input_rcv.key = InputKeyNone;
	xQueueSendFromISR(mp3_queue, &input_rcv, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

static void volume_control_timercb(TimerHandle_t xTimer) {
	uint32_t potentiometer = 0;
	uint8_t volume = 0xFF;

	hal_adc_getdata(1, &potentiometer);
	potentiometer >>= 9; // 12bit adc resolution msb 3비트만 참고하여 볼륨 조절

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
	MP3_Init();

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

	input_rcv.key = InputKeyNone;
	input_rcv.type = InputTypeNone;
	input_rcv.arg = 0;

	hal_tim_add_int_callback(4, mp3_feed_notify_timcb, NULL);
	hal_tim_start_it(4);

	while(1) {
		xQueueReceive(mp3_queue, &input_rcv, portMAX_DELAY);

		switch(input_rcv.key) {
		case InputKeyNone:
			while(!VS1053_IsBusy() && MP3_IsPlaying()) {
				MP3_Feeder();
			}
			if(MP3_IsPlaying() == false) {
				input_send.key = InputKeyNone;
				xQueueSend(display_queue, &input_send, 0);
			}
			break;

		case InputKeyCenter:
			if(input_rcv.arg == InputArgSelMp3File) {
				hal_tim_start_it(4);
				MP3_Play();
			} else {
				if(MP3_IsPlaying() == false) {
					hal_tim_start_it(4);
					MP3_Resume();
				} else {
					hal_tim_stop_it(4);
					MP3_Pause();
				}
			}
			input_send.key = InputKeyNone;
			xQueueSend(display_queue, &input_send, 0);
			break;
		default:
			break;
		}
	}
}
