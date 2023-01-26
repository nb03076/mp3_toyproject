#include "mp3_app.h"
#include "mp3_player.h"

void mp3Thread(void* param) {
	MP3_Init();
	MP3_Play("/mp3/Mercy.mp3");

	while(1) {
		MP3_Feeder();
	}
}
