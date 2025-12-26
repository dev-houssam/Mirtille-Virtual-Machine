#ifndef __ME_REGISTER_H__
#define __ME_REGISTER_H__

typedef enum {
	RAX=0,
	RBX,
	RCX,
	RDX,
	RSI,
	RDI,
	RSP,
	RBP,
	R8,
	R9,
	R10,
	R11,
	R12,
	R13,
	R14,
	R15,
	R_COUNT
} ME_REGISTER;

uint64_t me_RIP;

uint64_t me_getRIP();

typedef enum {
	CS=0,
	DS ,
	SS ,
	ES ,
	FS ,
	GS ,
	S_COUNT
} me_SegmentRegisters;

uint16_t segmentRegister[S_COUNT];



typedef enum{
	me_CarryFlag=0,
	me_Reserved1_1,
	me_ParityFlag,
	me_Reserved3_0,
	me_AuxiliaryCarryFlag,
	me_Reserved5_0,
	me_ZeroFlag,
	me_SignFlag,
	me_TrapFlag,
	me_InterruptEnableFlag,
	me_DirectionFlag,
	me_OverflowFlag,
	me_IO_PrivilegeLevel12=12,
	me_IO_PrivilegeLevel13=13,
	me_Nested_Task=14,
	me_Reserved,
	me_Resume_Flag,
	me_Virtual_8086_Mode,
	me_Alignment_Check_Access_Control,
	me_Virtual_Interrupt_Flag,
	me_Virtual_Interrupt_Pending,
	me_ID_Flag=21,
	me_Reserved_22=22,
	me_Reserved_23,
	me_Reserved_24,
	me_Reserved_25,
	me_Reserved_26,
	me_Reserved_27,
	me_Reserved_28,
	me_Reserved_29,
	me_Reserved_30,
	me_Reserved_31,
	me_Reserved_32,
	me_Reserved_33,
	me_Reserved_34,
	me_Reserved_35,
	me_Reserved_36,
	me_Reserved_37,
	me_Reserved_38,
	me_Reserved_39,
	me_Reserved_40,
	me_Reserved_41,
	me_Reserved_42,
	me_Reserved_43,
	me_Reserved_44,
	me_Reserved_45,
	me_Reserved_46,
	me_Reserved_47,
	me_Reserved_48,
	me_Reserved_49,
	me_Reserved_50,
	me_Reserved_51,
	me_Reserved_52,
	me_Reserved_53,
	me_Reserved_54,
	me_Reserved_55,
	me_Reserved_56,
	me_Reserved_57,
	me_Reserved_58,
	me_Reserved_59,
	me_Reserved_60,
	me_Reserved_61,
	me_Reserved_62,
	me_Reserved_63=63,
	me_RFLAGS_COUNT
} me_RFLAGSRegister;


uint16_t segmentRegister[me_RFLAGS_COUNT];


typedef enum {
	me_Protected_Mode_Enable=0,
	me_Monitor_CoProcessor,
	me_Emulation,
	me_Task_Switched,
	me_Extension_Type,
	me_Numeric_Error,
	me_Reserved6,
	me_Reserved7,
	me_Reserved8,
	me_Reserved9,
	me_Reserved10,
	me_Reserved11,
	me_Reserved12,
	me_Reserved13,
	me_Reserved14,
	me_Reserved15,
	me_Write_Protect=16,
	me_Reserved,
	me_Alignment_Mask,
	me_Reserved19_28=19,
	me_Not_Write_Through=29,
	me_Cache_Disable,
	me_Paging=31,
	me_Reserved_32,
	me_Reserved_33,
	me_Reserved_34,
	me_Reserved_35,
	me_Reserved_36,
	me_Reserved_37,
	me_Reserved_38,
	me_Reserved_39,
	me_Reserved_40,
	me_Reserved_41,
	me_Reserved_42,
	me_Reserved_43,
	me_Reserved_44,
	me_Reserved_45,
	me_Reserved_46,
	me_Reserved_47,
	me_Reserved_48,
	me_Reserved_49,
	me_Reserved_50,
	me_Reserved_51,
	me_Reserved_52,
	me_Reserved_53,
	me_Reserved_54,
	me_Reserved_55,
	me_Reserved_56,
	me_Reserved_57,
	me_Reserved_58,
	me_Reserved_59,
	me_Reserved_60,
	me_Reserved_61,
	me_Reserved_62,
	me_Reserved_63=63
} me_ControlRegisters;



#endif