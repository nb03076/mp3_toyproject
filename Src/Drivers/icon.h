#ifndef DRIVERS_ICON_H_
#define DRIVERS_ICON_H_

#include "u8g2.h"
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

extern const uint8_t icon_play[];
extern const uint8_t icon_pause[];

void icon_draw_play(u8g2_t* handle, u8g2_uint_t x, u8g2_uint_t y);
void icon_draw_pause(u8g2_t* handle, u8g2_uint_t x, u8g2_uint_t y);

#ifdef __cplusplus
}
#endif

#endif /* DRIVERS_ICON_H_ */
