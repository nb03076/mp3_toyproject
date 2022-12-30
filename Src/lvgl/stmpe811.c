#include "stmpe811.h"

void stmpe811_init(uint16_t DeviceAddr)
{

  IOE_Init();

  /* Generate stmpe811 Software reset */
  stmpe811_reset(DeviceAddr);
}

/**
  * @brief  Reset the stmpe811 by Software.
  * @param  DeviceAddr: Device address on communication Bus.
  * @retval None
  */
void stmpe811_reset(uint16_t DeviceAddr)
{
  /* Power Down the stmpe811 */
  IOE_Write(DeviceAddr, STMPE811_REG_SYS_CTRL1, 2);

  /* Wait for a delay to ensure registers erasing */
  IOE_Delay(10);

  /* Power On the Codec after the power off => all registers are reinitialized */
  IOE_Write(DeviceAddr, STMPE811_REG_SYS_CTRL1, 0);

  /* Wait for a delay to ensure registers erasing */
  IOE_Delay(2);
}


/**
  * @brief  Disable the AF for the selected IO pin(s).
  * @param  DeviceAddr: Device address on communication Bus.
  * @param  IO_Pin: The IO pin to be configured. This parameter could be any
  *         combination of the following values:
  *   @arg  STMPE811_PIN_x: Where x can be from 0 to 7.
  * @retval None
  */
void stmpe811_IO_DisableAF(uint16_t DeviceAddr, uint32_t IO_Pin)
{
  uint8_t tmp = 0;

  /* Get the current state of the IO_AF register */
  tmp = IOE_Read(DeviceAddr, STMPE811_REG_IO_AF);

  /* Enable the selected pins alternate function */
  tmp |= (uint8_t)IO_Pin;

  /* Write back the new value in IO AF register */
  IOE_Write(DeviceAddr, STMPE811_REG_IO_AF, tmp);

}

/**
  * @brief  Enable the AF for the selected IO pin(s).
  * @param  DeviceAddr: Device address on communication Bus.
  * @param  IO_Pin: The IO pin to be configured. This parameter could be any
  *         combination of the following values:
  *   @arg  STMPE811_PIN_x: Where x can be from 0 to 7.
  * @retval None
  */
void stmpe811_IO_EnableAF(uint16_t DeviceAddr, uint32_t IO_Pin)
{
  uint8_t tmp = 0;

  /* Get the current register value */
  tmp = IOE_Read(DeviceAddr, STMPE811_REG_IO_AF);

  /* Enable the selected pins alternate function */
  tmp &= ~(uint8_t)IO_Pin;

  /* Write back the new register value */
  IOE_Write(DeviceAddr, STMPE811_REG_IO_AF, tmp);
}

/**
  * @brief  Configures the touch Screen Controller (Single point detection)
  * @param  DeviceAddr: Device address on communication Bus.
  * @retval None.
  */
void stmpe811_TS_Start(uint16_t DeviceAddr)
{
  uint8_t mode;

  /* Get the current register value */
  mode = IOE_Read(DeviceAddr, STMPE811_REG_SYS_CTRL2);

  /* Set the Functionalities to be Enabled */
  mode &= ~(STMPE811_IO_FCT);

  /* Write the new register value */
  IOE_Write(DeviceAddr, STMPE811_REG_SYS_CTRL2, mode);

  /* Select TSC pins in TSC alternate mode */
  stmpe811_IO_EnableAF(DeviceAddr, STMPE811_TOUCH_IO_ALL);

  /* Set the Functionalities to be Enabled */
  mode &= ~(STMPE811_TS_FCT | STMPE811_ADC_FCT);

  /* Set the new register value */
  IOE_Write(DeviceAddr, STMPE811_REG_SYS_CTRL2, mode);

  /* Select Sample Time, bit number and ADC Reference */
  IOE_Write(DeviceAddr, STMPE811_REG_ADC_CTRL1, 0x49);

  /* Wait for 2 ms */
  IOE_Delay(2);

  /* Select the ADC clock speed: 3.25 MHz */
  IOE_Write(DeviceAddr, STMPE811_REG_ADC_CTRL2, 0x01);

  /* Select 2 nF filter capacitor */
  /* Configuration:
     - Touch average control    : 4 samples
     - Touch delay time         : 500 uS
     - Panel driver setting time: 500 uS
  */
  IOE_Write(DeviceAddr, STMPE811_REG_TSC_CFG, 0x9A);

  /* Configure the Touch FIFO threshold: single point reading */
  IOE_Write(DeviceAddr, STMPE811_REG_FIFO_TH, 0x01);

  /* Clear the FIFO memory content. */
  IOE_Write(DeviceAddr, STMPE811_REG_FIFO_STA, 0x01);

  /* Put the FIFO back into operation mode  */
  IOE_Write(DeviceAddr, STMPE811_REG_FIFO_STA, 0x00);

  /* Set the range and accuracy pf the pressure measurement (Z) :
     - Fractional part :7
     - Whole part      :1
  */
  IOE_Write(DeviceAddr, STMPE811_REG_TSC_FRACT_XYZ, 0x01);

  /* Set the driving capability (limit) of the device for TSC pins: 50mA */
  IOE_Write(DeviceAddr, STMPE811_REG_TSC_I_DRIVE, 0x01);

  /* Touch screen control configuration (enable TSC):
     - No window tracking index
     - XYZ acquisition mode
   */
  IOE_Write(DeviceAddr, STMPE811_REG_TSC_CTRL, 0x01);

  /*  Clear all the status pending bits if any */
  IOE_Write(DeviceAddr, STMPE811_REG_INT_STA, 0xFF);

  /* Wait for 2 ms delay */
  IOE_Delay(2);
}

