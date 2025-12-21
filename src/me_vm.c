#include "../include/me_vm.h"
#include "../include/me_video.h"
#include "../include/me_system.h"

Mirtille_VirtualMachine * me_init(Mirtille_VirtualMachine *me, ME_Video *vid, ME_System *stub){
	me->video = vid;
	me->sys 	= stub;
}

void me_configuration_init(Mirtille_VirtualMachine * me) {
	memset(me->vmVariables, 0, sizeof(me->vmVariables));
	me->vmVariables[0x54] = 0x81;
	me->vmVariables[VM_VARIABLE_RANDOM_SEED] = time(0); // preparation de Noyau de generation de nombre aléatoire
	#ifdef BYPASS_PROTECTION
	   // these 3 variables are set by the game code
	   me->vmVariables[0xBC] = 0x10;
	   me->vmVariables[0xC6] = 0x80;
	   me->vmVariables[0xF2] = 4000;
	   // these 2 variables are set by the engine executable
	   me->vmVariables[0xDC] = 33;
	#endif
}



void op_mov(Mirtille_VirtualMachine * me) {
	uint8_t dstVariableId = me->_scriptPtr.fetchByte();
	uint8_t srcVariableId = me->_scriptPtr.fetchByte();	
	debug(DBG_VM, "Mirtille_VirtualMachine: op_mov(0x%02X, 0x%02X)", dstVariableId, srcVariableId);
	me->vmVariables[dstVariableId] = me->vmVariables[srcVariableId];
}

void op_add(Mirtille_VirtualMachine * me) {
	uint8_t dstVariableId = me->_scriptPtr.fetchByte();
	uint8_t srcVariableId = me->_scriptPtr.fetchByte();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_add(0x%02X, 0x%02X)", dstVariableId, srcVariableId);
	me->vmVariables[dstVariableId] += me->vmVariables[srcVariableId];
}


void op_call(Mirtille_VirtualMachine * me) {

	uint16_t offset = me->_scriptPtr.fetchWord();
	uint8_t sp = me->_stackPtr;

	debug(DBG_VM, "Mirtille_VirtualMachine::op_call(0x%X)", offset);
	me->_scriptStackCalls[sp] = me->_scriptPtr.pc - res->segBytecode;
	if (me->_stackPtr == 0xFF) {
		error("Mirtille_VirtualMachine::op_call() ec=0x%X stack overflow", 0x8F);
	}
	++(me->_stackPtr);
	me->_scriptPtr.pc = res->segBytecode + offset ;
}

void op_ret(Mirtille_VirtualMachine * me) {
	debug(DBG_VM, "Mirtille_VirtualMachine::op_ret()");
	if (me->_stackPtr == 0) {
		error("Mirtille_VirtualMachine::op_ret() ec=0x%X stack underflow", 0x8F);
	}	
	--(me->_stackPtr);
	uint8_t sp = me->_stackPtr;
	me->_scriptPtr.pc = res->segBytecode + me->_scriptStackCalls[sp];
}


void op_jmp(Mirtille_VirtualMachine * me) {
	uint16_t pcOffset = me->_scriptPtr.fetchWord();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_jmp(0x%02X)", pcOffset);
	me->_scriptPtr.pc = res->segBytecode + pcOffset;	
}


void op_jnz(Mirtille_VirtualMachine * me) {
	uint8_t i = me->_scriptPtr.fetchByte();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_jnz(0x%02X)", i);
	--(me->vmVariables[i]);
	if (me->vmVariables[i] != 0) {
		op_jmp();
	} else {
		me->_scriptPtr.fetchWord();
	}
}

