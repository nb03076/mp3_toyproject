#ifndef DELAY_H_
#define DELAY_H_

#include "stm32f4xx.h"
#include <stdbool.h>

typedef struct {
	uint32_t start;
	uint32_t value;
}coretex_timer;


void hal_delay_us(uint32_t microseconds);
coretex_timer hal_get_delay_timer(uint32_t timeout);
bool hal_delay_timer_is_expired(coretex_timer* timer);

#endif /* DELAY_H_ */
