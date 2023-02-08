#include "vs1053.h"
#include "gpio.h"
#include "resources.h"
#include "spi.h"
#include <stdbool.h>
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_utils.h"


#define VS1053_SPI_TIMEOUT 100

/* Commands */
#define VS1053_WRITE_CMD	0x02;
#define VS1053_READ_CMD		0x03;

spidrv_t* vs1053spidrv = &spi4drv;

/* Registers */
const uint8_t VS1053_REG_BASE		= 0x00;
const uint8_t VS1053_REG_MODE   	= 0x00;
const uint8_t VS1053_REG_STATUS 	= 0x01;
const uint8_t VS1053_REG_BASS 		= 0x02;
const uint8_t VS1053_REG_CLOCKF 	= 0x03;
const uint8_t VS1053_REG_DECODE_TIME = 0x04;
const uint8_t VS1053_REG_AUDATA 	= 0x05;
const uint8_t VS1053_REG_WRAM 		= 0x06;
const uint8_t VS1053_REG_WRAMADDR 	= 0x07;
const uint8_t VS1053_REG_HDAT0 		= 0x08;
const uint8_t VS1053_REG_HDAT1 		= 0x09;
const uint8_t VS1053_REG_AIADDR 	= 0x0A;
const uint8_t VS1053_REG_VOL 		= 0x0B;
const uint8_t VS1053_REG_AICTRL0 	= 0x0C;
const uint8_t VS1053_REG_AICTRL1 	= 0x0D;
const uint8_t VS1053_REG_AICTRL2 	= 0x0E;
const uint8_t VS1053_REG_AICTRL3 	= 0x0F;

/* Pin control */

#define XCS_HIGH	hal_gpio_write(&gpio_vs1053_cs, 1)
#define XCS_LOW		hal_gpio_write(&gpio_vs1053_cs, 0)
#define XDCS_HIGH	hal_gpio_write(&gpio_vs1053_dcs, 1)
#define XDCS_LOW	hal_gpio_write(&gpio_vs1053_dcs, 0)
#define XRST_HIGH	hal_gpio_write(&gpio_vs1053_rst, 1)
#define XRST_LOW	hal_gpio_write(&gpio_vs1053_rst, 0)

/* endFill byte is required to stop playing */
uint8_t endFillByte;

/* Initialize VS1053 */
bool VS1053_Init()
{
	XCS_HIGH;		    /* XCS High */
	XDCS_HIGH;		    /* XDCS High */
	VS1053_Reset();     /* Hard Reset */

	/* MP3 Mode GPIO configuration */
	if(!VS1053_SciWrite(VS1053_REG_WRAMADDR, 0xC017)) return false; /* GPIO direction */
	if(!VS1053_SciWrite(VS1053_REG_WRAM, 3)) return false;
	if(!VS1053_SciWrite(VS1053_REG_WRAMADDR, 0xC019)) return false; /* GPIO output */
	if(!VS1053_SciWrite(VS1053_REG_WRAM, 0)) return false;

	/* Soft reset */
	if(!VS1053_SoftReset()) return false;

	/* x4.0 Clock */
	if(!VS1053_SciWrite(VS1053_REG_CLOCKF, 0x8000)) return false;

	LL_SPI_SetBaudRatePrescaler(vs1053spidrv->spi, LL_SPI_BAUDRATEPRESCALER_DIV32); /* 90MHz / 16 = about 5.6mhz */

	/* Read endFill Byte */
	uint16_t regVal;
	if(!VS1053_SciWrite(VS1053_REG_WRAMADDR, 0x1E06)) return false;	/* endFill */
	if(!VS1053_SciRead(VS1053_REG_WRAM, &regVal)) return false;
	endFillByte = regVal & 0xFF;

	return true;
}

/* Hard reset */
void VS1053_Reset()
{
	uint8_t dummy = 0xFF;
	XRST_LOW;		                                    /* XRST Low */
	hal_spi_transfer(vs1053spidrv, &dummy, 1, VS1053_SPI_TIMEOUT); /* Tx Dummy */
	LL_mDelay(10);										/* 10ms Delay */
	XRST_HIGH;			                                /* XRST High */
	LL_mDelay(10);
}

/* Soft reset */
bool VS1053_SoftReset()
{
	if(!VS1053_SciWrite(VS1053_REG_MODE, 0x4804)) return false;	/* SM LINE1 | SM SDINEW | SM RESET */
	LL_mDelay(100);
	return true;
}

/* Volume control */
bool VS1053_SetVolume(uint8_t volumeLeft, uint8_t volumeRight)
{
    uint16_t volume;
    volume = ( volumeLeft << 8 ) + volumeRight;

    if(!VS1053_SciWrite(VS1053_REG_VOL, volume)) return false;
    return true;
}


/* Mode control */
bool VS1053_SetMode(uint16_t mode)
{
	if(!VS1053_SciWrite(VS1053_REG_MODE, mode)) return false;
	return true;
}