void op_condJmp(Mirtille_VirtualMachine * me) {
	uint8_t opcode = me->_scriptPtr.fetchByte();
  const uint8_t var = me->_scriptPtr.fetchByte();
  int16_t b = me->vmVariables[var];
	int16_t a;

	if (opcode & 0x80) {
		a = me->vmVariables[me->_scriptPtr.fetchByte()];
	} else if (opcode & 0x40) {
    a = me->_scriptPtr.fetchWord();
	} else {
    a = me->_scriptPtr.fetchByte();
	}
	debug(DBG_VM, "Mirtille_VirtualMachine::op_condJmp(%d, 0x%02X, 0x%02X)", opcode, b, a);

	// Check if the conditional value is met.
	bool expr = false;
	enum ME_JMP_CONDITION condition_jmp = opcode & 7;
	switch (condition_jmp) {
	case ME_JZ:	// jz
		expr = (b == a);
#ifdef BYPASS_PROTECTION
      if (res->currentPartId == 16000) {
        //
        // 0CB8: jmpIf(VAR(0x29) == VAR(0x1E), @0CD3)
        // ...
        //
        if (b == 0x29 && (opcode & 0x80) != 0) {
          // 4 symbols
          me->vmVariables[0x29] = me->vmVariables[0x1E];
          me->vmVariables[0x2A] = me->vmVariables[0x1F];
          me->vmVariables[0x2B] = me->vmVariables[0x20];
          me->vmVariables[0x2C] = me->vmVariables[0x21];
          // counters
          me->vmVariables[0x32] = 6;
          me->vmVariables[0x64] = 20;
          warning("Script::op_condJmp() bypassing protection");
          expr = true;
        }
      }
#endif
		break;
	case ME_JNZ: // jnz
		expr = (b != a);
		break;
	case ME_JG: // jg
		expr = (b > a);
		break;
	case ME_JGE: // jge
		expr = (b >= a);
		break;
	case ME_JL: // jl
		expr = (b < a);
		break;
	case ME_JLE: // jle
		expr = (b <= a);
		break;
	default:
		warning("Mirtille_VirtualMachine::op_condJmp() invalid condition %d", (opcode & 7));
		break;
	}

	if (expr) {
		op_jmp();
	} else {
		me->_scriptPtr.fetchWord();
	}

}


void op_selectVideoPage(Mirtille_VirtualMachine * me) {
	uint8_t frameBufferId = me->_scriptPtr.fetchByte();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_selectVideoPage(%d)", frameBufferId);
	me->video->changePagePtr1(frameBufferId);
}

void op_fillVideoPage(Mirtille_VirtualMachine * me) {
	uint8_t pageId = me->_scriptPtr.fetchByte();
	uint8_t color = me->_scriptPtr.fetchByte();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_fillVideoPage(%d, %d)", pageId, color);
	me->video->fillPage(pageId, color);
}

void op_copyVideoPage(Mirtille_VirtualMachine * me) {
	uint8_t srcPageId = me->_scriptPtr.fetchByte();
	uint8_t dstPageId = me->_scriptPtr.fetchByte();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_copyVideoPage(%d, %d)", srcPageId, dstPageId);
	me->video->copyPage(srcPageId, dstPageId, me->vmVariables[VM_VARIABLE_SCROLL_Y]);
}


uint32_t lastTimeStamp = 0;
void op_blitFramebuffer(Mirtille_VirtualMachine * me) {

	uint8_t pageId = _scriptPtr.fetchByte();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_blitFramebuffer(%d)", pageId);
	inp_handleSpecialKeys();

  int32_t delay = sys->getTimeStamp() - lastTimeStamp;
  int32_t timeToSleep = me->vmVariables[VM_VARIABLE_PAUSE_SLICES] * 20 - delay;

  // The bytecode will set vmVariables[VM_VARIABLE_PAUSE_SLICES] from 1 to 5
  // The virtual machine hence indicate how long the image should be displayed.

  if (timeToSleep > 0) {
    sys->sleep(timeToSleep);
  }

  lastTimeStamp = sys->getTimeStamp();

	//What is this ??? aaahhhh ! we are looking in 0xF7 to put register to 0 as reset memory case before update video screen !!! OK ???
	me->vmVariables[0xF7] = 0;

	me->video->updateDisplay(pageId);
}

