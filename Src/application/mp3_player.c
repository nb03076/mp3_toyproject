#include <mp3_player.h>
#include "fatfs.h"
#include "stm32f4xx_ll_utils.h"
#include "resources.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 	32

static uint8_t mp3Buffer[BUFFER_SIZE];
static uint32_t mp3FileSize;
static uint32_t readBytes;
static uint16_t cnt = 0;

bool isPlaying = false;
bool isFileOpen = false;

static FATFS fs;
static FIL mp3File;

bool MP3_IsPlaying(void) {
	return isPlaying;
}

bool Mp3_IsFileOpen(void) {
	return isFileOpen;
}

bool MP3_SetFile(const char *filename) {
	char buffer[25];
	memset(buffer, '\0', 25);
	f_close(&mp3File);
	sprintf(buffer, "/mp3/%s", filename);
	f_open(&mp3File, buffer, FA_READ);

	return true;
}

/* Initialize VS1053 & Open a file */
bool MP3_Init()
{
	/* Initialize VS1053 */
    if(!VS1053_Init()) return false;

    /* Mount SD Card */
    if(f_mount(&fs, "", 0) != FR_OK) return false;

    return true;
}

bool MP3_Play(void)
{
	if(isPlaying) MP3_Stop();

	if(!VS1053_SetMode(0x4800)) return false;	/* SM LINE1 | SM SDINEW */
	if(!VS1053_AutoResync()) return false;		/* AutoResync */
	if(!VS1053_SetDecodeTime(0)) return false;	/* Set decode time */
	if(!VS1053_SetVolume( 0x0F, 0x0F )) return false;	/* Small number is louder */

	mp3FileSize = f_size(&mp3File);

	/* Set flags */
	isFileOpen = true;
	isPlaying = true;

    return true;
}

void MP3_Stop(void)
{
	/* Refer to page 49 of VS1053 datasheet */

	uint16_t mode;
	VS1053_SendEndFill(2052);	/* send endfill bytes */
	VS1053_SetMode(0x4808);		/* SM LINE1 | SM SDINEW | SM CANCEL */
	VS1053_SendEndFill(32);		/* send endfill bytes */
	LL_mDelay(100);
	VS1053_GetMode(&mode);		/* get mode value */
	if((mode & 0x08) != 0x0)	/* if SM CANCEL is not clear, soft reset */
	{
		VS1053_SoftReset();
	}

	isPlaying = false;			/* Stop flag */
	isFileOpen = false;			/* Close flag */
}

void MP3_Pause(void)
{
	if(isPlaying) isPlaying = false;
}

void MP3_Resume(void)
{
	if(!isPlaying) isPlaying = true;
}

/* Send mp3 buffer to VS1053 */
void MP3_Feeder(void)
{
	if(!isPlaying || !isFileOpen) return;

	if(mp3FileSize > BUFFER_SIZE)
	{
		/* Fill the buffer */
		f_read(&mp3File, mp3Buffer, BUFFER_SIZE, (void*)&readBytes);

		/* Tx buffer */
		VS1053_SdiWrite32( mp3Buffer );

		/* bytes to send */
		mp3FileSize -= BUFFER_SIZE;
	}
	else
	{
		/* Read left bytes */
		f_read(&mp3File, mp3Buffer, mp3FileSize, (void*)&readBytes);

		/* Tx buffer */
		for (cnt = 0; cnt < mp3FileSize; cnt++)
		{
			while(!VS1053_SdiWrite(*(mp3Buffer + cnt)));
		}

		/* Stop when played the whole file */
		MP3_Stop();
	}
}
