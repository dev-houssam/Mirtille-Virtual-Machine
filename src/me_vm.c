#include "../include/me_vm.h"
#include "../include/me_video.h"
#include "../include/me_system.h"



Mirtille_VirtualMachine * create_VirtualMachine( ME_Video *vid, ME_System *stub){
	
	//assert(vid != NULL);
	//assert(stub != NULL);

	Mirtille_VirtualMachine * MVM = (Mirtille_VirtualMachine*) malloc(sizeof(Mirtille_VirtualMachine));
	if(NULL == MVM){
		return NULL;
	}
	MVM->me_video = vid;
	MVM->me_system 	= stub;
	return MVM;
}

void me_configuration_init_VM(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	memset(me->me_vmVariables, 0, sizeof(me->me_vmVariables));
}

uint8_t fetchByteFromInstructionsSet(Instruction * instructionSet){
	assert(instructionSet != NULL);
	return instructionSet->instr[(instructionSet->pc)++];
}

uint16_t fetchWordFromInstructionsSet(Instruction * instructionSet){
	assert(instructionSet != NULL);
	return instructionSet->instr[(instructionSet->pc)++];
}


void me_op_mov(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t dstVariableId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint8_t srcVariableId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));	
	//debug(DBG_VM, "Mirtille_VirtualMachine: op_mov(0x%02X, 0x%02X)", dstVariableId, srcVariableId);
	me->me_vmVariables[dstVariableId] = me->me_vmVariables[srcVariableId];
}

void me_op_add(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t dstVariableId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint8_t srcVariableId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_add(0x%02X, 0x%02X)", dstVariableId, srcVariableId);
	me->me_vmVariables[dstVariableId] += me->me_vmVariables[srcVariableId];
}


