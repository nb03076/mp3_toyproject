#include <input_app.h>
#include "core.h"
#include "task.h"
#include "resources.h"
#include "gpio.h"

static InputEvent button_left_ev;
static InputEvent button_right_ev;
static InputEvent button_center_ev;
static InputEvent button_up_ev;
static InputEvent button_down_ev;

static void input_event_init(InputEvent* ev, const GpioPin* pin) {
	ev->sequence = 0;
	ev->type = InputTypeNone;
	ev->pin = pin;
}

static void input_button_exti_cb(void* context) {

}


void inputThread(void* param) {
	input_event_init(&button_left_ev, &gpio_button_left);
	input_event_init(&button_right_ev, &gpio_button_right);
	input_event_init(&button_center_ev, &gpio_button_center);
	input_event_init(&button_up_ev, &gpio_button_up);
	input_event_init(&button_down_ev, &gpio_button_down);

	for(int i = 0; i < InputKeyNum; i++) {
		hal_gpio_add_exti_callback(input_pins[i].gpio, input_button_exti_cb, NULL);
	}

	while(1) {

	}
}
