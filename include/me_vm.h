/*
	Author : Houssam BACAR
	Project Name : Mirtille Virtual Machine
	Description : headers for Mirtille Virtual Machine
	Date : 04/12/2025
*/

#ifndef __ME_MIRTILLE_VIRTUALMACHINE_H__
#define __ME_MIRTILLE_VIRTUALMACHINE_H__


typedef struct {
	typedef void (Mirtille_VirtualMachine *OpcodeStub)();
	static const OpcodeStub opcodeTable[];

	static const uint16_t frequenceTable[];

	Video *video;
	System *sys;

	int16_t vmVariables[VM_NUM_VARIABLES];

	Ptr _scriptPtr;
	uint8_t _stackPtr;

	void me_init(Mirtille_VirtualMachine *me, Video *vid, System *stub);
	void me_configuration_init(Mirtille_VirtualMachine * me);
	
	void op_mov();
	void op_add();
	void op_call();
	void op_ret();
	void op_jmp();
	void op_jnz();
	void op_selectVideoPage();
	void op_fillVideoPage();
	void op_copyVideoPage();
	void op_blitFramebuffer();	
	void op_drawString();
	void op_sub();
	void op_and();
	void op_or();
	void op_shl();
	void op_shr();
	void op_updateMemList();
	void inp_handleSpecialKeys();

} Mirtille_VirtualMachine;


enum ME_JMP_CONDITION { 
    ME_JZ=0, ME_JNZ=1, ME_JG=2, ME_JGE=3, ME_JL=4, ME_JLE=5
};


#endif

