#include "spi.h"

static void spi4_pin_conf(void);
static void spi4_dma_init(void);
static void spi4_config(void);

static void spi5_pin_conf(void);
static void spi5_dma_init(void);
static void spi5_config(void);

/* instance spi driver */
spi_drv spi4drv;
spi_drv spi5drv;

/* SPI4 init function */
void spi4_init(spi_drv* drv)
{
	spi4_pin_conf();
	spi4_dma_init();
	spi4_config();

	drv->spi = SPI4;
	drv->dma = DMA2;
	drv->dma_tx_stream = LL_DMA_STREAM_1;
	drv->dma_rx_stream = LL_DMA_STREAM_0;
}

void spi5_init(spi_drv* drv)
{
	spi5_pin_conf();
	spi5_dma_init();
	spi5_config();

	drv->spi = SPI5;
	drv->dma = DMA2;
	drv->dma_tx_stream = LL_DMA_STREAM_4;
}


static void spi4_pin_conf(void)
{
	/**SPI4 GPIO Configuration
	 PE2   ------> SPI4_SCK
	 PE5   ------> SPI4_MISO
	 E6   ------> SPI4_MOSI
	*/
	 LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	 LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);

	 GPIO_InitStruct.Pin = LL_GPIO_PIN_2|LL_GPIO_PIN_5|LL_GPIO_PIN_6;
	 GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	 GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	 GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	 GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	 GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
	 LL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}

static void spi4_dma_init(void)
{
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);

	NVIC_SetPriority(DMA2_Stream0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);
	/* DMA2_Stream1_IRQn interrupt configuration */
	NVIC_SetPriority(DMA2_Stream1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(DMA2_Stream1_IRQn);

	/* SPI4_RX Init */
	LL_DMA_SetChannelSelection(DMA2, LL_DMA_STREAM_0, LL_DMA_CHANNEL_4);
	LL_DMA_SetDataTransferDirection(DMA2, LL_DMA_STREAM_0, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	LL_DMA_SetStreamPriorityLevel(DMA2, LL_DMA_STREAM_0, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA2, LL_DMA_STREAM_0, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA2, LL_DMA_STREAM_0, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA2, LL_DMA_STREAM_0, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA2, LL_DMA_STREAM_0, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA2, LL_DMA_STREAM_0, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA2, LL_DMA_STREAM_0);

	/* SPI4_TX Init */
	LL_DMA_SetChannelSelection(DMA2, LL_DMA_STREAM_1, LL_DMA_CHANNEL_4);
	LL_DMA_SetDataTransferDirection(DMA2, LL_DMA_STREAM_1, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
	LL_DMA_SetStreamPriorityLevel(DMA2, LL_DMA_STREAM_1, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA2, LL_DMA_STREAM_1, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA2, LL_DMA_STREAM_1, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA2, LL_DMA_STREAM_1, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA2, LL_DMA_STREAM_1, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA2, LL_DMA_STREAM_1, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA2, LL_DMA_STREAM_1);
}

static void spi4_config(void)
{
	LL_SPI_InitTypeDef SPI_InitStruct = {0};

	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI4);
	/* SPI4 interrupt Init */
	NVIC_SetPriority(SPI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(SPI4_IRQn);

	/* USER CODE BEGIN SPI4_Init 1 */

	/* USER CODE END SPI4_Init 1 */
	SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
	SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_HIGH;
	SPI_InitStruct.ClockPhase = LL_SPI_PHASE_2EDGE;
	SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
	SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV64;
	SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
	SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
	SPI_InitStruct.CRCPoly = 10;
	LL_SPI_Init(SPI4, &SPI_InitStruct);
	LL_SPI_SetStandard(SPI4, LL_SPI_PROTOCOL_MOTOROLA);
}


static void spi5_pin_conf(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
	/**SPI5 GPIO Configuration
	PF7   ------> SPI5_SCK
	PF8   ------> SPI5_MISO
	PF9   ------> SPI5_MOSI
	*/
	GPIO_InitStruct.Pin = LL_GPIO_PIN_7|LL_GPIO_PIN_8|LL_GPIO_PIN_9;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
	LL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}

static void spi5_dma_init(void)
{
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);

	NVIC_SetPriority(DMA2_Stream4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(DMA2_Stream4_IRQn);

	/* tx configuration */
	LL_DMA_SetChannelSelection(DMA2, LL_DMA_STREAM_4, LL_DMA_CHANNEL_2);
	LL_DMA_SetDataTransferDirection(DMA2, LL_DMA_STREAM_4, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
	LL_DMA_SetStreamPriorityLevel(DMA2, LL_DMA_STREAM_4, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA2, LL_DMA_STREAM_4, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA2, LL_DMA_STREAM_4, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA2, LL_DMA_STREAM_4, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA2, LL_DMA_STREAM_4, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA2, LL_DMA_STREAM_4, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA2, LL_DMA_STREAM_4);
}

static void spi5_config(void)
{
	LL_SPI_InitTypeDef SPI_InitStruct = {0};

	/* Peripheral clock enable */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI5);

	/* SPI5 interrupt Init */
	NVIC_SetPriority(SPI5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(SPI5_IRQn);

	SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
	SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
	SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
	SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
	SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV16;
	SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
	SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
	SPI_InitStruct.CRCPoly = 10;
	LL_SPI_Init(SPI5, &SPI_InitStruct);
	LL_SPI_SetStandard(SPI5, LL_SPI_PROTOCOL_MOTOROLA);
}

void SPI4_IRQHandler(void)
{

}


void SPI5_IRQHandler(void)
{

}


/* spi4 dma rx */
void DMA2_Stream0_IRQHandler(void)
{

}

/* tx */
void DMA2_Stream1_IRQHandler(void)
{

}

/* spi5 tx dma handler */
void DMA2_Stream4_IRQHandler(void)
{

}
