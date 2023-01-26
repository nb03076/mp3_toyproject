#ifndef CORE_CORE_H_
#define CORE_CORE_H_

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "base.h"
#include "delay.h"

#ifdef __cplusplus
extern "C" {
#endif

void ErrorHandler(void);

SemaphoreHandle_t* mutex_alloc(void);
HalStatus mutex_lock(SemaphoreHandle_t* instance, uint32_t timeout);
HalStatus mutex_unlock(SemaphoreHandle_t* instance);

#ifdef __cplusplus
}
#endif

#endif /* CORE_CORE_H_ */
