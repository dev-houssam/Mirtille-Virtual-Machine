#include "../include/me_engine.h"
#include "../include/me_system.h"
#include <pthread.h>

char * createTabChar(int size){
	char * str = (char *) malloc(sizeof(char)  * size);
	if(str == NULL) {
		return NULL;
	}
	return str;
}

void StringCopy(char * dst, const char *src){
	dst = createTabChar(strlen(src));
	strcpy(dst, src);
}

Mirtille_Engine * me_create_MirtilleEngine(ME_System *paramSys, const char *dataDir, const char *saveDir){
	Mirtille_Engine * me = (Mirtille_Engine *) malloc(sizeof(Mirtille_Engine));
	if(me == NULL){
		return NULL;
	}
	me->sys 			 = paramSys;
	printf("+++++++\n");
	me->vm 				 = create_VirtualMachine(me->video, me->sys);
	printf("++++++++--------------\n");
	StringCopy(me->_dataDir, dataDir); 
	StringCopy(me->_saveDir, saveDir); 
	me->_stateSlot = 0;
	printf("***************************--------------\n");
	return me;
}

void me_configuration_init_engine(Mirtille_Engine * me){
	//Initialisation de toutes les parties prenantes (Composant)
	printf("void me_configuration_init_engine(Mirtille_Engine * me)\n");

	//Video
	me->video = me_create_video();
	pthread_t screen_task;
	pthread_create(&screen_task, NULL, Screen, (void *) me->video);
	pthread_detach(screen_task);
	//me_configuration_init_video(me->video);
	printf("me->video = me_create_video();\n");

}

// pc+0|00000000.00000000.00000000.00000000|
// pc+4|00000000.00000000.00000000.00000000|
// pc+8|00000000.00000000.00000000.00000000|
uint64_t fetch64bitsInstruction(Instruction * instructionSet){
	return instructionSet->instr[instructionSet->pc++];
}

// OP  |00000000.xxxxxxxx.xxxxxxxx.xxxxxxxx|
uint8_t fetch8bitsInstructionOp(uint64_t instruction){
	return instruction << 50;
}

// DST |00000000.00000000.xxxxxxxx.xxxxxxxx|
uint8_t fetch8bitsInstructionDst(uint64_t instruction){
	
	return instruction << 40;
}

// DST |00000000.00000000.xxxxxxxx.xxxxxxxx|
uint16_t fetch16bitsInstructionSrc(uint64_t instruction){
	
	return 32;
}

void fetchingStep(
	uint64_t * instruction64, 
	uint8_t  * operator,
	uint8_t  * operand1,
	uint32_t * operand2,
	uint8_t  * operand3,
	uint8_t	 * operand4
	){
	operator = NULL;
	operand1 = NULL; 
	operand2 = NULL;
	operand3 = NULL;
	operand4 = NULL;
}

void printX64Instruction(uint64_t instruction){
	printf("OP=%ld op1=%ld op2=%ld func=%ld\n", instruction << 8, instruction << 16, instruction << 32, instruction << 42 );
}


void me_run(Mirtille_Engine * me) {
	printf("RUN\n");
	me->vm->instructions.instr = (uint64_t * ) malloc(sizeof(uint64_t) * 100);
	for(int i = 0; i < 100; i++){
		me->vm->instructions.instr[i] = 0xFFFFFA & i; 
	}
	me->vm->instructions.pc = 0;
	while (me->vm->instructions.pc < 10000) {
		uint64_t instruction = fetch64bitsInstruction(&me->vm->instructions);
        uint8_t op 			 = fetch8bitsInstructionOp(instruction);
        uint8_t dst 		 = fetch8bitsInstructionDst(instruction);
        uint16_t src 		 = fetch16bitsInstructionSrc(instruction);
        switch(op){
        	case 0x00:
        		me_op_mov(me->vm);
				me_op_add(me->vm);
				me_op_call(me->vm);
				me_op_ret(me->vm);
				me_op_jmp(me->vm);
				me_op_jnz(me->vm);
				me_op_selectVideoPage(me->vm);
				me_op_fillVideoPage(me->vm);
				me_op_copyVideoPage(me->vm);
				me_op_blitFramebuffer(me->vm);	
				me_op_sub(me->vm);
				me_op_and(me->vm);
				me_op_or(me->vm);
				me_op_shl(me->vm);
				me_op_shr(me->vm);
				me_op_updateMemList(me->vm);
				me_inp_handleSpecialKeys(me->vm);
				me_hostFrame(me->vm);
        		break;

        }
		//me_processInput(me);
		//me_hostFrame(me->vm);
		//Fetch Instruction
		//VM :: Instruction instructions;
		//uint8_t byteOp = fetchByteFromInstructionsSet(&me->vm->instructions);
		printX64Instruction(instruction);
	}
}

// void me_destroy_System(ME_System * me_system);
void me_destroy_MirtilleEngine(Mirtille_Engine * me){
	me_finish(me);
	me_destroy_System(me->sys);
}


void me_configuration_init (Mirtille_Engine * me) {
	//Init system
	me_init_System(me->sys, "Mirtille Virtual Machine");
	me_configuration_init_video(me->video);
	me_configuration_init_VM(me->vm);
}


void me_configuration_engine (Mirtille_Engine * me) {

}


void me_finish(Mirtille_Engine * me) {
	// free something
}


void me_processInput(Mirtille_Engine * me) {
	/*
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
	*/
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
	/*
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
	*/
}



void me_loadOSState(Mirtille_Engine * me, uint8_t slot) {
	/*   ::FILE::
		 |  HEADER  | 32 BITS |
		 ----------- --------
		 | CONTENTS | N  BITS |
	*/
	/*
	char stateFile[20];
	me_makeOSStateName(slot, stateFile);
	//File f(true);
	if (!f.open(stateFile, me->_saveDir, "rb")) {
		//warning("Unable to open state file '%s'", stateFile);
	} else {
		uint32_t id = f.readUint32BE();
		if (id != 'AWSV') {
			//warning("Bad savegame format");
		} else {
			// header
			uint16_t ver = f.readUint16BE();
			f.readUint16BE();
			char hdrdesc[32];
			f.read(hdrdesc, sizeof(hdrdesc));
			// contents
			//Serializer me_serz(&f, Serializer::SM_LOAD, res._memPtrStart, ver);
			//me_saveOrLoad(me->vm, me_serz);
			//me_saveOrLoad(me->video, me_serz);
		}
		if (f.ioErr()) {
			//warning("I/O error when loading game state");
		} else {
			//debug(DBG_INFO, "Loaded state from slot %d", me->_stateSlot);
		}
	}*/
}