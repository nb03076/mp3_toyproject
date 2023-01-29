#include "spi.h"
#include "core.h"
#include "resources.h"
#include "cli.h"
#include "delay.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_gpio.h"

static void spi2_init(spidrv_t* drv);
static void spi4_init(spidrv_t* drv);
static void spi5_init(spidrv_t* drv);

static void spi2_pin_conf(void);
static void spi2_dma_init(void);
static void spi2_config(void);

static void spi4_pin_conf(void);
static void spi4_dma_init(void);
static void spi4_config(void);

static void spi5_pin_conf(void);
static void spi5_dma_init(void);
static void spi5_config(void);

/* instance spi driver */
spidrv_t spi2drv;
spidrv_t spi4drv;
spidrv_t spi5drv;


void spi_init(SpiId spi_id)
{
	taskENTER_CRITICAL();

	switch(spi_id) {
	case SpiId2:
		spi2_init(&spi2drv);
		hal_cli_printf("spi2 init");
		break;

	case SpiId4:
		spi4_init(&spi4drv);
		hal_cli_printf("spi4 init");
		break;

	case SpiId5:
		spi5_init(&spi5drv);
		hal_cli_printf("spi5 init");
		break;

	default:
		hal_cli_printf("spi id not existed");
		break;
	}

	taskEXIT_CRITICAL();
}

bool hal_spi_transfer(spidrv_t* drv, uint8_t* data, uint32_t size, uint32_t timeout)
{
	coretex_timer timer;

	timer = hal_get_delay_timer(timeout);

	while(size > 0) {
		LL_SPI_TransmitData8(drv->spi, *data);
		while(!LL_SPI_IsActiveFlag_TXE(drv->spi)) {
			if(hal_delay_timer_is_expired(&timer)) {
				hal_cli_printf("spi txe flag failed");
				return false;
			}
		}
		size--;
		data++;
	}

	while(LL_SPI_IsActiveFlag_BSY(drv->spi)) {
		if(hal_delay_timer_is_expired(&timer)) {
			hal_cli_printf("spi busy flag failed");
			return false;
		}
	}

	return true;
}


bool hal_spi_receive(spidrv_t* drv, uint8_t* data, uint32_t size, uint32_t timeout)
{
	coretex_timer timer;

	timer = hal_get_delay_timer(timeout);

	while(size > 0) {
		while(!LL_SPI_IsActiveFlag_RXNE(drv->spi)) {
			if(hal_delay_timer_is_expired(&timer)) {
				hal_cli_printf("spi rxne flag failed");
				return false;
			}
		}
		*data = LL_SPI_ReceiveData8(drv->spi);

		size--;
		data++;
	}

	return true;
}

bool hal_spi_txrx(spidrv_t* drv, uint8_t* tx, uint8_t* rx, uint32_t size, uint32_t timeout)
{
	coretex_timer timer;

	timer = hal_get_delay_timer(timeout);

	for(int i = 0; i < size; i++) {
		while(!LL_SPI_IsActiveFlag_TXE(drv->spi)) {
			if(hal_delay_timer_is_expired(&timer)) {
				hal_cli_printf("spi txe flag failed");
				return false;
			}
		}
		LL_SPI_TransmitData8(drv->spi, tx[i]);

		while(!LL_SPI_IsActiveFlag_RXNE(drv->spi)) {
			if(hal_delay_timer_is_expired(&timer)) {
				hal_cli_printf("spi rxne flag failed");
				return false;
			}
		}
		rx[i] = LL_SPI_ReceiveData8(drv->spi);
	}

	while(LL_SPI_IsActiveFlag_BSY(drv->spi)) {
		if(hal_delay_timer_is_expired(&timer)) {
			hal_cli_printf("spi busy flag failed");
			return false;
		}
	}
	return true;
}


static void spi2_init(spidrv_t* drv)
{
	spi2_pin_conf();
	spi2_dma_init();
	spi2_config();

	LL_SPI_Enable(SPI2);

	drv->spi = SPI2;
	drv->dma = DMA1;
	drv->dma_tx_stream = LL_DMA_STREAM_4;
	drv->dma_rx_stream = 0;

	drv->mutex = xSemaphoreCreateMutex();
}

/* SPI4 init function */
static void spi4_init(spidrv_t* drv)
{
	spi4_pin_conf();
	spi4_dma_init();
	spi4_config();

	LL_SPI_Enable(SPI4);

	drv->spi = SPI4;
	drv->dma = DMA2;
	drv->dma_tx_stream = LL_DMA_STREAM_1;
	drv->dma_rx_stream = LL_DMA_STREAM_0;

	drv->mutex = xSemaphoreCreateMutex();
}

static void spi5_init(spidrv_t* drv)
{
	spi5_pin_conf();
	spi5_dma_init();
	spi5_config();

	LL_SPI_Enable(SPI5);

	drv->spi = SPI5;
	drv->dma = DMA2;
	drv->dma_tx_stream = LL_DMA_STREAM_4;
	drv->dma_rx_stream = 0;

	drv->mutex = xSemaphoreCreateMutex();
}


