#ifndef APPLICATION_EVENT_INPUT_H_
#define APPLICATION_EVENT_INPUT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "gpio.h"
#include "resources.h"
#include "display_app.h"

typedef enum {
	InputTypeNone,
	InputTypePress,
	InputTypeRelease,
	InputTypeLong,
	InputTypeNum
}InputType;

typedef struct {
	InputKey key;
	InputType type;
	uint32_t arg;
}InputEvent;

typedef enum {
	InputArgNone,
	InputArgSelMp3File,
	InputArgMp3PlayPause,
}InputArg;


void inputThread(void* param);


#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_EVENT_INPUT_H_ */
