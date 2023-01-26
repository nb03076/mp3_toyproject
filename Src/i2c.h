#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "core.h"

#include "stm32f4xx_ll_i2c.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	I2C_TypeDef* i2c;
	SemaphoreHandle_t mutex;
}i2cdrv_t;

extern i2cdrv_t i2c1drv;
extern i2cdrv_t i2c3drv;


typedef enum {
	I2cId1 = 1,
	I2cId2,
	I2cId3
}I2cID;

void i2c_init(I2cID i2c_id);
bool hal_i2c_transfer(i2cdrv_t* drv, uint8_t addr, uint32_t regaddr, uint8_t* buf, uint32_t size, uint32_t timeout);
bool hal_i2c_receive(i2cdrv_t* drv, uint8_t addr, uint32_t regaddr, uint8_t* buf, uint32_t size, uint32_t timeout);
uint8_t hal_i2c_receive_byte(i2cdrv_t* drv, uint8_t addr, uint32_t regaddr, uint32_t timeout);

void DMA1_Stream0_IRQHandler(void);
void DMA1_Stream6_IRQHandler(void);

void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);

void I2C3_EV_IRQHandler(void);
void I2C3_ER_IRQHandler(void);

#if 0
typedef struct {
	I2C_TypeDef* i2c;
	SemaphoreHandle_t* mutex;
}I2cDrv;


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
