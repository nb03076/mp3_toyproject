#include "i2c.h"



#if 0

static void i2c3_pin_conf(void);
static void i2c3_dma_init(void);
static void i2c3_config(void);

static void i2c_handler(i2c_drv* drv);
static void i2c_dma_tx_handler(i2c_drv* drv);
static void i2c_dma_rx_handler(i2c_drv* drv);
static void I2C3_ErrorCallback(void);


i2c_drv i2c3drv =
{
	.i2c = I2C3,
	.dma = DMA1,
	.dma_tx_stream = LL_DMA_STREAM_4,
	.dma_rx_stream = LL_DMA_STREAM_2,
};

void i2c3_init(i2c_drv* drv)
{
	i2c3_pin_conf();

    i2c3_dma_init();

    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C3);
    i2c3_config();


	/* remove busy flag glitch */
	LL_I2C_EnableReset(drv->i2c);
	HAL_Delay(2);
	LL_I2C_DisableReset(drv->i2c);

	drv->mutex = xSemaphoreCreateMutex();
}

uint8_t i2c_transfer(i2c_drv* drv ,uint8_t dev_addr, uint8_t* tx_buf, uint16_t len)
{
	I2C_TypeDef* i2c = drv->i2c;

	while(LL_I2C_IsActiveFlag_BUSY(i2c));
	/* dev addr transfer */
	LL_I2C_GenerateStartCondition(i2c);
	while(!LL_I2C_IsActiveFlag_SB(i2c));
	LL_I2C_TransmitData8(i2c, dev_addr | 0x00);
	while(!LL_I2C_IsActiveFlag_ADDR(i2c));
	LL_I2C_ClearFlag_ADDR(i2c);

	/* reg write */
	for(int i=0; i < len; i++)
	{
		while(!LL_I2C_IsActiveFlag_TXE(i2c));
		LL_I2C_TransmitData8(i2c, tx_buf[i]);
	}

	while(!LL_I2C_IsActiveFlag_BTF(i2c));
	LL_I2C_GenerateStopCondition(i2c);

	return 0;
}


uint8_t i2c_receive(i2c_drv* drv, uint8_t dev_addr, uint8_t* rx_buf, uint8_t len)
{
	I2C_TypeDef* i2c = drv->i2c;

	while(LL_I2C_IsActiveFlag_BUSY(i2c));

	if(len == 1) LL_I2C_AcknowledgeNextData(i2c, LL_I2C_NACK);
	else		 LL_I2C_AcknowledgeNextData(i2c, LL_I2C_ACK);

	/* dev addr transfer */
	LL_I2C_GenerateStartCondition(i2c);
	while(!LL_I2C_IsActiveFlag_SB(i2c));
	LL_I2C_TransmitData8(i2c, dev_addr | 0x01);
	while(!LL_I2C_IsActiveFlag_ADDR(i2c));
	LL_I2C_ClearFlag_ADDR(i2c);

	/* reg receive */
	for(int i=0; i < len; i++)
	{
		if(i == len - 1)
		{
			LL_I2C_AcknowledgeNextData(i2c, LL_I2C_NACK);
		}

		while(!LL_I2C_IsActiveFlag_RXNE(i2c));

		rx_buf[i] = LL_I2C_ReceiveData8(i2c);
	}

	LL_I2C_GenerateStopCondition(i2c);

	return 0;

}

uint8_t i2c_mem_transfer(i2c_drv* drv, uint8_t dev_addr, uint8_t reg_addr, uint8_t* tx_buf, uint8_t len)
{
	I2C_TypeDef* i2c = drv->i2c;

	while(LL_I2C_IsActiveFlag_BUSY(i2c));
	/* dev addr transfer */
	LL_I2C_GenerateStartCondition(i2c);
	while(!LL_I2C_IsActiveFlag_SB(i2c));
	LL_I2C_TransmitData8(i2c, dev_addr | 0x00);
	while(!LL_I2C_IsActiveFlag_ADDR(i2c));
	LL_I2C_ClearFlag_ADDR(i2c);

	while(!LL_I2C_IsActiveFlag_TXE(i2c));
	LL_I2C_TransmitData8(i2c, reg_addr);

	/* reg write */
	for(int i=0; i < len; i++)
	{
		while(!LL_I2C_IsActiveFlag_TXE(i2c));
		LL_I2C_TransmitData8(i2c, tx_buf[i]);
	}

	while(!LL_I2C_IsActiveFlag_BTF(i2c));
	LL_I2C_GenerateStopCondition(i2c);

	return 0;
}

