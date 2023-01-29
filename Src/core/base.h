#ifndef CORE_BASE_H_
#define CORE_BASE_H_

#if 0
/* errno */
typedef enum {
	HalStatusOK = 0,
	HalStatusError = -1,
	HalStatusErrorTimeout = -2,
	HalStatusErrorResrouce = -3
}HalStatus;
#endif

#define IS_IRQ_MODE() (__get_IPSR() != 0U)  // in_interrupt()

#endif /* CORE_BASE_H_ */
