#include <string.h>
#include "tft.h"

#define DMA_STREAM               DMA2_Stream6
#define DMA_CHANNEL              DMA_CHANNEL_0
#define DMA_STREAM_IRQ           DMA2_Stream6_IRQn
#define DMA_STREAM_IRQHANDLER    DMA2_Stream6_IRQHandler


#if TFT_EXT_FB != 0
__IO uint16_t * my_fb = (__IO uint16_t*) (SDRAM_BANK_ADDR);
#else
static uint16_t my_fb[TFT_HOR_RES * TFT_VER_RES];
#endif


static void tft_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_p);
static void DMA_Config(void);

DMA_HandleTypeDef     hdma_tft;
static lv_disp_drv_t disp_drv;
static int32_t x1_flush;
static int32_t y1_flush;
static int32_t x2_flush;
static int32_t y2_fill;
static int32_t y_fill_act;
static const lv_color_t * buf_to_flush;


static volatile uint32_t t_saved = 0;
void monitor_cb(lv_disp_drv_t * d, uint32_t t, uint32_t p)
{
	t_saved = t;
}


void tft_init(void)
{
	static lv_color_t disp_buf1[TFT_HOR_RES * 60];
	static lv_color_t disp_buf2[TFT_HOR_RES * 60];
	static lv_disp_draw_buf_t buf;
	lv_disp_draw_buf_init(&buf, disp_buf1, disp_buf2, TFT_HOR_RES * 40);
	lv_disp_drv_init(&disp_drv);

#if TFT_EXT_FB != 0
	SDRAM_Init();
#endif
	ili9341_Init();
	ltdc_init();
	DMA_Config();
	disp_drv.draw_buf = &buf;
	disp_drv.flush_cb = tft_flush;
	disp_drv.monitor_cb = monitor_cb;
	disp_drv.hor_res = 240;
	disp_drv.ver_res = 320;
	lv_disp_drv_register(&disp_drv);
}


/**
 * Flush a color buffer
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color_p pointer to an array of colors
 */
static void tft_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_p)
{
	/*Return if the area is out the screen*/
	if(area->x2 < 0) return;
	if(area->y2 < 0) return;
	if(area->x1 > TFT_HOR_RES - 1) return;
	if(area->y1 > TFT_VER_RES - 1) return;

	/*Truncate the area to the screen*/
	int32_t act_x1 = area->x1 < 0 ? 0 : area->x1;
	int32_t act_y1 = area->y1 < 0 ? 0 : area->y1;
	int32_t act_x2 = area->x2 > TFT_HOR_RES - 1 ? TFT_HOR_RES - 1 : area->x2;
	int32_t act_y2 = area->y2 > TFT_VER_RES - 1 ? TFT_VER_RES - 1 : area->y2;

	x1_flush = act_x1;
	y1_flush = act_y1;
	x2_flush = act_x2;
	y2_fill = act_y2;
	y_fill_act = act_y1;
	buf_to_flush = color_p;


	  /*##-7- Start the DMA transfer using the interrupt mode #*/
	  /* Configure the source, destination and buffer size DMA fields and Start DMA Stream transfer */
	  /* Enable All the DMA interrupts */
	HAL_StatusTypeDef err;
	err = HAL_DMA_Start_IT(&hdma_tft,(uint32_t)buf_to_flush, (uint32_t)&my_fb[y_fill_act * TFT_HOR_RES + x1_flush],
			  (x2_flush - x1_flush + 1));
	if(err != HAL_OK)
	{
		while(1);	/*Halt on error*/
	}
}


/**
  * @brief DMA2D MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param hdma2d: DMA2D handle pointer
  * @retval None
  */
void HAL_DMA2D_MspInit(DMA2D_HandleTypeDef *hdma2d)
{
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  __HAL_RCC_DMA2D_CLK_ENABLE();

  /*##-2- NVIC configuration  ################################################*/
  /* NVIC configuration for DMA2D transfer complete interrupt */
  HAL_NVIC_SetPriority(DMA2D_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2D_IRQn);
}




