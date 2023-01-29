#include "core.h"
#include "timers.h"
#include "display_app.h"
#include "u8g2.h"
#include "u8g2_stm.h"
#include "icon.h"
#include "ds3231.h"
#include "cli.h"

#define RTC_TIMER_PERIOD 1000

static u8g2_t u8g2;
static ds3231_time_t ds3231_time;
static TimerHandle_t rtc_timer;

static void refresh_rtc_timercb (TimerHandle_t xTimer) {
	ds3231_get_time(&ds3231_time);
}

void displayThread(void* param) {
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


	while(1) {
	    u8g2_FirstPage(&u8g2);
	    icon_draw_play(&u8g2, 0, 0);
	    icon_draw_pause(&u8g2, 120, 0);

#if 0
	    u8g2_SetFont(&u8g2, u8g2_font_6x13B_tf);
	    u8g2_DrawStr(&u8g2, 1, 14, "hello world!");
#endif
		taskYIELD();
	}
}
