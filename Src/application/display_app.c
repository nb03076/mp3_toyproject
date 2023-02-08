#include "core.h"
#include "timers.h"
#include "display_app.h"
#include "u8g2.h"
#include "u8g2_stm.h"
#include "icon.h"
#include "ds3231.h"
#include "cli.h"
#include <stdio.h>
#include <string.h>
#include "input_app.h"
#include "event.h"
#include "mp3_player.h"
#include "fatfs.h"

#define RTC_TIMER_PERIOD 1000
#define DISPLAY_MP3LIST_ROW 4

/* u8g2 handle */
static u8g2_t u8g2;

/* RTOS variable */
static TimerHandle_t rtc_timer;

/* FATFS variable */
static FATFS mp3fatfs;
static DIR mp3dir;

/* queue event */
static InputEvent input_send;
static InputEvent input_rcv;

/* display layer */
static DisplayLayer current_layer;

/* rtc time info */
static ds3231_time_t ds3231_time;

/* mp3 file list */
static char mp3list[16][25];
static int mp3list_maxnum = 0, mp3list_selnum = 0;

/* display buffer */
static char rtc_string[50];
static char filename_buf[25] = {};

static void display_mp3list(u8g2_t* u8g2_handle);
static void MP3_SetFileList(DIR *dir);
static void display_clock(void);
static void display_mp3select(void);

static void display_clock(void) {
    u8g2_SetFont(&u8g2, u8g2_font_5x8_tf);
	u8g2_DrawStr(&u8g2, 0, 10, rtc_string);
	u8g2_SendBuffer(&u8g2);
}

static void display_mp3screen(void) {
	u8g2_ClearBuffer(&u8g2);
	display_clock();
    u8g2_SetFont(&u8g2, u8g2_font_5x8_tf);
	sprintf(filename_buf, "%s", mp3list[mp3list_selnum]);
	u8g2_DrawStr(&u8g2, 0, 40, filename_buf);
	u8g2_SendBuffer(&u8g2);
}

static void display_mp3select(void) {
	int num = mp3list_selnum % DISPLAY_MP3LIST_ROW;

    u8g2_SetFont(&u8g2, u8g2_font_5x8_tf);
    u8g2_DrawFrame(&u8g2, 5, 17 + 10 * num, 118, 10);
	u8g2_SendBuffer(&u8g2);
}

static void MP3_SetFileList(DIR *dir) {
	int i = 0;

	FILINFO info;

	while(1) {
		f_readdir(dir, &info);
		if(info.fname[0] == '\0') break;
		snprintf(mp3list[i], 25, info.fname);
		i++;

		if(i>=15) break;
	}

	mp3list_maxnum = i - 1;
}

static void display_mp3list(u8g2_t* u8g2_handle) {
	int i = mp3list_selnum / 4 * 4;
	int num = 0;

    u8g2_SetFont(u8g2_handle, u8g2_font_5x8_tf);
    u8g2_ClearBuffer(u8g2_handle);

	while(mp3list[i] != NULL && num < DISPLAY_MP3LIST_ROW) {
		u8g2_DrawStr(u8g2_handle, 10, 25 + 10*num, mp3list[i]);
		i++;
		num++;
	}

	display_clock();
	u8g2_SendBuffer(u8g2_handle);
}


static void btn_center_handler(void) {
	input_send.type = InputTypePress;
	input_send.key = InputKeyCenter;
	input_send.arg = 0;

	switch(current_layer) {
	case DisplayLayerList:
		current_layer = DisplayLayerMp3;
		input_send.arg = InputArgSelMp3File;
		MP3_SetFile(mp3list[mp3list_selnum]);
		display_mp3screen();
		xQueueSend(mp3_queue, &input_send, 0);
		break;

	case DisplayLayerMp3:
		input_send.arg = InputArgMp3PlayPause;
		xQueueSend(mp3_queue, &input_send, 0);
		break;

	default:
		break;
	}
}

static void btn_up_handler(void) {
	switch(current_layer) {
	case DisplayLayerList:
		if(mp3list_selnum == 0) {
			mp3list_selnum = mp3list_maxnum;
		} else {
			mp3list_selnum--;
		}
		display_mp3list(&u8g2);
		display_mp3select();
		break;

	case DisplayLayerMp3:
		current_layer = DisplayLayerList;
		display_mp3list(&u8g2);
		display_mp3select();
		break;

	default:
		break;
	}
}

static void btn_down_handler(void) {
	switch(current_layer) {
	case DisplayLayerList:
		if(mp3list_selnum >= mp3list_maxnum) {
			mp3list_selnum = 0;
		} else {
			mp3list_selnum++;
		}
		display_mp3list(&u8g2);
		display_mp3select();
		break;

	case DisplayLayerMp3:
		current_layer = DisplayLayerList;
		display_mp3list(&u8g2);
		display_mp3select();
		break;

	default:
		break;
	}
}

static void btn_left_handler(void) {
	switch(current_layer) {
	case DisplayLayerList:
		current_layer = DisplayLayerMp3;
		display_mp3screen();
		break;

	case DisplayLayerMp3:
		break;

	default:
		break;
	}
}

static void btn_right_handler(void) {
	switch(current_layer) {
	case DisplayLayerList:
		current_layer = DisplayLayerMp3;
		display_mp3screen();
		break;

	case DisplayLayerMp3:
		break;

	default:
		break;
	}
}


static void refresh_rtc_timercb (TimerHandle_t xTimer) {
	ds3231_get_time(&ds3231_time);
    u8g2_SetFont(&u8g2, u8g2_font_5x8_tf);
	sprintf(rtc_string, "%d/%d %s %d:%d:%d", ds3231_time.month, ds3231_time.date, ds3231_day_to_string(ds3231_time.day),
			ds3231_time.hour, ds3231_time.min, ds3231_time.sec);
	u8g2_DrawStr(&u8g2, 0, 10, rtc_string);
	u8g2_SendBuffer(&u8g2);
}

void displayThread(void* param) {
	current_layer = DisplayLayerList;

	u8g2_Setup_ssd1306_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_stm32_hw_spi, u8x8_stm32_gpio_and_delay);
	u8g2_InitDisplay(&u8g2);
	u8g2_SetPowerSave(&u8g2, 0);

	ds3231_register_driver(&i2c1drv);

	rtc_timer = xTimerCreate("rtc",
							pdMS_TO_TICKS(RTC_TIMER_PERIOD),
							pdTRUE,
							(void*)0,
							refresh_rtc_timercb);

	if(rtc_timer == NULL) {
		hal_cli_printf("rtc timer create failed");
		return;
	} else {
		if(xTimerStart(rtc_timer, 0) != pdPASS) {
			hal_cli_printf("rtc timer start failed");
			return;
		}
	}

	f_mount(&mp3fatfs, "", 1);
	f_opendir(&mp3dir, "/mp3");
	MP3_SetFileList(&mp3dir);
	display_mp3list(&u8g2);

    icon_draw_pause(&u8g2, 120, 0);

	while(1) {
		xQueueReceive(display_queue, &input_rcv, portMAX_DELAY);

		switch(input_rcv.key) {
		case InputKeyCenter:
			btn_center_handler();
			break;
		case InputKeyUp:
			btn_up_handler();
			break;
		case InputKeyDown:
			btn_down_handler();
			break;
		case InputKeyLeft:
			btn_left_handler();
			break;
		case InputKeyRight:
			btn_right_handler();
			break;

		default:
			break;
		}
	}
}