/**
  * @brief  Return if there is touch detected or not.
  * @param  DeviceAddr: Device address on communication Bus.
  * @retval Touch detected state.
  */
uint8_t stmpe811_TS_DetectTouch(uint16_t DeviceAddr)
{
  uint8_t state;
  uint8_t ret = 0;

  state = ((IOE_Read(DeviceAddr, STMPE811_REG_TSC_CTRL) & (uint8_t)STMPE811_TS_CTRL_STATUS) == (uint8_t)0x80);

  if(state > 0)
  {
    if(IOE_Read(DeviceAddr, STMPE811_REG_FIFO_SIZE) > 0)
    {
      ret = 1;
    }
  }
  else
  {
    /* Reset FIFO */
    IOE_Write(DeviceAddr, STMPE811_REG_FIFO_STA, 0x01);
    /* Enable the FIFO again */
    IOE_Write(DeviceAddr, STMPE811_REG_FIFO_STA, 0x00);
  }

  return ret;
}

/**
  * @brief  Get the touch screen X and Y positions values
  * @param  DeviceAddr: Device address on communication Bus.
  * @param  X: Pointer to X position value
  * @param  Y: Pointer to Y position value
  * @retval None.
  */
void stmpe811_TS_GetXY(uint16_t DeviceAddr, uint16_t *X, uint16_t *Y)
{
  uint8_t  dataXYZ[4];
  uint32_t uldataXYZ;

  IOE_ReadMultiple(DeviceAddr, STMPE811_REG_TSC_DATA_NON_INC, dataXYZ, sizeof(dataXYZ)) ;

  /* Calculate positions values */
  uldataXYZ = (dataXYZ[0] << 24)|(dataXYZ[1] << 16)|(dataXYZ[2] << 8)|(dataXYZ[3] << 0);
  *X = (uldataXYZ >> 20) & 0x00000FFF;
  *Y = (uldataXYZ >>  8) & 0x00000FFF;

  /* Reset FIFO */
  IOE_Write(DeviceAddr, STMPE811_REG_FIFO_STA, 0x01);
  /* Enable the FIFO again */
  IOE_Write(DeviceAddr, STMPE811_REG_FIFO_STA, 0x00);
}


void IOE_Init(void)
{
  I2C3_Init();
}


void IOE_Write(uint8_t Addr, uint8_t Reg, uint8_t Value)
{
  I2Cx_WriteData(Addr, Reg, Value);
}

uint8_t IOE_Read(uint8_t Addr, uint8_t Reg)
{
  return I2Cx_ReadData(Addr, Reg);
}

void IOE_WriteMultiple(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer, uint16_t Length)
{
  I2Cx_WriteBuffer(Addr, Reg, pBuffer, Length);
}

uint16_t IOE_ReadMultiple(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer, uint16_t Length)
{
 return I2Cx_ReadBuffer(Addr, Reg, pBuffer, Length);
}

void IOE_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}
