#ifndef APPLICATION_EVENT_H_
#define APPLICATION_EVENT_H_

#include "FreeRTOS.h"
#include "queue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	DisplayLayerMain,
	DisplayLayerMp3,
	DisplayLayerList,
}DisplayLayer;

extern QueueHandle_t mp3_queue;
extern QueueHandle_t display_queue;

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_EVENT_H_ */
