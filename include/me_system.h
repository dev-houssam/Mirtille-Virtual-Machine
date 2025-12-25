#ifndef __ME_SYSTEM_H__
#define __ME_SYSTEM_H__

#include "me_video.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef enum {
	OK
} ME_VIDEO_SYSTEM_STATE_T;

typedef struct
{
	ME_VIDEO_SYSTEM_STATE_T setVideoState;
} ME_System;

ME_System * create_MirtilleSystem();

void me_init_System(ME_System * me_system, const char * title);

void me_configuration_init_system(ME_System * me_system);

void me_destroy_System(ME_System * me_system);

#endif

