#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "FreeRTOS.h"
#include "semphr.h"

#include "stm32f4xx_ll_i2c.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if 0

typedef enum
{
	I2C_TX,
	I2C_RX
}i2c_direction_t;


typedef struct
{
	I2C_TypeDef* i2c;
	DMA_TypeDef* dma;

	uint32_t dma_tx_stream;
	uint32_t dma_rx_stream;

	xSemaphoreHandle mutex;

	/* only use in interrupt */
	i2c_direction_t direction;

	uint8_t dev_addr;
	uint8_t reg_addr;

	uint8_t* tx_buf;
	uint8_t tx_size;
	uint8_t tx_count;

	uint8_t* rx_buf;
	uint8_t rx_size;
	uint8_t rx_count;
	bool restart;
}i2c_drv;

extern i2c_drv i2c3drv;

/* function */
void i2c3_init(i2c_drv* drv);
uint8_t i2c_transfer(i2c_drv* drv ,uint8_t dev_addr, uint8_t* tx_buf, uint16_t len);
uint8_t i2c_receive(i2c_drv* drv, uint8_t dev_addr, uint8_t* rx_buf, uint8_t len);

uint8_t i2c_mem_transfer(i2c_drv* drv, uint8_t dev_addr, uint8_t reg_addr, uint8_t* tx_buf, uint8_t len);
uint8_t i2c_mem_receive(i2c_drv* drv, uint8_t dev_addr, uint8_t reg_addr, uint8_t* rx_buf, uint8_t len);

uint8_t i2c_transfer_it(i2c_drv* drv, uint8_t dev_addr, uint8_t reg_addr, uint8_t* tx_buf, uint8_t len);
uint8_t i2c_receive_it(i2c_drv* drv, uint8_t dev_addr, uint8_t reg_addr, uint8_t* rx_buf, uint8_t len);

uint8_t i2c_transfer_dma(i2c_drv* drv ,uint8_t dev_addr, uint8_t* tx_buf, uint16_t len);
uint8_t i2c_receive_dma(i2c_drv* drv ,uint8_t dev_addr, uint8_t* rx_buf, uint16_t len);

/* handler */
void I2C3_EV_IRQHandler(void);
void I2C3_ER_IRQHandler(void);
void DMA1_Stream2_IRQHandler(void);
void DMA1_Stream4_IRQHandler(void);

#endif

#ifdef __cplusplus
}
#endif


#endif /* INC_I2C_H_ */
