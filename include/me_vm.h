/*
	Author : Houssam BACAR
	Project Name : Mirtille Virtual Machine
	Description : headers for Mirtille Virtual Machine
	Date : 04/12/2025
*/

#ifndef __ME_MIRTILLE_VIRTUALMACHINE_H__
#define __ME_MIRTILLE_VIRTUALMACHINE_H__

#include <stdint.h>
#include <assert.h>
#include "me_video.h"
#include "me_system.h"
#include "me_sound.h"
#include "me_ai.h"
#include "me_network.h"
#include "me_memory.h"

#define VM_NUM_VARIABLES 100

typedef uint16_t me_RegisterOnInt16_t;

typedef struct{

} OpcodeStub;

typedef struct {
	uint64_t * instr;
	long int pc;
} Instruction;

typedef struct {
	//Mirtille_VirtualMachine 
	void (*OpcodeStub)();
	OpcodeStub opcodeTable[100];

	//Composant critique : AI : on simule aussi un composant d'intelligence artificielle
	ME_Video   * me_video;
	ME_System  * me_system;
	ME_Sound   * me_sound; 
	ME_AI 	   * me_ai;
	ME_Network * me_network;
	ME_Memory  * me_memory;

	// Stocke les valeurs de variables ===> on va le transformer en Banque de registers
	me_RegisterOnInt16_t me_vmVariables[VM_NUM_VARIABLES];
	uint8_t _stackPtr;
	uint8_t none;
	Instruction instructions;
} Mirtille_VirtualMachine;


Mirtille_VirtualMachine * create_VirtualMachine(ME_Video *vid, ME_System *stub);
void me_configuration_init_VM(Mirtille_VirtualMachine * me);
uint8_t fetchByteFromInstructionsSet(Instruction * instructionSet);
uint16_t fetchWordFromInstructionsSet(Instruction * instructionSet);

//Instruction
void me_op_mov(Mirtille_VirtualMachine *me);
void me_op_add(Mirtille_VirtualMachine *me);
void me_op_call(Mirtille_VirtualMachine *me);
void me_op_ret(Mirtille_VirtualMachine *me);
void me_op_jmp(Mirtille_VirtualMachine *me);
void me_op_jnz(Mirtille_VirtualMachine *me);	
void me_op_sub(Mirtille_VirtualMachine *me);
void me_op_and(Mirtille_VirtualMachine *me);
void me_op_or(Mirtille_VirtualMachine *me);
void me_op_shl(Mirtille_VirtualMachine *me);
void me_op_shr(Mirtille_VirtualMachine *me);



void me_op_updateMemList(Mirtille_VirtualMachine *me);
void me_inp_handleSpecialKeys(Mirtille_VirtualMachine *me);
void me_hostFrame(Mirtille_VirtualMachine *me);
void me_op_selectVideoPage(Mirtille_VirtualMachine *me);
void me_op_fillVideoPage(Mirtille_VirtualMachine *me);
void me_op_copyVideoPage(Mirtille_VirtualMachine *me);
void me_op_blitFramebuffer(Mirtille_VirtualMachine *me);


enum ME_JMP_CONDITION { 
    ME_JZ=0, ME_JNZ=1, ME_JG=2, ME_JGE=3, ME_JL=4, ME_JLE=5
};


#endif