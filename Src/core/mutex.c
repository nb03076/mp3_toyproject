#include "mutex.h"

SemaphoreHandle_t* mutex_alloc(void)
{
	SemaphoreHandle_t mutex = NULL;

	mutex = xSemaphoreCreateMutex();
	if(!mutex){
		Error_Handler();
	}

	return (SemaphoreHandle_t*) mutex;
}

HalStatus mutex_lock(SemaphoreHandle_t* instance, uint32_t timeout)
{
	HalStatus status;

	status = HalStatusOK;

	if(xSemaphoreTake(instance, timeout) != pdPASS){
		if(timeout!=0){
			status = HalStatusErrorTimeout;
		} else {
			status = HalStatusErrorResrouce;
		}
	}

	return (status);
}

HalStatus mutex_unlock(SemaphoreHandle_t* instance)
{
	HalStatus status;

	status = HalStatusOK;

	if(xSemaphoreGive(instance) != pdPASS){
		status = HalStatusErrorResrouce;
	}

	return (status);
}
