#include "icon.h"
#include "u8g2.h"
#include <stdint.h>

/* 8 x 8 */
const uint8_t icon_play[] = {
		0x00, 0x24, 0x3c, 0x3c, 0x3c, 0x3c, 0x24, 0x00
		//0x00, 0x30, 0x38, 0x3e, 0x3e, 0x38, 0x30, 0x00
};

const uint8_t icon_pause[] = {
		0x00, 0x24, 0x3c, 0x3c, 0x3c, 0x3c, 0x24, 0x00
};

void icon_draw_play(u8g2_t* handle, u8g2_uint_t x, u8g2_uint_t y) {
    u8g2_SetDrawColor(handle,1);
    u8g2_SetBitmapMode(handle,1);
    u8g2_DrawBitmap(handle, x, y, 1, 8,  icon_play);
    u8g2_SendBuffer(handle);
}

void icon_draw_pause(u8g2_t* handle, u8g2_uint_t x, u8g2_uint_t y) {
    u8g2_SetDrawColor(handle,1);
    u8g2_SetBitmapMode(handle,1);
    u8g2_DrawBitmap(handle, x, y, 1, 8,  icon_pause);
    u8g2_SendBuffer(handle);
}
