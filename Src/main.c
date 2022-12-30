#include "FreeRTOS.h"
#include "task.h"
#include "lvgl.h"

#include "clock.h"
#include "resources.h"
#include "misc.h"
#include "i2c.h"
#include "spi.h"
#include "gpio.h"
#include "uart.h"

void testThread(void* param) {
	while(1) {
		vTaskDelay(1000);
		hal_gpio_toggle(&gpio_led_red);
		hal_gpio_toggle(&gpio_led_green);
	}
}

int main(void) {
	HAL_Init();
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    DWT->CYCCNT = 0U;

	hal_clock_init_early();
	hal_clock_config();
	ltdc_clock_config();

	hal_resources_init_early();

	hal_uart_init(UartIdUSART1, 115200);

	uint8_t buffer[] = "hello world!\r\n";
	hal_uart_transfer(UartIdUSART1, buffer, sizeof(buffer));

	traceSTART();
	xTaskCreate(testThread, "test", 128, NULL, 3, NULL);
	vTaskStartScheduler();

	for(;;);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
}


/*********************************************************************
*
*       vApplicationMallocFailedHook
*
*  Function description
*    Called if a call to pvPortMalloc() fails because there
*    is insufficient free memory available in the FreeRTOS heap.
*    pvPortMalloc() is called internally by FreeRTOS API functions
*    that create tasks, queues, software timers, and semaphores.
*    The size of the FreeRTOS heap is set by the configTOTAL_HEAP_SIZE
*    configuration constant in FreeRTOSConfig.h
*
*/

void vApplicationMallocFailedHook(void) {
  taskDISABLE_INTERRUPTS();
  for( ;; );
}

/*********************************************************************
*
*       vApplicationStackOverflowHook
*
*  Function description
*    Run time stack overflow checking is performed if
*    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.
*    This hook function is called if a stack overflow is detected.
*/
void vApplicationStackOverflowHook(TaskHandle_t xTask, char * pcTaskName) {
  ( void ) pcTaskName;
  ( void ) xTask;
  taskDISABLE_INTERRUPTS();
  for( ;; );
}

/*********************************************************************
*
*       vApplicationIdleHook
*
*  Function description
*    This function is called on each cycle of the idle task.
*    In this case it does nothing useful, other than report
*    the amount of FreeRTOS heap that remains unallocated.
*
*/

void vApplicationIdleHook(void) {
#if configSUPPORT_DYNAMIC_ALLOCATION == 1
  volatile size_t xFreeHeapSpace;

  xFreeHeapSpace = xPortGetFreeHeapSize();
  if( xFreeHeapSpace > 100 ) {
    //
    // By now, the kernel has allocated everything it is going to, so
    // if there is a lot of heap remaining unallocated then
    // the value of configTOTAL_HEAP_SIZE in FreeRTOSConfig.h can be
    // reduced accordingly.
  }
#endif
}

/*********************************************************************
*
*       vMainConfigureTimerForRunTimeStats
*
*  Function description
*    The Blinky build configuration does not include run time
*    stats gathering, however, the Full and Blinky build configurations
*    share a FreeRTOSConfig.h file.
*    Therefore, dummy run time stats functions need to be defined
*    to keep the linker happy.
*
*/

void vMainConfigureTimerForRunTimeStats(void) {
}

/*********************************************************************
*
*       ulMainGetRunTimeCounterValue
*
*/

unsigned long ulMainGetRunTimeCounterValue(void) {
  return 0UL;
}

/*********************************************************************
*
*       vApplicationTickHook
*
*  Function description
*    A tick hook is used by the "Full" build configuration.
*    The Full and blinky build configurations share a FreeRTOSConfig.h
*    header file, so this simple build configuration also has to define
*    a tick hook - even though it does not actually use it for anything.
*
*/


void vApplicationTickHook(void) {
}

/*********************************************************************
*
*       vApplicationGetIdleTaskMemory()
*
*/
#if configSUPPORT_STATIC_ALLOCATION == 1
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize ) {
  /* If the buffers to be provided to the Idle task are declared inside this
  function then they must be declared static - otherwise they will be allocated on
  the stack and so not exists after this function exits. */
  static StaticTask_t xIdleTaskTCB;
  static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

  /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
  state will be stored. */
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

  /* Pass out the array that will be used as the Idle task's stack. */
  *ppxIdleTaskStackBuffer = uxIdleTaskStack;

  /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
  Note that, as the array is necessarily of type StackType_t,
  configMINIMAL_STACK_SIZE is specified in words, not bytes. */
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
#endif

/*********************************************************************
*
*       vApplicationGetTimerTaskMemory()
*
*/
/*-----------------------------------------------------------*/

#if configSUPPORT_STATIC_ALLOCATION == 1
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize ) {
  /* If the buffers to be provided to the Timer task are declared inside this
  function then they must be declared static - otherwise they will be allocated on
  the stack and so not exists after this function exits. */
  static StaticTask_t xTimerTaskTCB;
  static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

  /* Pass out a pointer to the StaticTask_t structure in which the Timer
  task's state will be stored. */
  *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

  /* Pass out the array that will be used as the Timer task's stack. */
  *ppxTimerTaskStackBuffer = uxTimerTaskStack;

  /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
  Note that, as the array is necessarily of type StackType_t,
  configMINIMAL_STACK_SIZE is specified in words, not bytes. */
  *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}
#endif

