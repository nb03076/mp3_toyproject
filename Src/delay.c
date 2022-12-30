/*
 * delay.c
 *
 *  Created on: Dec 29, 2022
 *      Author: kang
 */

#include "delay.h"

void delay_us(uint32_t microseconds) {
    uint32_t start = DWT->CYCCNT;
    uint32_t time_ticks = (SystemCoreClock / 1000000) * microseconds;
    while((DWT->CYCCNT - start) < time_ticks) {
    };
}
