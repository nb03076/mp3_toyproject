#ifndef CLI_H_
#define CLI_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "uart.h"
#include <stdbool.h>

#define LOG_BUF_SIZE (256U)

typedef enum {
	LOG_IDLE,
	LOG_BUSY,
	LOG_FULL
}LogState;

typedef struct {
	uint8_t wd_buf[LOG_BUF_SIZE];
 	uint8_t rd_buf[LOG_BUF_SIZE];
 	uint32_t head,tail;
 	bool is_over_rd;
 	uint32_t prev_rd_size;
 	LogState state;
}UartLogBuf_t;

extern UartLogBuf_t logbuf;

void hal_cli_printf(const char* fmt, ...);
void hal_cli_init(void);
void hal_cli_putbufbyte(uint8_t data);
uint8_t hal_cli_getbufbyte(void);

#ifdef __cplusplus
}
#endif
#endif
