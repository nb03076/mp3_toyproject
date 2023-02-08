#ifndef MP3_PLAYER_H_
#define MP3_PLAYER_H_

#include <stdbool.h>
#include <vs1053.h>
#include "stm32f4xx_hal.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* Functions */
bool MP3_SetFile(const char *filename);
bool MP3_IsPlaying(void);
bool Mp3_IsFileOpen(void);
bool MP3_Init(void);
bool MP3_Play(void);
void MP3_Stop(void);
void MP3_Pause(void);
void MP3_Resume(void);
void MP3_Feeder(void);


/* Flags */
extern bool isPlaying;
extern bool isFileOpen;

#ifdef __cplusplus
}
#endif

#endif /* MP3_PLAYER_H_ */
