/*
 * clock.h
 *
 *  Created on: Dec 29, 2022
 *      Author: kang
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "stm32f4xx_ll_bus.h"

void hal_clock_init_early(void);
void hal_clock_deinit_early(void);

#endif /* CLOCK_H_ */
