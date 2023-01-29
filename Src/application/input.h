#ifndef APPLICATION_EVENT_INPUT_H_
#define APPLICATION_EVENT_INPUT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	InputTypePress,
	InputTypeRelease,
	InputTypeLong,
	InputTypeNum
}InputType;

typedef struct {
//key, sequence, input type
}InputEvent;


#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_EVENT_INPUT_H_ */
