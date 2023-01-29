#ifndef TIM_H_
#define TIM_H_

#include "stm32f4xx_ll_tim.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*TimInterruptCallback)(void *context);

typedef struct {
	TimInterruptCallback callback;
	void* context;
	volatile bool ready;
}TimInterrupt;

typedef enum {
	TimId4 = 4,
}TimID;

void tim_init(TimID id);
bool hal_tim_set_channel(TimID id, uint32_t channel, uint32_t value);
void hal_tim_add_int_callback(uint32_t tim, TimInterruptCallback cb, void* context);
void hal_tim_start_it(TimID id);
void hal_tim_stop_it(TimID id);

#ifdef __cplusplus
}
#endif

#endif /* TIM_H_ */