bool VS1053_GetMode(uint16_t *mode)
{
	if(!VS1053_SciRead(VS1053_REG_MODE, mode)) return false;
	return true;
}

/* Resync control */
bool VS1053_AutoResync()
{
	if(!VS1053_SciWrite(VS1053_REG_WRAMADDR, 0x1E29)) return false; /* Auto Resync */
	if(!VS1053_SciWrite(VS1053_REG_WRAM, 0)) return false;
	return true;
}

/* Set decode time */
bool VS1053_SetDecodeTime(uint16_t time)
{
	if(!VS1053_SciWrite(VS1053_REG_DECODE_TIME, time)) return false;
	if(!VS1053_SciWrite(VS1053_REG_DECODE_TIME, time)) return false;
	return true;
}

uint16_t VS1053_GetDecodeTime(void) {
	uint16_t time = 0;
	if(!VS1053_SciRead(VS1053_REG_DECODE_TIME, &time)) return false;
	return time;
}

/* Send endfill bytes */
bool VS1053_SendEndFill(uint16_t num)
{
	uint16_t regVal;
	if(!VS1053_SciWrite(VS1053_REG_WRAMADDR, 0x1E06)) return false;	/* endFill */
	if(!VS1053_SciRead(VS1053_REG_WRAM, &regVal)) return false;
	endFillByte = regVal & 0xFF;

	for(uint16_t i = 0; i < num; i++)
	{
		VS1053_SdiWrite(endFillByte);
	}
	return true;
}

/* Check DREQ pin */
bool VS1053_IsBusy()
{
	if(hal_gpio_readpin(&gpio_vs1053_dreq) == 1) return false;
	else return true; // busy
}

/* SCI Tx */
bool VS1053_SciWrite( uint8_t address, uint16_t input )
{
	uint8_t buffer[4];

	buffer[0] = VS1053_WRITE_CMD;
	buffer[1] = address;
	buffer[2] = input >> 8;			/* Input MSB */
	buffer[3] = input & 0x00FF;		/* Input LSB */

	while (hal_gpio_readpin(&gpio_vs1053_dreq) == 0);	/* Wait DREQ High */

	XCS_LOW;			/* XCS Low */
	if(hal_spi_transfer(vs1053spidrv, buffer, sizeof(buffer), VS1053_SPI_TIMEOUT) != true) return false;
	XCS_HIGH;			/* XCS High */

	while (hal_gpio_readpin(&gpio_vs1053_dreq) == 0);	/* Wait DREQ High */

	return true;
}

/* SCI TxRx */
bool VS1053_SciRead( uint8_t address, uint16_t *res)
{
	uint8_t dummy = 0xFF;
	uint8_t txBuffer[2];
	uint8_t rxBuffer[2];

	txBuffer[0] = VS1053_READ_CMD;
	txBuffer[1] = address;

	while (hal_gpio_readpin(&gpio_vs1053_dreq) == 0);	/* Wait DREQ High */

	XCS_LOW;        /* XCS Low */
	if(hal_spi_transfer(vs1053spidrv, txBuffer, sizeof(txBuffer), VS1053_SPI_TIMEOUT) != true) return false;
	if(hal_spi_txrx(vs1053spidrv, &dummy, &rxBuffer[0], 1, VS1053_SPI_TIMEOUT) != true) return false;
	if(hal_spi_txrx(vs1053spidrv, &dummy, &rxBuffer[1], 1, VS1053_SPI_TIMEOUT) != true) return false;
	XCS_HIGH;       /* XCS High */

	while (hal_gpio_readpin(&gpio_vs1053_dreq) == 0);	/* Wait DREQ High */

	*res = rxBuffer[0];     /* Received data */
	*res <<= 8;				/* MSB */
	*res |= rxBuffer[1];	/* LSB */

	return true;
}

/* SDI Tx */
bool VS1053_SdiWrite( uint8_t input )
{
	while (hal_gpio_readpin(&gpio_vs1053_dreq) == 0);	/* Wait DREQ High */

	XDCS_LOW;			/* XDCS Low(SDI) */
	if(hal_spi_transfer(vs1053spidrv, &input, 1, VS1053_SPI_TIMEOUT) != true) return false;		/* SPI Tx 1 byte */
	XDCS_HIGH;			/* XDCS High(SDI) */

	return true;
}

/* SDI Tx 32 bytes */
bool VS1053_SdiWrite32( uint8_t *input32 )
{
	while (hal_gpio_readpin(&gpio_vs1053_dreq) == 0);	/* Wait DREQ High */

	XDCS_LOW;			/* XDCS Low(SDI) */
	if(hal_spi_transfer(vs1053spidrv, input32, 32, VS1053_SPI_TIMEOUT) != true) return false; /* SPI Tx 32 bytes */
	XDCS_HIGH;			/* XDCS High(SDI) */

	return true;
}