uint8_t i2c_mem_receive(i2c_drv* drv, uint8_t dev_addr, uint8_t reg_addr, uint8_t* rx_buf, uint8_t len)
{
	I2C_TypeDef* i2c = drv->i2c;

	while(LL_I2C_IsActiveFlag_BUSY(i2c));
	/* dev addr transfer */
	LL_I2C_GenerateStartCondition(i2c);
	while(!LL_I2C_IsActiveFlag_SB(i2c));
	LL_I2C_TransmitData8(i2c, dev_addr | 0x00);
	while(!LL_I2C_IsActiveFlag_ADDR(i2c));
	LL_I2C_ClearFlag_ADDR(i2c);

	/* reg write */
	while(!LL_I2C_IsActiveFlag_TXE(i2c));
	LL_I2C_TransmitData8(i2c, reg_addr);

	while(!LL_I2C_IsActiveFlag_BTF(i2c));

	/* restart */
	LL_I2C_GenerateStartCondition(i2c);

	/* dev addr transfer */
	LL_I2C_GenerateStartCondition(i2c);
	while(!LL_I2C_IsActiveFlag_SB(i2c));
	LL_I2C_TransmitData8(i2c, dev_addr | 0x01);
	while(!LL_I2C_IsActiveFlag_ADDR(i2c));
	LL_I2C_ClearFlag_ADDR(i2c);

	/* reg read */
	for(int i=0; i < len; i++)
	{
		if(i == len - 1)
		{
			LL_I2C_AcknowledgeNextData(i2c, LL_I2C_NACK);
		}

		while(!LL_I2C_IsActiveFlag_RXNE(i2c));

		rx_buf[i] = LL_I2C_ReceiveData8(i2c);
	}

	LL_I2C_GenerateStopCondition(i2c);

	return 0;
}

uint8_t i2c_transfer_it(i2c_drv* drv, uint8_t dev_addr, uint8_t reg_addr, uint8_t* tx_buf, uint8_t len)
{
	drv->dev_addr = dev_addr;
	drv->reg_addr = reg_addr;
	drv->tx_buf = tx_buf;
	drv->tx_size = len;
	drv->tx_count = 0;

	while(LL_I2C_IsActiveFlag_BUSY(drv->i2c));

	LL_I2C_EnableIT_TX(drv->i2c);
	LL_I2C_EnableIT_ERR(drv->i2c);

	drv->direction = I2C_TX;

	LL_I2C_GenerateStartCondition(drv->i2c);

	return 0;
}

uint8_t i2c_receive_it(i2c_drv* drv, uint8_t dev_addr, uint8_t reg_addr, uint8_t* rx_buf, uint8_t len)
{
	drv->dev_addr = dev_addr;
	drv->reg_addr = reg_addr;
	drv->rx_buf = rx_buf;
	drv->rx_size = len;
	drv->rx_count = 0;

	while(LL_I2C_IsActiveFlag_BUSY(drv->i2c));

	LL_I2C_EnableIT_RX(drv->i2c);
	LL_I2C_EnableIT_ERR(drv->i2c);

	drv->direction = I2C_RX;
	drv->restart = 0;

	LL_I2C_AcknowledgeNextData(drv->i2c, LL_I2C_ACK);
	LL_I2C_GenerateStartCondition(drv->i2c);

	return 0;
}

/*
	1. Set the I2C_DR register address in the DMA_SxPAR register. The data will be moved
	to this address from the memory after each TxE event.
	2. Set the memory address in the DMA_SxMA0R register (and in DMA_SxMA1R register
	in the case of a double buffer mode). The data will be loaded into I2C_DR from this
	memory after each TxE event.
	3. Configure the total number of bytes to be transferred in the DMA_SxNDTR register.
	After each TxE event, this value will be decremented.
	4. Configure the DMA stream priority using the PL[0:1] bits in the DMA_SxCR register
	5. Set the DIR bit in the DMA_SxCR register and configure interrupts after half transfer or
	full transfer depending on application requirements.
	6. Activate the stream by setting the EN bit in the DMA_SxCR register.
*/

