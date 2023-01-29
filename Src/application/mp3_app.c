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

#define VS1053_VOLUME_PERIOD 1000

static TimerHandle_t vs1053_volume_timer;
static VolumeLevel prev_volume = VOLUME_OFF;

static uint8_t convert_volume_level(VolumeLevel vol);

#if 0
sd 카드 api 내부에 있는 hal_delay때문에 ISR 내부에서는 사용못하는듯
static void mp3_feed_timcb(void* context) {
	if(MP3_is_playing())
		MP3_Feeder();
}
#endif

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
	hal_cli_printf("%d", VS1053_GetDecodeTime()/256);
}

void mp3Thread(void* param) {
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

	while(1) {
		MP3_Feeder();
	}
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
