#include <input_app.h>
#include "core.h"
#include "task.h"
#include "resources.h"
#include "gpio.h"
#include "event.h"
#include "queue.h"

static InputEvent input_ev;

static void input_button_exti_cb(void* context) {
	BaseType_t xHigherPriorityTaskWoken;
	int* key = context;

	switch(*key) {
	case InputKeyLeft:
		input_ev.key = InputKeyLeft;
		xQueueSendFromISR(display_queue, &input_ev, &xHigherPriorityTaskWoken);
		break;
	case InputKeyRight:
		input_ev.key = InputKeyRight;
		xQueueSendFromISR(display_queue, &input_ev, &xHigherPriorityTaskWoken);
		break;
	case InputKeyCenter:
		input_ev.key = InputKeyCenter;
		xQueueSendFromISR(display_queue, &input_ev, &xHigherPriorityTaskWoken);
		break;
	case InputKeyUp:
		input_ev.key = InputKeyUp;
		xQueueSendFromISR(display_queue, &input_ev, &xHigherPriorityTaskWoken);
		break;
	case InputKeyDown:
		input_ev.key = InputKeyDown;
		xQueueSendFromISR(display_queue, &input_ev, &xHigherPriorityTaskWoken);
		break;
	default:
		break;
	}

	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}


void inputThread(void* param) {
	for(int i = 0; i < InputKeyNum; i++) {
		hal_gpio_add_exti_callback(input_pins[i].gpio, input_button_exti_cb, &input_pins[i].key);
	}

	input_ev.key = InputKeyNone;
	input_ev.type = InputTypeNone;
	input_ev.arg = 0;

	while(1) {
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
	}
}
