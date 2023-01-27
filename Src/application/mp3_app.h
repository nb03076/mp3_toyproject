#ifndef APPLICATION_MP3_APP_H_
#define APPLICATION_MP3_APP_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	VOLUME_OFF,
	VOLUME_LEVEL_1,
	VOLUME_LEVEL_2,
	VOLUME_LEVEL_3,
	VOLUME_LEVEL_4,
	VOLUME_LEVEL_5,
	VOLUME_LEVEL_6,
	VOLUME_LEVEL_7,
}VolumeLevel;

void mp3Thread(void* param);


#ifdef __cplusplus
}
#endif
#endif /* APPLICATION_MP3_APP_H_ */