void me_op_call(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint16_t offset = /*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	//uint8_t sp = me->none;

	//debug(DBG_VM, "Mirtille_VirtualMachine::op_call(0x%X)", offset);
	//me->_scriptStackCalls[sp] = me->_scriptPtr.pc - res->segBytecode;
	if (me->none == 0xFF) {
		//error("Mirtille_VirtualMachine::op_call() ec=0x%X stack overflow", 0x8F);
	}
	++(me->none);
	//me->_scriptPtr.pc = res->segBytecode + offset ;
}

void me_op_ret(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_ret()");
	if (me->none == 0) {
		//error("Mirtille_VirtualMachine::op_ret() ec=0x%X stack underflow", 0x8F);
	}	
	--(me->none);
	uint8_t sp = me->none;
	//me->_scriptPtr.pc = res->segBytecode + me->_scriptStackCalls[sp];
}


void me_op_jmp(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint16_t pcOffset = /*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_jmp(0x%02X)", pcOffset);
	me->instructions.pc = 1 + pcOffset;	
}


void me_op_jnz(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t i = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_jnz(0x%02X)", i);
	--(me->me_vmVariables[i]);
	if (me->me_vmVariables[i] != 0) {
		//op_jmp();
	} else {
		/*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	}
}

void me_op_condJmp(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t opcode = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
  const uint8_t var = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
  int16_t b = me->me_vmVariables[var];
	int16_t a;

	if (opcode & 0x80) {
		//a = me->me_vmVariables[me->_scriptPtr.fetchByte()];
	} else if (opcode & 0x40) {
    a = /*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	} else {
    a = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	}
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_condJmp(%d, 0x%02X, 0x%02X)", opcode, b, a);

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
          me->me_vmVariables[0x29] = me->me_vmVariables[0x1E];
          me->me_vmVariables[0x2A] = me->me_vmVariables[0x1F];
          me->me_vmVariables[0x2B] = me->me_vmVariables[0x20];
          me->me_vmVariables[0x2C] = me->me_vmVariables[0x21];
          // counters
          me->me_vmVariables[0x32] = 6;
          me->me_vmVariables[0x64] = 20;
          //warning("Script::op_condJmp() bypassing protection");
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
		//warning("Mirtille_VirtualMachine::op_condJmp() invalid condition %d", (opcode & 7));
		break;
	}

	if (expr) {
		//op_jmp();
	} else {
		/*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	}

}


void me_op_selectVideoPage(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t frameBufferId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_selectVideoPage(%d)", frameBufferId);
	//me_changePagePtr1(me->me_video, frameBufferId);
}

void me_op_fillVideoPage(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t pageId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint8_t color = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_fillVideoPage(%d, %d)", pageId, color);
	//me_fillPage(me->me_video, pageId, color);
}

void me_op_copyVideoPage(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t srcPageId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint8_t dstPageId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_copyVideoPage(%d, %d)", srcPageId, dstPageId);
	//me_copyPage(me->me_video, srcPageId, dstPageId, me->me_vmVariables[10]);
}


uint32_t lastTimeStamp = 0;

void me_op_blitFramebuffer(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t pageId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_blitFramebuffer(%d)", pageId);
	int getTimeStamp = 2;
  int32_t delay = getTimeStamp - lastTimeStamp;
  int32_t timeToSleep = me->me_vmVariables[10] * 20 - delay;

  // The bytecode will set vmVariables[VM_VARIABLE_PAUSE_SLICES] from 1 to 5
  // The virtual machine hence indicate how long the image should be displayed.

  if (timeToSleep > 0) {
    //sys->sleep(timeToSleep);
  }

  lastTimeStamp = getTimeStamp;

	//What is this ??? aaahhhh ! we are looking in 0xF7 to put register to 0 as reset memory case before update video screen !!! OK ???
	me->me_vmVariables[0xF7] = 0;
	if(me->me_video == NULL){
		printf("NULL : me_updateDisplay(me->me_video, pageId);\n");
	}
	//me_updateDisplay(me->me_video, pageId);

}

void me_op_sub(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t i = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint8_t j = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_sub(0x%02X, 0x%02X)", i, j);
	me->me_vmVariables[i] -= me->me_vmVariables[j];
}

void me_op_and(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t variableId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint16_t n = /*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_and(0x%02X, %d)", variableId, n);
	me->me_vmVariables[variableId] = (uint16_t)me->me_vmVariables[variableId] & n;
}

void me_op_or(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t variableId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint16_t value = /*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_or(0x%02X, %d)", variableId, value);
	me->me_vmVariables[variableId] = (uint16_t)me->me_vmVariables[variableId] | value;
}


void me_op_shl(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t variableId =		  /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint16_t leftShiftValue = /*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_shl(0x%02X, %d)", variableId, leftShiftValue);
	me->me_vmVariables[variableId] = (uint16_t)me->me_vmVariables[variableId] << leftShiftValue;
}

void me_op_shr(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint8_t variableId = /*GET*/ fetchByteFromInstructionsSet(&(me->instructions));
	uint16_t rightShiftValue = /*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_shr(0x%02X, %d)", variableId, rightShiftValue);
	me->me_vmVariables[variableId] = (uint16_t)me->me_vmVariables[variableId] >> rightShiftValue;
}

void me_op_updateMemList(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	uint16_t resourceId = /*GET*/ fetchWordFromInstructionsSet(&(me->instructions));
	//debug(DBG_VM, "Mirtille_VirtualMachine::op_updateMemList(%d)", resourceId);

}


void me_inp_handleSpecialKeys(Mirtille_VirtualMachine * me) {
	assert(me != NULL);
	/*if (me->sys->input.pause) {
			me->sys->input.pause = false;
			while (!me->sys->input.pause) {
				sys->processEvents();
				sys->sleep(200);
			}
		
		me->sys->input.pause = false;
	}

	if (me->sys->input.code) {
		me->sys->input.code = false;
	}

	// XXX
	if (me->me_vmVariables[0xC9] == 1) {
		//warning("Mirtille_VirtualMachine::inp_handleSpecialKeys() unhandled case (vmVariables[0xC9] == 1)");
	}*/

}

void me_saveOrLoad_VM(Mirtille_VirtualMachine * me, ME_Serializer *ser) {
	assert(me != NULL);
	assert(ser != NULL);
	/*Serializer::Entry entries[] = {
		SE_ARRAY(me->me_vmVariables, 0x100, Serializer::SES_INT16, VER(1)),
		SE_ARRAY(me->_scriptStackCalls, 0x100, Serializer::SES_INT16, VER(1)),
		SE_END()
	};
	ser.saveOrLoadEntries(entries);*/
}

void me_hostFrame(Mirtille_VirtualMachine *me){
	assert(me != NULL);
	// hostFrame
}