/**
  * @brief  Configure the DMA controller according to the Stream parameters
  *         defined in main.h file
  * @note  This function is used to :
  *        -1- Enable DMA2 clock
  *        -2- Select the DMA functional Parameters
  *        -3- Select the DMA instance to be used for the transfer
  *        -4- Select Callbacks functions called after Transfer complete and
               Transfer error interrupt detection
  *        -5- Initialize the DMA stream
  *        -6- Configure NVIC for DMA transfer complete/error interrupts
  * @param  None
  * @retval None
  */
static void DMA_Config(void)
{
  /*## -1- Enable DMA2 clock #################################################*/
  __HAL_RCC_DMA2_CLK_ENABLE();

  /*##-2- Select the DMA functional Parameters ###############################*/
  hdma_tft.Init.Channel = DMA_CHANNEL;                     /* DMA_CHANNEL_0                    */
  hdma_tft.Init.Direction = DMA_MEMORY_TO_MEMORY;          /* M2M transfer mode                */
  hdma_tft.Init.PeriphInc = DMA_PINC_ENABLE;               /* Peripheral increment mode Enable */
  hdma_tft.Init.MemInc = DMA_MINC_ENABLE;                  /* Memory increment mode Enable     */
  hdma_tft.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD; /* Peripheral data alignment : 16bit */
  hdma_tft.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;    /* memory data alignment : 16bit     */
  hdma_tft.Init.Mode = DMA_NORMAL;                         /* Normal DMA mode                  */
  hdma_tft.Init.Priority = DMA_PRIORITY_HIGH;              /* priority level : high            */
  hdma_tft.Init.FIFOMode = DMA_FIFOMODE_ENABLE;            /* FIFO mode enabled                */
  hdma_tft.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_1QUARTERFULL; /* FIFO threshold: 1/4 full   */
  hdma_tft.Init.MemBurst = DMA_MBURST_SINGLE;              /* Memory burst                     */
  hdma_tft.Init.PeriphBurst = DMA_PBURST_SINGLE;           /* Peripheral burst                 */

  /*##-3- Select the DMA instance to be used for the transfer : DMA2_Stream0 #*/
  hdma_tft.Instance = DMA_STREAM;

  /*##-4- Initialize the DMA stream ##########################################*/
  if(HAL_DMA_Init(&hdma_tft) != HAL_OK)
  {
    while(1);
  }

  /*##-5- Select Callbacks functions called after Transfer complete and Transfer error */
  HAL_DMA_RegisterCallback(&hdma_tft, HAL_DMA_XFER_CPLT_CB_ID, DMA_TransferComplete);
  HAL_DMA_RegisterCallback(&hdma_tft, HAL_DMA_XFER_ERROR_CB_ID, DMA_TransferError);

  /*##-6- Configure NVIC for DMA transfer complete/error interrupts ##########*/
  HAL_NVIC_SetPriority(DMA_STREAM_IRQ, 0, 0);
  HAL_NVIC_EnableIRQ(DMA_STREAM_IRQ);
}


void tft_dma_flush_transfer(DMA_HandleTypeDef *han)
{
	y_fill_act ++;

	if(y_fill_act > y2_fill) {
		lv_disp_flush_ready(&disp_drv);
	} else {
		buf_to_flush += x2_flush - x1_flush + 1;
		/*##-7- Start the DMA transfer using the interrupt mode ####################*/
		/* Configure the source, destination and buffer size DMA fields and Start DMA Stream transfer */
		/* Enable All the DMA interrupts */
		if(HAL_DMA_Start_IT(han,(uint32_t)buf_to_flush, (uint32_t)&my_fb[y_fill_act * TFT_HOR_RES + x1_flush],
					  (x2_flush - x1_flush + 1)) != HAL_OK)
		{
		  while(1);	/*Halt on error*/
		}
	}
}





