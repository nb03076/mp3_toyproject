#ifndef OS_MUTEX_H_
#define OS_MUTEX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "semphr.h"

#include "error_handler.h"
#include "base.h"

SemaphoreHandle_t* mutex_alloc(void);
HalStatus mutex_lock(SemaphoreHandle_t* instance, uint32_t timeout);
HalStatus mutex_unlock(SemaphoreHandle_t* instance);


#ifdef __cplusplus
}
#endif

#endif /* OS_MUTEX_H_ */
