#include "delay.h"
#include <stdbool.h>

void hal_delay_us(uint32_t microseconds) {
    uint32_t start = DWT->CYCCNT;
    uint32_t time_ticks = (SystemCoreClock / 1000000) * microseconds;
    while((DWT->CYCCNT - start) < time_ticks) {
    };
}

coretex_timer hal_get_delay_timer(uint32_t timeout) {
	coretex_timer tmp;
	tmp.start = DWT->CYCCNT;
	tmp.value = (SystemCoreClock / 1000) * timeout;
	return tmp;
}

bool hal_delay_timer_is_expired(coretex_timer* timer)
{
	return !(DWT->CYCCNT - timer->start < timer->value);
}