static void spi2_pin_conf(void)
{
	hal_gpio_init_alt(
		&gpio_spi2_sck,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqVeryHigh,
		GpioAltFnSpi2);

	hal_gpio_init_alt(
		&gpio_spi2_mosi,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqVeryHigh,
		GpioAltFnSpi2);
}

static void spi2_dma_init(void)
{
	NVIC_SetPriority(DMA1_Stream4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(DMA1_Stream4_IRQn);

	LL_DMA_SetChannelSelection(DMA1, DMA_SPI2_TX_STREAM, DMA_SPI2_TX_CHANNEL);
	LL_DMA_SetDataTransferDirection(DMA1, DMA_SPI2_TX_STREAM, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
	LL_DMA_SetStreamPriorityLevel(DMA1, DMA_SPI2_TX_STREAM, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA1, DMA_SPI2_TX_STREAM, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA1, DMA_SPI2_TX_STREAM, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA1, DMA_SPI2_TX_STREAM, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA1, DMA_SPI2_TX_STREAM, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA1, DMA_SPI2_TX_STREAM, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA1, DMA_SPI2_TX_STREAM);
}

static void spi2_config(void)
{
	 LL_SPI_InitTypeDef SPI_InitStruct = {0};

	 NVIC_SetPriority(SPI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	 NVIC_EnableIRQ(SPI2_IRQn);

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
	 LL_SPI_Init(SPI2, &SPI_InitStruct);
	 LL_SPI_SetStandard(SPI2, LL_SPI_PROTOCOL_MOTOROLA);
}

static void spi4_pin_conf(void)
{
	hal_gpio_init_alt(
		&gpio_spi4_sck,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqVeryHigh,
		GpioAltFnSpi2);

	hal_gpio_init_alt(
		&gpio_spi4_mosi,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqVeryHigh,
		GpioAltFnSpi2);

	hal_gpio_init_alt(
		&gpio_spi4_miso,
		GpioModeAltFunctionPushPull,
		GpioPullNo,
		GpioSpeedFreqVeryHigh,
		GpioAltFnSpi2);
}

static void spi4_dma_init(void)
{
	NVIC_SetPriority(DMA2_Stream0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);
	/* DMA2_Stream1_IRQn interrupt configuration */
	NVIC_SetPriority(DMA2_Stream1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(DMA2_Stream1_IRQn);

	/* SPI4_RX Init */
	LL_DMA_SetChannelSelection(DMA2, DMA_SPI4_RX_STREAM, DMA_SPI4_RX_CHANNEL);
	LL_DMA_SetDataTransferDirection(DMA2, DMA_SPI4_RX_STREAM, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	LL_DMA_SetStreamPriorityLevel(DMA2, DMA_SPI4_RX_STREAM, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA2, DMA_SPI4_RX_STREAM, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA2, DMA_SPI4_RX_STREAM, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA2, DMA_SPI4_RX_STREAM, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA2, DMA_SPI4_RX_STREAM, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA2, DMA_SPI4_RX_STREAM, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA2, DMA_SPI4_RX_STREAM);

	/* SPI4_TX Init */
	LL_DMA_SetChannelSelection(DMA2, DMA_SPI4_TX_STREAM, DMA_SPI4_TX_CHANNEL);
	LL_DMA_SetDataTransferDirection(DMA2, DMA_SPI4_TX_STREAM, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
	LL_DMA_SetStreamPriorityLevel(DMA2, DMA_SPI4_TX_STREAM, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA2, DMA_SPI4_TX_STREAM, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA2, DMA_SPI4_TX_STREAM, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA2, DMA_SPI4_TX_STREAM, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA2, DMA_SPI4_TX_STREAM, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA2, DMA_SPI4_TX_STREAM, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA2, DMA_SPI4_TX_STREAM);
}

static void spi4_config(void)
{
	LL_SPI_InitTypeDef SPI_InitStruct = {0};

	/* SPI4 interrupt Init */
	NVIC_SetPriority(SPI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
	NVIC_EnableIRQ(SPI4_IRQn);

	SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
	SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
	SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
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
	NVIC_SetPriority(DMA2_Stream4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
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
	NVIC_SetPriority(SPI5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
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

void SPI2_IRQHandler(void)
{

}

void SPI4_IRQHandler(void)
{

}


void SPI5_IRQHandler(void)
{

}

/* spi2 dma tx */
void DMA1_Stream4_IRQHandler(void)
{

}


/* spi4 dma rx */
void DMA2_Stream0_IRQHandler(void)
{

}

/* spi4 dma tx */
void DMA2_Stream1_IRQHandler(void)
{

}

/* spi5 tx dma handler */
void DMA2_Stream4_IRQHandler(void)
{

}