uint8_t i2c_transfer_dma(i2c_drv* drv ,uint8_t dev_addr, uint8_t* tx_buf, uint16_t len)
{
	LL_DMA_DisableStream(drv->dma, drv->dma_tx_stream);
	LL_DMA_ConfigAddresses(drv->dma, drv->dma_tx_stream, LL_I2C_DMA_GetRegAddr(drv->i2c), \
			(uint32_t)tx_buf, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
	LL_DMA_SetDataLength(drv->dma, drv->dma_tx_stream, len);
	LL_DMA_EnableIT_TE(drv->dma, drv->dma_tx_stream);
	LL_DMA_EnableIT_TC(drv->dma, drv->dma_tx_stream);
	LL_I2C_EnableLastDMA(drv->i2c);
	LL_DMA_EnableStream(drv->dma, drv->dma_tx_stream);
	LL_I2C_EnableDMAReq_TX(drv->i2c);

	return 0;
}


uint8_t i2c_receive_dma(i2c_drv* drv ,uint8_t dev_addr, uint8_t* rx_buf, uint16_t len)
{
	LL_DMA_DisableStream(drv->dma, drv->dma_rx_stream);
	LL_DMA_ConfigAddresses(drv->dma, drv->dma_rx_stream, LL_I2C_DMA_GetRegAddr(drv->i2c), \
			(uint32_t)rx_buf, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	LL_DMA_SetDataLength(drv->dma, drv->dma_rx_stream, len);
	LL_DMA_EnableIT_TE(drv->dma, drv->dma_rx_stream);
	LL_DMA_EnableIT_TC(drv->dma, drv->dma_rx_stream);
	LL_I2C_EnableLastDMA(drv->i2c);
	LL_DMA_EnableStream(drv->dma, drv->dma_rx_stream);
	LL_I2C_EnableDMAReq_RX(drv->i2c);

	LL_I2C_AcknowledgeNextData(drv->i2c, LL_I2C_ACK);
	LL_I2C_GenerateStartCondition(drv->i2c);

	return 0;
}

static void i2c_handler(i2c_drv* drv)
{
	I2C_TypeDef* i2c = drv->i2c;

	if(LL_I2C_IsActiveFlag_SB(i2c))
	{
		LL_I2C_TransmitData8(i2c, drv->dev_addr);
	}
	else if(LL_I2C_IsActiveFlag_ADDR(i2c))
	{
		LL_I2C_ClearFlag_ADDR(i2c);

		if(!drv->restart)
			LL_I2C_TransmitData8(i2c, drv->reg_addr);

		if(drv->direction == I2C_RX && !drv->restart)
		{
			drv->restart = 1;
			drv->dev_addr |= 0x01; // read
			LL_I2C_GenerateStartCondition(i2c);

			return;
		}

	}
	else if(LL_I2C_IsActiveFlag_TXE(i2c) && drv->direction == I2C_TX && \
		drv->tx_count != drv->tx_size)
	{
		LL_I2C_TransmitData8(i2c, drv->tx_buf[drv->tx_count++]);
	}
	else if(LL_I2C_IsActiveFlag_RXNE(i2c) && drv->direction == I2C_RX)
	{
		drv->rx_buf[drv->rx_count++] = LL_I2C_ReceiveData8(i2c);
		if(drv->rx_count == drv->rx_size)
		{
			drv->rx_buf = NULL;
			drv->rx_size = 0;
			drv->rx_count = 0;

			LL_I2C_GenerateStopCondition(i2c);
			LL_I2C_DisableIT_ERR(i2c);
			LL_I2C_DisableIT_RX(i2c);
		}
	}
	else if(LL_I2C_IsActiveFlag_BTF(i2c) && LL_I2C_IsActiveFlag_TXE(i2c))
	{
		drv->tx_buf = NULL;
		drv->tx_size = 0;
		drv->tx_count = 0;

		LL_I2C_GenerateStopCondition(i2c);
		LL_I2C_DisableIT_ERR(i2c);
		LL_I2C_DisableIT_TX(i2c);
	}

}


void I2C3_EV_IRQHandler(void)
{
	i2c_handler(&i2c3drv);
}


void I2C3_ER_IRQHandler(void)
{


}


void DMA1_Stream2_IRQHandler(void)
{
	i2c_dma_rx_handler(&i2c3drv);
}

void DMA1_Stream4_IRQHandler(void)
{
	i2c_dma_tx_handler(&i2c3drv);
}


static void i2c_dma_tx_handler(i2c_drv* drv)
{
	if(LL_DMA_IsActiveFlag_TC4(drv->dma))
	{
		LL_DMA_DisableIT_TE(drv->dma, drv->dma_tx_stream);
		LL_DMA_DisableIT_TC(drv->dma, drv->dma_tx_stream);
		LL_DMA_ClearFlag_TE4(drv->dma);
		LL_DMA_ClearFlag_TC4(drv->dma);
		LL_I2C_GenerateStopCondition(drv->i2c);
		LL_I2C_DisableLastDMA(drv->dma);
	}
}

static void i2c_dma_rx_handler(i2c_drv* drv)
{
	if(LL_DMA_IsActiveFlag_TC2(drv->dma))
	{
		LL_DMA_DisableIT_TE(drv->dma, drv->dma_rx_stream);
		LL_DMA_DisableIT_TC(drv->dma, drv->dma_rx_stream);
		LL_DMA_ClearFlag_TE2(drv->dma);
		LL_DMA_ClearFlag_TC2(drv->dma);
		LL_I2C_GenerateStopCondition(drv->i2c);
		LL_I2C_DisableLastDMA(drv->dma);
	}
}


static void i2c3_pin_conf(void)
{
	  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
	  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
	  /**I2C3 GPIO Configuration
	  PC9   ------> I2C3_SDA
	  PA8   ------> I2C3_SCL
	  */
	  GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
	  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
	  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	  GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
	  LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
	  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
	  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	  GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
	  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

static void i2c3_dma_init(void)
{
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
	/* rx */
	NVIC_SetPriority(DMA1_Stream2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(DMA1_Stream2_IRQn);
	/* tx */
	NVIC_SetPriority(DMA1_Stream4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(DMA1_Stream4_IRQn);

	/* I2C3_RX Init */
	LL_DMA_SetChannelSelection(DMA1, LL_DMA_STREAM_2, LL_DMA_CHANNEL_3);
	LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_STREAM_2, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	LL_DMA_SetStreamPriorityLevel(DMA1, LL_DMA_STREAM_2, LL_DMA_PRIORITY_LOW);
    LL_DMA_SetMode(DMA1, LL_DMA_STREAM_2, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_STREAM_2, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_STREAM_2, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA1, LL_DMA_STREAM_2, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA1, LL_DMA_STREAM_2, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA1, LL_DMA_STREAM_2);

	/* I2C3_TX Init */
	LL_DMA_SetChannelSelection(DMA1, LL_DMA_STREAM_4, LL_DMA_CHANNEL_3);
	LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_STREAM_4, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
	LL_DMA_SetStreamPriorityLevel(DMA1, LL_DMA_STREAM_4, LL_DMA_PRIORITY_LOW);
	LL_DMA_SetMode(DMA1, LL_DMA_STREAM_4, LL_DMA_MODE_NORMAL);
	LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_STREAM_4, LL_DMA_PERIPH_NOINCREMENT);
	LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_STREAM_4, LL_DMA_MEMORY_INCREMENT);
	LL_DMA_SetPeriphSize(DMA1, LL_DMA_STREAM_4, LL_DMA_PDATAALIGN_BYTE);
	LL_DMA_SetMemorySize(DMA1, LL_DMA_STREAM_4, LL_DMA_MDATAALIGN_BYTE);
	LL_DMA_DisableFifoMode(DMA1, LL_DMA_STREAM_4);
}

static void i2c3_config(void)
{
	LL_I2C_InitTypeDef I2C_InitStruct = {0};

	/* I2C3 interrupt Init */
	NVIC_SetPriority(I2C3_EV_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
 	NVIC_EnableIRQ(I2C3_EV_IRQn);
	NVIC_SetPriority(I2C3_ER_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
	NVIC_EnableIRQ(I2C3_ER_IRQn);

	/* I2C Initialization */
	LL_I2C_Disable(I2C3);

	LL_I2C_DisableOwnAddress2(I2C3);
	LL_I2C_DisableGeneralCall(I2C3);
	LL_I2C_EnableClockStretching(I2C3);
	I2C_InitStruct.PeripheralMode = LL_I2C_MODE_I2C;
	I2C_InitStruct.ClockSpeed = 400000;
	I2C_InitStruct.DutyCycle = LL_I2C_DUTYCYCLE_2;
	I2C_InitStruct.AnalogFilter = LL_I2C_ANALOGFILTER_ENABLE;
	I2C_InitStruct.DigitalFilter = 0;
	I2C_InitStruct.OwnAddress1 = 0;
	I2C_InitStruct.TypeAcknowledge = LL_I2C_ACK;
	I2C_InitStruct.OwnAddrSize = LL_I2C_OWNADDRESS1_7BIT;
	LL_I2C_Init(I2C3, &I2C_InitStruct);
	LL_I2C_SetOwnAddress2(I2C3, 0);

	LL_I2C_Enable(I2C3);
}

static void I2C3_ErrorCallback(void)
{
	for(;;);
}

/* USER CODE END 1 */
#endif
