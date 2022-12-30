#ifndef __TFT_H
#define __TFT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include "stm_lvgl_include.h"
#include "tft_config.h"
#include "ltdc.h"
#include "ili9341.h"
#include "stm32f4xx_ll_dma.h"

#if TFT_EXT_FB != 0
	#include "sdram.h"
#endif

void tft_init(void);
void tft_dma_flush_transfer(DMA_HandleTypeDef *han);

#ifdef __cplusplus
}
#endif

#endif
