#ifndef _VS1053_H_
#define _VS1053_H_

#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include "spi.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* spi driver */
extern spidrv_t* vs1053spidrv;

/* Functions */
bool VS1053_Init();
void VS1053_Reset();
bool VS1053_SoftReset();
bool VS1053_SetVolume(uint8_t volumeLeft, uint8_t volumeRight);
bool VS1053_SetMode(uint16_t mode);
bool VS1053_GetMode(uint16_t *mode);
bool VS1053_AutoResync();
bool VS1053_SetDecodeTime(uint16_t time);
uint16_t VS1053_GetDecodeTime(void);
bool VS1053_SendEndFill(uint16_t num);
bool VS1053_IsBusy();
bool VS1053_SciWrite(uint8_t address, uint16_t input);
bool VS1053_SciRead(uint8_t address, uint16_t *res);
bool VS1053_SdiWrite(uint8_t input);
bool VS1053_SdiWrite32(uint8_t *input32);

extern uint8_t endFillByte;

#ifdef __cplusplus
}
#endif

#endif
