#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_dma.h"

#include "core.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	SpiId2 = 2,
	SpiId4 = 4,
	SpiId5
}SpiId;

typedef struct
{
	SPI_TypeDef* spi;
	SemaphoreHandle_t mutex;

	/* dma */
	DMA_TypeDef* dma;
	uint32_t dma_tx_stream;
	uint32_t dma_rx_stream;
}spidrv_t;

extern spidrv_t spi2drv;
extern spidrv_t spi4drv;
extern spidrv_t spi5drv;

/* spi init */
void spi_init(SpiId spi_id);
bool hal_spi_transfer(spidrv_t* drv, uint8_t* data, uint32_t size, uint32_t timeout);
bool hal_spi_receive(spidrv_t* drv, uint8_t* data, uint32_t size, uint32_t timeout);
bool hal_spi_txrx(spidrv_t* drv, uint8_t* tx, uint8_t* rx, uint32_t size, uint32_t timeout);

/* spi handler */
void SPI3_IRQHandler(void);
void SPI4_IRQHandler(void);
void SPI5_IRQHandler(void);
void DMA1_Stream5_IRQHandler(void); // spi3 tx
void DMA2_Stream0_IRQHandler(void);
void DMA2_Stream1_IRQHandler(void);
void DMA2_Stream4_IRQHandler(void);


#ifdef __cplusplus
}
#endif

#endif /* INC_SPI_H_ */
