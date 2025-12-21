#ifndef __ME_SOUND_H__
#define __ME_SOUND_H__


#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "me_portaudio.h"


typedef struct {
	int64_t sCallbackCount;
	void *inputBuffer;
	void *outputBuffer;
	unsigned long framesPerBuffer;
	/*PaStreamCallbackTimeInfo* timeInfo;
	PaStreamCallbackFlags statusFlags;*/
	void *userData;
} ME_Sound;


///////////////////////////////////

///////////////////////////////////


#endif