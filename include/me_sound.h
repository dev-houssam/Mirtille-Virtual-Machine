#ifndef __ME_SOUND_H__
#define __ME_SOUND_H__

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "portaudio.h"

typedef struct {
	static int64_t sCallbackCount;
	const void *inputBuffer, void *outputBuffer, 
	unsigned long framesPerBuffer;
	const PaStreamCallbackTimeInfo* timeInfo;
	PaStreamCallbackFlags statusFlags;
	void *userData;
} ME_Sound;


///////////////////////////////////




///////////////////////////////////


#endif