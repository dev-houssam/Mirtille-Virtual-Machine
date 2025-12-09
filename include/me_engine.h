#ifndef __ME_ENGINE_H__
#define __ME_ENGINE_H__

#include "intern.h"
#include "vm.h"
#include "video.h"

struct System;

typedef struct {
	enum {
		MAX_SAVE_SLOTS = 100
	};

	System *sys;
	Video video;
	Mirtille_VirtualMachine vm;
	const char * _dataDir, 
	const char * _saveDir;
	uint8_t 	 _stateSlot;	
} Mirtille_Engine;

me_create_MirtilleEngine(Mirtille_Engine * me, System *stub, const char *dataDir, const char *saveDir);
me_destroy_MirtilleEngine(Mirtille_Engine * me);

void me_run(Mirtille_Engine * me);
void me_init(Mirtille_Engine * me);
void me_finish(Mirtille_Engine * me);
void me_processInput(Mirtille_Engine * me);

#endif