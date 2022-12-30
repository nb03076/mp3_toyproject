#ifndef MISC_H_
#define MISC_H_


#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_utils.h"

#ifdef __cplusplus
 extern "C" {
#endif

void hal_clock_config(void);
void ltdc_clock_config(void);


#ifdef __cplusplus
}
#endif

#endif