void op_drawString(Mirtille_VirtualMachine * me) {
	uint16_t stringId = me->_scriptPtr.fetchWord();
	uint16_t x = me->_scriptPtr.fetchByte();
	uint16_t y = me->_scriptPtr.fetchByte();
	uint16_t color = me->_scriptPtr.fetchByte();

	debug(DBG_VM, "Mirtille_VirtualMachine::op_drawString(0x%03X, %d, %d, %d)", stringId, x, y, color);

	me->video->drawString(color, x, y, stringId);
}

void op_sub(Mirtille_VirtualMachine * me) {
	uint8_t i = me->_scriptPtr.fetchByte();
	uint8_t j = me->_scriptPtr.fetchByte();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_sub(0x%02X, 0x%02X)", i, j);
	me->vmVariables[i] -= me->vmVariables[j];
}

void op_and(Mirtille_VirtualMachine * me) {
	uint8_t variableId = me->_scriptPtr.fetchByte();
	uint16_t n = me->_scriptPtr.fetchWord();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_and(0x%02X, %d)", variableId, n);
	me->vmVariables[variableId] = (uint16_t)me->vmVariables[variableId] & n;
}

void op_or(Mirtille_VirtualMachine * me) {
	uint8_t variableId = me->_scriptPtr.fetchByte();
	uint16_t value = me->_scriptPtr.fetchWord();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_or(0x%02X, %d)", variableId, value);
	me->vmVariables[variableId] = (uint16_t)me->vmVariables[variableId] | value;
}

void op_shl(Mirtille_VirtualMachine * me) {
	uint8_t variableId =		  me->_scriptPtr.fetchByte();
	uint16_t leftShiftValue = me->_scriptPtr.fetchWord();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_shl(0x%02X, %d)", variableId, leftShiftValue);
	me->vmVariables[variableId] = (uint16_t)me->vmVariables[variableId] << leftShiftValue;
}

void op_shr(Mirtille_VirtualMachine * me) {
	uint8_t variableId = me->_scriptPtr.fetchByte();
	uint16_t rightShiftValue = me->_scriptPtr.fetchWord();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_shr(0x%02X, %d)", variableId, rightShiftValue);
	me->vmVariables[variableId] = (uint16_t)me->vmVariables[variableId] >> rightShiftValue;
}

void op_updateMemList(Mirtille_VirtualMachine * me) {
	uint16_t resourceId = me->_scriptPtr.fetchWord();
	debug(DBG_VM, "Mirtille_VirtualMachine::op_updateMemList(%d)", resourceId);

	if (resourceId == 0) {
		res->invalidateRes();
	} else {
		res->loadPartsOrMemoryEntry(resourceId);
	}
}

#define COLOR_BLACK 0xFF
#define DEFAULT_ZOOM 0x40


void inp_handleSpecialKeys(Mirtille_VirtualMachine * me) {

	if (sys->input.pause) {

		if (res->currentPartId != GAME_PART1 && res->currentPartId != GAME_PART2) {
			sys->input.pause = false;
			while (!sys->input.pause) {
				sys->processEvents();
				sys->sleep(200);
			}
		}
		sys->input.pause = false;
	}

	if (sys->input.code) {
		sys->input.code = false;
		if (res->currentPartId != GAME_PART_LAST && res->currentPartId != GAME_PART_FIRST) {
			res->requestedNextPart = GAME_PART_LAST;
		}
	}

	// XXX
	if (me->vmVariables[0xC9] == 1) {
		warning("Mirtille_VirtualMachine::inp_handleSpecialKeys() unhandled case (vmVariables[0xC9] == 1)");
	}

}

void me_saveOrLoad(Mirtille_VirtualMachine * me, Serializer &ser) {
	Serializer::Entry entries[] = {
		SE_ARRAY(me->vmVariables, 0x100, Serializer::SES_INT16, VER(1)),
		SE_ARRAY(me->_scriptStackCalls, 0x100, Serializer::SES_INT16, VER(1)),
		SE_END()
	};
	ser.saveOrLoadEntries(entries);
}

void me_hostFrame(Mirtille_VirtualMachine *me){
	// hostFrame
}