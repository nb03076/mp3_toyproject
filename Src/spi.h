
#ifndef INC_SPI_H_
#define INC_SPI_H_


#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	SPI_TypeDef* spi;
	DMA_TypeDef* dma;

	uint32_t dma_tx_stream;
	uint32_t dma_rx_stream;
}spi_drv;

extern spi_drv spi4drv;
extern spi_drv spi5drv;


/* spi init */
void spi4_init(spi_drv* drv);
void spi5_init(spi_drv* drv);


/* spi handler */
void SPI4_IRQHandler(void);
void SPI5_IRQHandler(void);
void DMA2_Stream0_IRQHandler(void);
void DMA2_Stream1_IRQHandler(void);
void DMA2_Stream4_IRQHandler(void);


#ifdef __cplusplus
}
#endif

#endif /* INC_SPI_H_ */
