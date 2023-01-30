#ifndef APPLICATION_EVENT_INPUT_H_
#define APPLICATION_EVENT_INPUT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "gpio.h"

typedef enum {
	InputTypeNone,
	InputTypePress,
	InputTypeRelease,
	InputTypeLong,
	InputTypeNum
}InputType;

typedef struct {
	uint32_t sequence;
	InputType type;
	GpioPin* pin;
}InputEvent;


void inputThread(void* param);


#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_EVENT_INPUT_H_ */
