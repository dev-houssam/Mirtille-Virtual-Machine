#ifndef __ME_REGISTER_H__
#define __ME_REGISTER_H__

typedef enum {
	me_RAX=0,
	me_RBX,
	me_RCX,
	me_RDX,
	me_RSI,
	me_RDI,
	me_RSP,
	me_RBP,
	me_R8,
	me_R9,
	me_R10,
	me_R11,
	me_R12,
	me_R13,
	me_R14,
	me_R15,
	me_REGS_COUNT
} me_REGISTER;

uint64_t me_generalPurposeRegistersMemory[(
		 me_REGISTER) 
		 me_REGS_COUNT
];

uint64_t me_getValueFromRegister(me_REGISTER register);

uint64_t me_RIP;

uint64_t me_getRIP();

typedef enum {
	me_CS=0,
	me_DS,
	me_SS,
	me_ES,
	me_FS,
	me_GS=6,
	me_S_COUNT
} me_SegmentRegisters;

uint64_t me_segmentRegisterMemory[(
		 me_SegmentRegisters) 
		 me_S_COUNT
];



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


uint64_t me_me_RFLAGSRegisterMemory[(
		 me_RFLAGSRegister) 
		 me_RFLAGS_COUNT
];


typedef enum {
	me_CR_Protected_Mode_Enable=0,
	me_CR_Monitor_CoProcessor,
	me_CR_Emulation,
	me_CR_Task_Switched,
	me_CR_Extension_Type,
	me_CR_Numeric_Error,
	me_CR_Reserved6,
	me_CR_Reserved7,
	me_CR_Reserved8,
	me_CR_Reserved9,
	me_CR_Reserved10,
	me_CR_Reserved11,
	me_CR_Reserved12,
	me_CR_Reserved13,
	me_CR_Reserved14,
	me_CR_Reserved15,
	me_CR_Write_Protect=16,
	me_CR_Reserved17,
	me_CR_Alignment_Mask,
	me_CR_Reserved19_28=19,
	me_CR_Not_Write_Through=29,
	me_CR_Cache_Disable,
	me_CR_Paging=31,
	me_CR_Reserved_32,
	me_CR_Reserved_33,
	me_CR_Reserved_34,
	me_CR_Reserved_35,
	me_CR_Reserved_36,
	me_CR_Reserved_37,
	me_CR_Reserved_38,
	me_CR_Reserved_39,
	me_CR_Reserved_40,
	me_CR_Reserved_41,
	me_CR_Reserved_42,
	me_CR_Reserved_43,
	me_CR_Reserved_44,
	me_CR_Reserved_45,
	me_CR_Reserved_46,
	me_CR_Reserved_47,
	me_CR_Reserved_48,
	me_CR_Reserved_49,
	me_CR_Reserved_50,
	me_CR_Reserved_51,
	me_CR_Reserved_52,
	me_CR_Reserved_53,
	me_CR_Reserved_54,
	me_CR_Reserved_55,
	me_CR_Reserved_56,
	me_CR_Reserved_57,
	me_CR_Reserved_58,
	me_CR_Reserved_59,
	me_CR_Reserved_60,
	me_CR_Reserved_61,
	me_CR_Reserved_62,
	me_CR_Reserved_63=63
} me_ControlRegisters;

typedef enum {
	me_XMM0 = 0,
	me_XMM1,
	me_XMM2,
	me_XMM3,
	me_XMM4,
	me_XMM5,
	me_XMM6,
	me_XMM7,
	me_XMM8,
	me_XMM9,
	me_XMM10,
	me_XMM11,
	me_XMM12,
	me_XMM13,
	me_XMM14,
	me_XMM15=15,
	me_XMMX_COUNT
} me_128bitMediaRegisters;

uint64_t me_128bitMediaRegistersMemory[(
		 me_128bitMediaRegisters) 
		 me_XMMX_COUNT
];


typedef enum {
	me_MMX_FPR_0 = 0,
	me_MMX_FPR_1,
	me_MMX_FPR_2,
	me_MMX_FPR_3,
	me_MMX_FPR_4,
	me_MMX_FPR_5,
	me_MMX_FPR_6,
	me_MMX_FPR_7,
	me_XMMX_FPR__COUNT
} me_64bitMediaAndFloatingPointRegisters;

uint64_t me_64bitMediaAndFloatingPointRegistersMemory[(
		 me_64bitMediaAndFloatingPointRegisters) 
		 me_XMMX_COUNT
];


#endif