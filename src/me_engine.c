#include "me_engine.h"
#include "file.h"
#include "sys.h"

void me_create_MirtilleEngine(Mirtille_Engine * me, System *paramSys, const char *dataDir, const char *saveDir){
	me->sys 			 = paramSys;
	me->vm 				 = create_MirtualMachine(&video, sys);
	init(me->video, &res, sys); 
	me->_dataDir 	 = dataDir; 
	me->_saveDir 	 = saveDir; 
	me->_stateSlot = 0;

}

void me_run(Mirtille_Engine * me) {
	while (!me->sys->input.quit) {
		me_processInput(me);
		me_hostFrame(me->vm);
	}
}

// void me_destroy_System(ME_System * me_system);
void me_destroy_MirtilleEngine(Mirtille_Engine * me){
	me_finish(me);
	me_destroy_System(me->sys);
}


void me_init(Mirtille_Engine * me) {
	//Init system
	me->sys->init("Mirtille Virtual Machine");
	me_configuration_init_video(me->video);
	me->vm.init();

}


void me_finish(Mirtille_Engine * me) {
	// free something
}


void me_processInput(Mirtille_Engine * me) {
	if (me->sys->input.load) {
		me_loadOSState(me->_stateSlot);
		me->sys->input.load = false;
	}
	if (me->sys->input.save) {
		me_saveOSState(me->_stateSlot, "quicksave");
		me->sys->input.save = false;
	}
	if (me->sys->input.stateSlot != 0) {
		int8_t slot = me->_stateSlot + sys->input.stateSlot;
		if (slot >= 0 && slot < MAX_SAVE_SLOTS) {
			me->_stateSlot = slot;
			debug(DBG_INFO, "Current game state slot is %d", me->_stateSlot);
		}
		me->sys->input.stateSlot = 0;
	}
}



void me_makeOSStateName(Mirtille_Engine * me, uint8_t slot, char *buf) {
	sprintf(buf, "raw.s%02d", slot);
}



void me_saveOSState(Mirtille_Engine * me, uint8_t slot, const char *desc) {
	/*   ::FILE::
		 |  HEADER  | 32 BITS |
		 ----------- --------
		 | CONTENTS | N  BITS |
	*/
	char stateFile[20];
	me_makeOSStateName(slot, stateFile);
	File f(true);
	if (!f.open(stateFile, me->_saveDir, "wb")) {
		warning("Unable to save state file '%s'", stateFile);
	} else {
		// header
		f.writeUint32BE('AWSV');
		f.writeUint16BE(Serializer::CUR_VER);
		f.writeUint16BE(0);
		char hdrdesc[32];
		strncpy(hdrdesc, desc, sizeof(hdrdesc) - 1);
		f.write(hdrdesc, sizeof(hdrdesc));
		// contents
		Serializer me_serz(&f, Serializer::SM_SAVE, res._memPtrStart);
		me_saveOrLoad(me->vm, me_serz);
		me_saveOrLoad(me->video, me_serz);
		if (f.ioErr()) {
			warning("I/O error when saving game state");
		} else {
			debug(DBG_INFO, "Saved state to slot %d", me->_stateSlot);
		}
	}
}



void me_loadOSState(Mirtille_Engine * me, uint8_t slot) {
	/*   ::FILE::
		 |  HEADER  | 32 BITS |
		 ----------- --------
		 | CONTENTS | N  BITS |
	*/

	char stateFile[20];
	me_makeOSStateName(slot, stateFile);
	File f(true);
	if (!f.open(stateFile, me->_saveDir, "rb")) {
		warning("Unable to open state file '%s'", stateFile);
	} else {
		uint32_t id = f.readUint32BE();
		if (id != 'AWSV') {
			warning("Bad savegame format");
		} else {
			// header
			uint16_t ver = f.readUint16BE();
			f.readUint16BE();
			char hdrdesc[32];
			f.read(hdrdesc, sizeof(hdrdesc));
			// contents
			Serializer me_serz(&f, Serializer::SM_LOAD, res._memPtrStart, ver);
			me_saveOrLoad(me->vm, me_serz);
			me_saveOrLoad(me->video, me_serz);
		}
		if (f.ioErr()) {
			warning("I/O error when loading game state");
		} else {
			debug(DBG_INFO, "Loaded state from slot %d", me->_stateSlot);
		}
	}
}