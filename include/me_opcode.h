#ifndef __ME_OPCODE_H__
#define __ME_OPCODE_H__

typedef enum{
	AAA,
	ME_AAD,
	ME_AAM,
	ME_AAS,
	ME_ADC,
	ME_ADCX,
	ME_ADD,
	ME_ADDPD,
	ME_ADDPS,
	ME_ADDSD,
	ME_ADDSS,
	ME_ADDSUBPD,
	ME_ADDSUBPS,
	ME_ADOX,
	ME_AESDEC,
	ME_AESDEC128KL,
	ME_AESDEC256KL,
	ME_AESDECLAST,
	ME_AESDECWIDE128KL,
	ME_AESDECWIDE256KL,
	ME_AESENC,
	ME_AESENC128KL,
	ME_AESENC256KL,
	ME_AESENCLAST,
	ME_AESENCWIDE128KL,
	ME_AESENCWIDE256KL,
	ME_AESIMC,
	ME_AESKEYGENASSIST,
	ME_AND,
	ME_ANDN,
	ME_ANDNPD,
	ME_ANDNPS,
	ME_ANDPD,
	ME_ANDPS,
	ME_ARPL,
	ME_BEXTR,
	ME_BLENDPD,
	ME_BLENDPS,
	ME_BLENDVPD,
	ME_BLENDVPS,
	ME_BLSI,
	ME_BLSMSK,
	ME_BLSR,
	ME_BNDCL,
	ME_BNDCN,
	ME_BNDCU,
	ME_BNDLDX,
	ME_BNDMK,
	ME_BNDMOV,
	ME_BNDSTX,
	ME_BOUND,
	ME_BSF,
	ME_BSR,
	ME_BSWAP,
	ME_BT,
	ME_BTC,
	ME_BTR,
	ME_BTS,
	ME_BZHI,
	ME_CALL,
	ME_CBW,
	ME_CDQ,
	ME_CDQE,
	ME_CLAC,
	ME_CLC,
	ME_CLD,
	ME_CLDEMOTE,
	ME_CLFLUSH,
	ME_CLFLUSHOPT,
	ME_CLI,
	ME_CLRSSBSY,
	ME_CLTS,
	ME_CLUI,
	ME_CLWB,
	ME_CMC,
	ME_CMOVcc,
	ME_CMP,
	ME_CMPPD,
	ME_CMPPS,
	ME_CMPS,
	ME_CMPSB,
	ME_CMPSD,
	ME_CMPSD,
	ME_CMPSQ,
	ME_CMPSS,
	ME_CMPSW,
	ME_CMPXCHG,
	ME_CMPXCHG16B,
	ME_CMPXCHG8B,
	ME_COMISD,
	ME_COMISS,
	ME_CPUID,
	ME_CQO,
	ME_CRC32,
	ME_CVTDQ2PD,
	ME_CVTDQ2PS,
	ME_CVTPD2DQ,
	ME_CVTPD2PI,
	ME_CVTPD2PS,
	ME_CVTPI2PD,
	ME_CVTPI2PS,
	ME_CVTPS2DQ,
	ME_CVTPS2PD,
	ME_CVTPS2PI,
	ME_CVTSD2SI,
	ME_CVTSD2SS,
	ME_CVTSI2SD,
	ME_CVTSI2SS,
	ME_CVTSS2SD,
	ME_CVTSS2SI,
	ME_CVTTPD2DQ,
	ME_CVTTPD2PI,
	ME_CVTTPS2DQ,
	ME_CVTTPS2PI,
	ME_CVTTSD2SI,
	ME_CVTTSS2SI,
	ME_CWD,
	ME_CWDE,
	ME_DAA,
	ME_DAS,
	ME_DEC,
	ME_DIV,
	ME_DIVPD,
	ME_DIVPS,
	ME_DIVSD,
	ME_DIVSS,
	ME_DPPD,
	ME_DPPS,
	ME_EMMS,
	ME_ENCODEKEY128,
	ME_ENCODEKEY256,
	ME_ENDBR32,
	ME_ENDBR64,
	ME_ENQCMD,
	ME_ENQCMDS,
	ME_ENTER,
	ME_EXTRACTPS,
	ME_F2XM1,
	ME_FABS,
	ME_FADD,
	ME_FADDP,
	ME_FBLD,
	ME_FBSTP,
	ME_FCHS,
	ME_FCLEX,
	ME_FCMOVcc,
	ME_FCOM,
	ME_FCOMI,
	ME_FCOMIP,
	ME_FCOMP,
	ME_FCOMPP,
	ME_FCOS,
	ME_FDECSTP,
	ME_FDIV,
	ME_FDIVP,
	ME_FDIVR,
	ME_FDIVRP,
	ME_FFREE,
	ME_FIADD,
	ME_FICOM,
	ME_FICOMP,
	ME_FIDIV,
	ME_FIDIVR,
	ME_FILD,
	ME_FIMUL,
	ME_FINCSTP,
	ME_FINIT,
	ME_FIST,
	ME_FISTP,
	ME_FISTTP,
	ME_FISUB,
	ME_FISUBR,
	ME_FLD,
	ME_FLD1,
	ME_FLDCW,
	ME_FLDENV,
	ME_FLDL2E,
	ME_FLDL2T,
	ME_FLDLG2,
	ME_FLDLN2,
	ME_FLDPI,
	ME_FLDZ,
	ME_FMUL,
	ME_FMULP,
	ME_FNCLEX,
	ME_FNINIT,
	ME_FNOP,
	ME_FNSAVE,
	ME_FNSTCW,
	ME_FNSTENV,
	ME_FNSTSW,
	ME_FPATAN,
	ME_FPREM,
	ME_FPREM1,
	ME_FPTAN,
	ME_FRNDINT,
	ME_FRSTOR,
	ME_FSAVE,
	ME_FSCALE,
	ME_FSIN,
	ME_FSINCOS,
	ME_FSQRT,
	ME_FST,
	ME_FSTCW,
	ME_FSTENV,
	ME_FSTP,
	ME_FSTSW,
	ME_FSUB,
	ME_FSUBP,
	ME_FSUBR,
	ME_FSUBRP,
	ME_FTST,
	ME_FUCOM,
	ME_FUCOMI,
	ME_FUCOMIP,
	ME_FUCOMP,
	ME_FUCOMPP,
	ME_FWAIT,
	ME_FXAM,
	ME_FXCH,
	ME_FXRSTOR,
	ME_FXSAVE,
	ME_FXTRACT,
	ME_FYL2X,
	ME_FYL2XP1,
	ME_GF2P8AFFINEINVQB,
	ME_GF2P8AFFINEQB,
	ME_GF2P8MULB,
	ME_HADDPD,
	ME_HADDPS,
	ME_HLT,
	ME_HRESET,
	ME_HSUBPD,
	ME_HSUBPS,
	ME_IDIV,
	ME_IMUL,
	ME_IN,
	ME_INC,
	ME_INCSSPD,
	ME_INCSSPQ,
	ME_INS,
	ME_INSB,
	ME_INSD,
	ME_INSERTPS,
	ME_INSW,
	ME_INT,
	ME_INT1,
	ME_INT3,
	ME_INTO,
	ME_INVD,
	ME_INVLPG,
	ME_INVPCID,
	ME_IRET,
	ME_IRETD,
	ME_IRETQ,
	ME_JMP,
	ME_Jcc,
	ME_KADDB,
	ME_KADDD,
	ME_KADDQ,
	ME_KADDW,
	ME_KANDB,
	ME_KANDD,
	ME_KANDNB,
	ME_KANDND,
	ME_KANDNQ,
	ME_KANDNW,
	ME_KANDQ,
	ME_KANDW,
	ME_KMOVB,
	ME_KMOVD,
	ME_KMOVQ,
	ME_KMOVW,
	ME_KNOTB,
	ME_KNOTD,
	ME_KNOTQ,
	ME_KNOTW,
	ME_KORB,
	ME_KORD,
	ME_KORQ,
	ME_KORTESTB,
	ME_KORTESTD,
	ME_KORTESTQ,
	ME_KORTESTW,
	ME_KORW,
	ME_KSHIFTLB,
	ME_KSHIFTLD,
	ME_KSHIFTLQ,
	ME_KSHIFTLW,
	ME_KSHIFTRB,
	ME_KSHIFTRD,
	ME_KSHIFTRQ,
	ME_KSHIFTRW,
	ME_KTESTB,
	ME_KTESTD,
	ME_KTESTQ,
	ME_KTESTW,
	ME_KUNPCKBW,
	ME_KUNPCKDQ,
	ME_KUNPCKWD,
	ME_KXNORB,
	ME_KXNORD,
	ME_KXNORQ,
	ME_KXNORW,
	ME_KXORB,
	ME_KXORD,
	ME_KXORQ,
	ME_KXORW,
	ME_LAHF,
	ME_LAR,
	ME_LDDQU,
	ME_LDMXCSR,
	ME_LDS,
	ME_LDTILECFG,
	ME_LEA,
	ME_LEAVE,
	ME_LES,
	ME_LFENCE,
	ME_LFS,
	ME_LGDT,
	ME_LGS,
	ME_LIDT,
	ME_LLDT,
	ME_LMSW,
	ME_LOADIWKEY,
	ME_LOCK,
	ME_LODS,
	ME_LODSB,
	ME_LODSD,
	ME_LODSQ,
	ME_LODSW,
	ME_LOOP,
	ME_LOOPcc,
	ME_LSL,
	ME_LSS,
	ME_LTR,
	ME_LZCNT,
	ME_MASKMOVDQU,
	ME_MASKMOVQ,
	ME_MAXPD,
	ME_MAXPS,
	ME_MAXSD,
	ME_MAXSS,
	ME_MFENCE,
	ME_MINPD,
	ME_MINPS,
	ME_MINSD,
	ME_MINSS,
	ME_MONITOR,
	ME_MOV,
	ME_MOV,
	ME_MOV,
	ME_MOVAPD,
	ME_MOVAPS,
	ME_MOVBE,
	ME_MOVD,
	ME_MOVDDUP,
	ME_MOVDIR64B,
	ME_MOVDIRI,
	ME_MOVDQ2Q,
	ME_MOVDQA,
	ME_MOVDQU,
	ME_MOVHLPS,
	ME_MOVHPD,
	ME_MOVHPS,
	ME_MOVLHPS,
	ME_MOVLPD,
	ME_MOVLPS,
	ME_MOVMSKPD,
	ME_MOVMSKPS,
	ME_MOVNTDQ,
	ME_MOVNTDQA,
	ME_MOVNTI,
	ME_MOVNTPD,
	ME_MOVNTPS,
	ME_MOVNTQ,
	ME_MOVQ,
	ME_MOVQ,
	ME_MOVQ2DQ,
	ME_MOVS,
	ME_MOVSB,
	ME_MOVSD,
	ME_MOVSD,
	ME_MOVSHDUP,
	ME_MOVSLDUP,
	ME_MOVSQ,
	ME_MOVSS,
	ME_MOVSW,
	ME_MOVSX,
	ME_MOVSXD,
	ME_MOVUPD,
	ME_MOVUPS,
	ME_MOVZX,
	ME_MPSADBW,
	ME_MUL,
	ME_MULPD,
	ME_MULPS,
	ME_MULSD,
	ME_MULSS,
	ME_MULX,
	ME_MWAIT,
	ME_NEG,
	ME_NOP,
	ME_NOT,
	ME_OR,
	ME_ORPD,
	ME_ORPS,
	ME_OUT,
	ME_OUTS,
	ME_OUTSB,
	ME_OUTSD,
	ME_OUTSW,
	ME_PABSB,
	ME_PABSD,
	ME_PABSQ,
	ME_PABSW,
	ME_PACKSSDW,
	ME_PACKSSWB,
	ME_PACKUSDW,
	ME_PACKUSWB,
	ME_PADDB,
	ME_PADDD,
	ME_PADDQ,
	ME_PADDSB,
	ME_PADDSW,
	ME_PADDUSB,
	ME_PADDUSW,
	ME_PADDW,
	ME_PALIGNR,
	ME_PAND,
	ME_PANDN,
	ME_PAUSE,
	ME_PAVGB,
	ME_PAVGW,
	ME_PBLENDVB,
	ME_PBLENDW,
	ME_PCLMULQDQ,
	ME_PCMPEQB,
	ME_PCMPEQD,
	ME_PCMPEQQ,
	ME_PCMPEQW,
	ME_PCMPESTRI,
	ME_PCMPESTRM,
	ME_PCMPGTB,
	ME_PCMPGTD,
	ME_PCMPGTQ,
	ME_PCMPGTW,
	ME_PCMPISTRI,
	ME_PCMPISTRM,
	ME_PCONFIG,
	ME_PDEP,
	ME_PEXT,
	ME_PEXTRB,
	ME_PEXTRD,
	ME_PEXTRQ,
	ME_PEXTRW,
	ME_PHADDD,
	ME_PHADDSW,
	ME_PHADDW,
	ME_PHMINPOSUW,
	ME_PHSUBD,
	ME_PHSUBSW,
	ME_PHSUBW,
	ME_PINSRB,
	ME_PINSRD,
	ME_PINSRQ,
	ME_PINSRW,
	ME_PMADDUBSW,
	ME_PMADDWD,
	ME_PMAXSB,
	ME_PMAXSD,
	ME_PMAXSQ,
	ME_PMAXSW,
	ME_PMAXUB,
	ME_PMAXUD,
	ME_PMAXUQ,
	ME_PMAXUW,
	ME_PMINSB,
	ME_PMINSD,
	ME_PMINSQ,
	ME_PMINSW,
	ME_PMINUB,
	ME_PMINUD,
	ME_PMINUQ,
	ME_PMINUW,
	ME_PMOVMSKB,
	ME_PMOVSX,
	ME_PMOVZX,
	ME_PMULDQ,
	ME_PMULHRSW,
	ME_PMULHUW,
	ME_PMULHW,
	ME_PMULLD,
	ME_PMULLQ,
	ME_PMULLW,
	ME_PMULUDQ,
	ME_POP,
	ME_POPA,
	ME_POPAD,
	ME_POPCNT,
	ME_POPF,
	ME_POPFD,
	ME_POPFQ,
	ME_POR,
	ME_PREFETCHW,
	ME_PREFETCHh,
	ME_PSADBW,
	ME_PSHUFB,
	ME_PSHUFD,
	ME_PSHUFHW,
	ME_PSHUFLW,
	ME_PSHUFW,
	ME_PSIGNB,
	ME_PSIGND,
	ME_PSIGNW,
	ME_PSLLD,
	ME_PSLLDQ,
	ME_PSLLQ,
	ME_PSLLW,
	ME_PSRAD,
	ME_PSRAQ,
	ME_PSRAW,
	ME_PSRLD,
	ME_PSRLDQ,
	ME_PSRLQ,
	ME_PSRLW,
	ME_PSUBB,
	ME_PSUBD,
	ME_PSUBQ,
	ME_PSUBSB,
	ME_PSUBSW,
	ME_PSUBUSB,
	ME_PSUBUSW,
	ME_PSUBW,
	ME_PTEST,
	ME_PTWRITE,
	ME_PUNPCKHBW,
	ME_PUNPCKHDQ,
	ME_PUNPCKHQDQ,
	ME_PUNPCKHWD,
	ME_PUNPCKLBW,
	ME_PUNPCKLDQ,
	ME_PUNPCKLQDQ,
	ME_PUNPCKLWD,
	ME_PUSH,
	ME_PUSHA,
	ME_PUSHAD,
	ME_PUSHF,
	ME_PUSHFD,
	ME_PUSHFQ,
	ME_PXOR,
	ME_RCL,
	ME_RCPPS,
	ME_RCPSS,
	ME_RCR,
	ME_RDFSBASE,
	ME_RDGSBASE,
	ME_RDMSR,
	ME_RDPID,
	ME_RDPKRU,
	ME_RDPMC,
	ME_RDRAND,
	ME_RDSEED,
	ME_RDSSPD,
	ME_RDSSPQ,
	ME_RDTSC,
	ME_RDTSCP,
	ME_REP,
	ME_REPE,
	ME_REPNE,
	ME_REPNZ,
	ME_REPZ,
	ME_RET,
	ME_ROL,
	ME_ROR,
	ME_RORX,
	ME_ROUNDPD,
	ME_ROUNDPS,
	ME_ROUNDSD,
	ME_ROUNDSS,
	ME_RSM,
	ME_RSQRTPS,
	ME_RSQRTSS,
	ME_RSTORSSP,
	ME_SAHF,
	ME_SAL,
	ME_SAR,
	ME_SARX,
	ME_SAVEPREVSSP,
	ME_SBB,
	ME_SCAS,
	ME_SCASB,
	ME_SCASD,
	ME_SCASW,
	ME_SENDUIPI,
	ME_SERIALIZE,
	ME_SETSSBSY,
	ME_SETcc,
	ME_SFENCE,
	ME_SGDT,
	ME_SHA1MSG1,
	ME_SHA1MSG2,
	ME_SHA1NEXTE,
	ME_SHA1RNDS4,
	ME_SHA256MSG1,
	ME_SHA256MSG2,
	ME_SHA256RNDS2,
	ME_SHL,
	ME_SHLD,
	ME_SHLX,
	ME_SHR,
	ME_SHRD,
	ME_SHRX,
	ME_SHUFPD,
	ME_SHUFPS,
	ME_SIDT,
	ME_SLDT,
	ME_SMSW,
	ME_SQRTPD,
	ME_SQRTPS,
	ME_SQRTSD,
	ME_SQRTSS,
	ME_STAC,
	ME_STC,
	ME_STD,
	ME_STI,
	ME_STMXCSR,
	ME_STOS,
	ME_STOSB,
	ME_STOSD,
	ME_STOSQ,
	ME_STOSW,
	ME_STR,
	ME_STTILECFG,
	ME_STUI,
	ME_SUB,
	ME_SUBPD,
	ME_SUBPS,
	ME_SUBSD,
	ME_SUBSS,
	ME_SWAPGS,
	ME_SYSCALL,
	ME_SYSENTER,
	ME_SYSEXIT,
	ME_SYSRET,
	ME_TDPBF16PS,
	ME_TDPBSSD,
	ME_TDPBSUD,
	ME_TDPBUSD,
	ME_TDPBUUD,
	ME_TEST,
	ME_TESTUI,
	ME_TILELOADD,
	ME_TILELOADDT1,
	ME_TILERELEASE,
	ME_TILESTORED,
	ME_TILEZERO,
	ME_TPAUSE,
	ME_TZCNT,
	ME_UCOMISD,
	ME_UCOMISS,
	ME_UD,
	ME_UIRET,
	ME_UMONITOR,
	ME_UMWAIT,
	ME_UNPCKHPD,
	ME_UNPCKHPS,
	ME_UNPCKLPD,
	ME_UNPCKLPS,
	ME_VADDPH,
	ME_VADDSH,
	ME_VALIGND,
	ME_VALIGNQ,
	ME_VBLENDMPD,
	ME_VBLENDMPS,
	ME_VBROADCAST,
	ME_VCMPPH,
	ME_VCMPSH,
	ME_VCOMISH,
	ME_VCOMPRESSPD,
	ME_VCOMPRESSPS,
	ME_VCOMPRESSW,
	ME_VCVTDQ2PH,
	ME_VCVTNE2PS2BF16,
	ME_VCVTNEPS2BF16,
	ME_VCVTPD2PH,
	ME_VCVTPD2QQ,
	ME_VCVTPD2UDQ,
	ME_VCVTPD2UQQ,
	ME_VCVTPH2DQ,
	ME_VCVTPH2PD,
	ME_VCVTPH2PS,
	ME_VCVTPH2PSX,
	ME_VCVTPH2QQ,
	ME_VCVTPH2UDQ,
	ME_VCVTPH2UQQ,
	ME_VCVTPH2UW,
	ME_VCVTPH2W,
	ME_VCVTPS2PH,
	ME_VCVTPS2PHX,
	ME_VCVTPS2QQ,
	ME_VCVTPS2UDQ,
	ME_VCVTPS2UQQ,
	ME_VCVTQQ2PD,
	ME_VCVTQQ2PH,
	ME_VCVTQQ2PS,
	ME_VCVTSD2SH,
	ME_VCVTSD2USI,
	ME_VCVTSH2SD,
	ME_VCVTSH2SI,
	ME_VCVTSH2SS,
	ME_VCVTSH2USI,
	ME_VCVTSI2SH,
	ME_VCVTSS2SH,
	ME_VCVTSS2USI,
	ME_VCVTTPD2QQ,
	ME_VCVTTPD2UDQ,
	ME_VCVTTPD2UQQ,
	ME_VCVTTPH2DQ,
	ME_VCVTTPH2QQ,
	ME_VCVTTPH2UDQ,
	ME_VCVTTPH2UQQ,
	ME_VCVTTPH2UW,
	ME_VCVTTPH2W,
	ME_VCVTTPS2QQ,
	ME_VCVTTPS2UDQ,
	ME_VCVTTPS2UQQ,
	ME_VCVTTSD2USI,
	ME_VCVTTSH2SI,
	ME_VCVTTSH2USI,
	ME_VCVTTSS2USI,
	ME_VCVTUDQ2PD,
	ME_VCVTUDQ2PH,
	ME_VCVTUDQ2PS,
	ME_VCVTUQQ2PD,
	ME_VCVTUQQ2PH,
	ME_VCVTUQQ2PS,
	ME_VCVTUSI2SD,
	ME_VCVTUSI2SH,
	ME_VCVTUSI2SS,
	ME_VCVTUW2PH,
	ME_VCVTW2PH,
	ME_VDBPSADBW,
	ME_VDIVPH,
	ME_VDIVSH,
	ME_VDPBF16PS,
	ME_VERR,
	ME_VERW,
	ME_VEXPANDPD,
	ME_VEXPANDPS,
	ME_VEXTRACTF128,
	ME_VEXTRACTF32x4,
	ME_VEXTRACTF32x8,
	ME_VEXTRACTF64x2,
	ME_VEXTRACTF64x4,
	ME_VEXTRACTI128,
	ME_VEXTRACTI32x4,
	ME_VEXTRACTI32x8,
	ME_VEXTRACTI64x2,
	ME_VEXTRACTI64x4,
	ME_VFCMADDCPH,
	ME_VFCMADDCSH,
	ME_VFCMULCPH,
	ME_VFCMULCSH,
	ME_VFIXUPIMMPD,
	ME_VFIXUPIMMPS,
	ME_VFIXUPIMMSD,
	ME_VFIXUPIMMSS,
	ME_VFMADD132PD,
	ME_VFMADD132PH,
	ME_VFMADD132PS,
	ME_VFMADD132SD,
	ME_VFMADD132SH,
	ME_VFMADD132SS,
	ME_VFMADD213PD,
	ME_VFMADD213PH,
	ME_VFMADD213PS,
	ME_VFMADD213SD,
	ME_VFMADD213SH,
	ME_VFMADD213SS,
	ME_VFMADD231PD,
	ME_VFMADD231PH,
	ME_VFMADD231PS,
	ME_VFMADD231SD,
	ME_VFMADD231SH,
	ME_VFMADD231SS,
	ME_VFMADDCPH,
	ME_VFMADDCSH,
	ME_VFMADDRND231PD,
	ME_VFMADDSUB132PD,
	ME_VFMADDSUB132PH,
	ME_VFMADDSUB132PS,
	ME_VFMADDSUB213PD,
	ME_VFMADDSUB213PH,
	ME_VFMADDSUB213PS,
	ME_VFMADDSUB231PD,
	ME_VFMADDSUB231PH,
	ME_VFMADDSUB231PS,
	ME_VFMSUB132PD,
	ME_VFMSUB132PH,
	ME_VFMSUB132PS,
	ME_VFMSUB132SD,
	ME_VFMSUB132SH,
	ME_VFMSUB132SS,
	ME_VFMSUB213PD,
	ME_VFMSUB213PH,
	ME_VFMSUB213PS,
	ME_VFMSUB213SD,
	ME_VFMSUB213SH,
	ME_VFMSUB213SS,
	ME_VFMSUB231PD,
	ME_VFMSUB231PH,
	ME_VFMSUB231PS,
	ME_VFMSUB231SD,
	ME_VFMSUB231SH,
	ME_VFMSUB231SS,
	ME_VFMSUBADD132PD,
	ME_VFMSUBADD132PH,
	ME_VFMSUBADD132PS,
	ME_VFMSUBADD213PD,
	ME_VFMSUBADD213PH,
	ME_VFMSUBADD213PS,
	ME_VFMSUBADD231PD,
	ME_VFMSUBADD231PH,
	ME_VFMSUBADD231PS,
	ME_VFMULCPH,
	ME_VFMULCSH,
	ME_VFNMADD132PD,
	ME_VFNMADD132PH,
	ME_VFNMADD132PS,
	ME_VFNMADD132SD,
	ME_VFNMADD132SH,
	ME_VFNMADD132SS,
	ME_VFNMADD213PD,
	ME_VFNMADD213PH,
	ME_VFNMADD213PS,
	ME_VFNMADD213SD,
	ME_VFNMADD213SH,
	ME_VFNMADD213SS,
	ME_VFNMADD231PD,
	ME_VFNMADD231PH,
	ME_VFNMADD231PS,
	ME_VFNMADD231SD,
	ME_VFNMADD231SH,
	ME_VFNMADD231SS,
	ME_VFNMSUB132PD,
	ME_VFNMSUB132PH,
	ME_VFNMSUB132PS,
	ME_VFNMSUB132SD,
	ME_VFNMSUB132SH,
	ME_VFNMSUB132SS,
	ME_VFNMSUB213PD,
	ME_VFNMSUB213PH,
	ME_VFNMSUB213PS,
	ME_VFNMSUB213SD,
	ME_VFNMSUB213SH,
	ME_VFNMSUB213SS,
	ME_VFNMSUB231PD,
	ME_VFNMSUB231PH,
	ME_VFNMSUB231PS,
	ME_VFNMSUB231SD,
	ME_VFNMSUB231SH,
	ME_VFNMSUB231SS,
	ME_VFPCLASSPD,
	ME_VFPCLASSPH,
	ME_VFPCLASSPS,
	ME_VFPCLASSSD,
	ME_VFPCLASSSH,
	ME_VFPCLASSSS,
	ME_VGATHERDPD,
	ME_VGATHERDPD,
	ME_VGATHERDPS,
	ME_VGATHERDPS,
	ME_VGATHERQPD,
	ME_VGATHERQPD,
	ME_VGATHERQPS,
	ME_VGATHERQPS,
	ME_VGETEXPPD,
	ME_VGETEXPPH,
	ME_VGETEXPPS,
	ME_VGETEXPSD,
	ME_VGETEXPSH,
	ME_VGETEXPSS,
	ME_VGETMANTPD,
	ME_VGETMANTPH,
	ME_VGETMANTPS,
	ME_VGETMANTSD,
	ME_VGETMANTSH,
	ME_VGETMANTSS,
	ME_VINSERTF128,
	ME_VINSERTF32x4,
	ME_VINSERTF32x8,
	ME_VINSERTF64x2,
	ME_VINSERTF64x4,
	ME_VINSERTI128,
	ME_VINSERTI32x4,
	ME_VINSERTI32x8,
	ME_VINSERTI64x2,
	ME_VINSERTI64x4,
	ME_VMASKMOV,
	ME_VMAXPH,
	ME_VMAXSH,
	ME_VMINPH,
	ME_VMINSH,
	ME_VMOVDQA32,
	ME_VMOVDQA64,
	ME_VMOVDQU16,
	ME_VMOVDQU32,
	ME_VMOVDQU64,
	ME_VMOVDQU8,
	ME_VMOVSH,
	ME_VMOVW,
	ME_VMULPH,
	ME_VMULSH,
	ME_VP2INTERSECTD,
	ME_VP2INTERSECTQ,
	ME_VPBLENDD,
	ME_VPBLENDMB,
	ME_VPBLENDMD,
	ME_VPBLENDMQ,
	ME_VPBLENDMW,
	ME_VPBROADCAST,
	ME_VPBROADCASTB,
	ME_VPBROADCASTD,
	ME_VPBROADCASTM,
	ME_VPBROADCASTQ,
	ME_VPBROADCASTW,
	ME_VPCMPB,
	ME_VPCMPD,
	ME_VPCMPQ,
	ME_VPCMPUB,
	ME_VPCMPUD,
	ME_VPCMPUQ,
	ME_VPCMPUW,
	ME_VPCMPW,
	ME_VPCOMPRESSB,
	ME_VPCOMPRESSD,
	ME_VPCOMPRESSQ,
	ME_VPCONFLICTD,
	ME_VPCONFLICTQ,
	ME_VPDPBUSD,
	ME_VPDPBUSDS,
	ME_VPDPWSSD,
	ME_VPDPWSSDS,
	ME_VPERM2F128,
	ME_VPERM2I128,
	ME_VPERMB,
	ME_VPERMD,
	ME_VPERMI2B,
	ME_VPERMI2D,
	ME_VPERMI2PD,
	ME_VPERMI2PS,
	ME_VPERMI2Q,
	ME_VPERMI2W,
	ME_VPERMILPD,
	ME_VPERMILPS,
	ME_VPERMPD,
	ME_VPERMPS,
	ME_VPERMQ,
	ME_VPERMT2B,
	ME_VPERMT2D,
	ME_VPERMT2PD,
	ME_VPERMT2PS,
	ME_VPERMT2Q,
	ME_VPERMT2W,
	ME_VPERMW,
	ME_VPEXPANDB,
	ME_VPEXPANDD,
	ME_VPEXPANDQ,
	ME_VPEXPANDW,
	ME_VPGATHERDD,
	ME_VPGATHERDD,
	ME_VPGATHERDQ,
	ME_VPGATHERDQ,
	ME_VPGATHERQD,
	ME_VPGATHERQD,
	ME_VPGATHERQQ,
	ME_VPGATHERQQ,
	ME_VPLZCNTD,
	ME_VPLZCNTQ,
	ME_VPMADD52HUQ,
	ME_VPMADD52LUQ,
	ME_VPMASKMOV,
	ME_VPMOVB2M,
	ME_VPMOVD2M,
	ME_VPMOVDB,
	ME_VPMOVDW,
	ME_VPMOVM2B,
	ME_VPMOVM2D,
	ME_VPMOVM2Q,
	ME_VPMOVM2W,
	ME_VPMOVQ2M,
	ME_VPMOVQB,
	ME_VPMOVQD,
	ME_VPMOVQW,
	ME_VPMOVSDB,
	ME_VPMOVSDW,
	ME_VPMOVSQB,
	ME_VPMOVSQD,
	ME_VPMOVSQW,
	ME_VPMOVSWB,
	ME_VPMOVUSDB,
	ME_VPMOVUSDW,
	ME_VPMOVUSQB,
	ME_VPMOVUSQD,
	ME_VPMOVUSQW,
	ME_VPMOVUSWB,
	ME_VPMOVW2M,
	ME_VPMOVWB,
	ME_VPMULTISHIFTQB,
	ME_VPOPCNT,
	ME_VPROLD,
	ME_VPROLQ,
	ME_VPROLVD,
	ME_VPROLVQ,
	ME_VPRORD,
	ME_VPRORQ,
	ME_VPRORVD,
	ME_VPRORVQ,
	ME_VPSCATTERDD,
	ME_VPSCATTERDQ,
	ME_VPSCATTERQD,
	ME_VPSCATTERQQ,
	ME_VPSHLD,
	ME_VPSHLDV,
	ME_VPSHRD,
	ME_VPSHRDV,
	ME_VPSHUFBITQMB,
	ME_VPSLLVD,
	ME_VPSLLVQ,
	ME_VPSLLVW,
	ME_VPSRAVD,
	ME_VPSRAVQ,
	ME_VPSRAVW,
	ME_VPSRLVD,
	ME_VPSRLVQ,
	ME_VPSRLVW,
	ME_VPTERNLOGD,
	ME_VPTERNLOGQ,
	ME_VPTESTMB,
	ME_VPTESTMD,
	ME_VPTESTMQ,
	ME_VPTESTMW,
	ME_VPTESTNMB,
	ME_VPTESTNMD,
	ME_VPTESTNMQ,
	ME_VPTESTNMW,
	ME_VRANGEPD,
	ME_VRANGEPS,
	ME_VRANGESD,
	ME_VRANGESS,
	ME_VRCP14PD,
	ME_VRCP14PS,
	ME_VRCP14SD,
	ME_VRCP14SS,
	ME_VRCPPH,
	ME_VRCPSH,
	ME_VREDUCEPD,
	ME_VREDUCEPH,
	ME_VREDUCEPS,
	ME_VREDUCESD,
	ME_VREDUCESH,
	ME_VREDUCESS,
	ME_VRNDSCALEPD,
	ME_VRNDSCALEPH,
	ME_VRNDSCALEPS,
	ME_VRNDSCALESD,
	ME_VRNDSCALESH,
	ME_VRNDSCALESS,
	ME_VRSQRT14PD,
	ME_VRSQRT14PS,
	ME_VRSQRT14SD,
	ME_VRSQRT14SS,
	ME_VRSQRTPH,
	ME_VRSQRTSH,
	ME_VSCALEFPD,
	ME_VSCALEFPH,
	ME_VSCALEFPS,
	ME_VSCALEFSD,
	ME_VSCALEFSH,
	ME_VSCALEFSS,
	ME_VSCATTERDPD,
	ME_VSCATTERDPS,
	ME_VSCATTERQPD,
	ME_VSCATTERQPS,
	ME_VSHUFF32x4,
	ME_VSHUFF64x2,
	ME_VSHUFI32x4,
	ME_VSHUFI64x2,
	ME_VSQRTPH,
	ME_VSQRTSH,
	ME_VSUBPH,
	ME_VSUBSH,
	ME_VTESTPD,
	ME_VTESTPS,
	ME_VUCOMISH,
	ME_VZEROALL,
	ME_VZEROUPPER,
	ME_WAIT,
	ME_WBINVD,
	ME_WBNOINVD,
	ME_WRFSBASE,
	ME_WRGSBASE,
	ME_WRMSR,
	ME_WRPKRU,
	ME_WRSSD,
	ME_WRSSQ,
	ME_WRUSSD,
	ME_WRUSSQ,
	ME_XABORT,
	ME_XACQUIRE,
	ME_XADD,
	ME_XBEGIN,
	ME_XCHG,
	ME_XEND,
	ME_XGETBV,
	ME_XLAT,
	ME_XLATB,
	ME_XOR,
	ME_XORPD,
	ME_XORPS,
	ME_XRELEASE,
	ME_XRESLDTRK,
	ME_XRSTOR,
	ME_XRSTORS,
	ME_XSAVE,
	ME_XSAVEC,
	ME_XSAVEOPT,
	ME_XSAVES,
	ME_XSETBV,
	ME_XSUSLDTRK,
	ME_XTEST,
	ME_SGX,

	ME_ENCLS,
	ME_ENCLS_EADD_,
	ME_ENCLS_EAUG_,
	ME_ENCLS_EBLOCK_,
	ME_ENCLS_ECREATE_,
	ME_ENCLS_EDBGRD_,
	ME_ENCLS_EDBGWR_,
	ME_ENCLS_EEXTEND_,
	ME_ENCLS_EINIT_,
	ME_ENCLS_ELDBC_,
	ME_ENCLS_ELDB_,
	ME_ENCLS_ELDUC_,
	ME_ENCLS_ELDU_,
	ME_ENCLS_EMODPR_,
	ME_ENCLS_EMODT_,
	ME_ENCLS_EPA_,
	ME_ENCLS_ERDINFO_,
	ME_ENCLS_EREMOVE_,
	ME_ENCLS_ETRACKC_,
	ME_ENCLS_ETRACK_,
	ME_ENCLS_EWB_,
	ME_ENCLU,
	ME_ENCLU_EACCEPTCOPY_,
	ME_ENCLU_EACCEPT_,
	ME_ENCLU_EDECCSSA_,
	ME_ENCLU_EENTER_,
	ME_ENCLU_EEXIT_,
	ME_ENCLU_EGETKEY_,
	ME_ENCLU_EMODPE_,
	ME_ENCLU_EREPORT_,
	ME_ENCLU_ERESUME_,
	ME_ENCLV,
	ME_ENCLV_EDECVIRTCHILD_,
	ME_ENCLV_EINCVIRTCHILD_,
	ME_ENCLV_ESETCONTEXT_,
	ME_SMX,

	ME_GETSEC_CAPABILITIES_,
	ME_GETSEC_ENTERACCS_,
	ME_GETSEC_EXITAC_,
	ME_GETSEC_PARAMETERS_,
	ME_GETSEC_SENTER_,
	ME_GETSEC_SEXIT_,
	ME_GETSEC_SMCTRL_,
	ME_GETSEC_WAKEUP_,
	ME_VMX,

	ME_INVEPT,
	ME_INVVPID,
	ME_VMCALL,
	ME_VMCLEAR,
	ME_VMFUNC,
	ME_VMLAUNCH,
	ME_VMPTRLD,
	ME_VMPTRST,
	ME_VMREAD,
	ME_VMRESUME,
	ME_VMRESUME,
	ME_VMWRITE,
	ME_VMXOFF,
	ME_VMXON,

	ME_PREFETCHWT1,
	ME_V4FMADDPS,
	ME_V4FMADDSS,
	ME_V4FNMADDPS,
	ME_V4FNMADDSS,
	ME_VEXP2PD,
	ME_VEXP2PS,
	ME_VGATHERPF0DPD,
	ME_VGATHERPF0DPS,
	ME_VGATHERPF0QPD,
	ME_VGATHERPF0QPS,
	ME_VGATHERPF1DPD,
	ME_VGATHERPF1DPS,
	ME_VGATHERPF1QPD,
	ME_VGATHERPF1QPS,
	ME_VP4DPWSSD,
	ME_VP4DPWSSDS,
	ME_VRCP28PD,
	ME_VRCP28PS,
	ME_VRCP28SD,
	ME_VRCP28SS,
	ME_VRSQRT28PD,
	ME_VRSQRT28PS,
	ME_VRSQRT28SD,
	ME_VRSQRT28SS,
	ME_VSCATTERPF0DPD,
	ME_VSCATTERPF0DPS,
	ME_VSCATTERPF0QPD,
	ME_VSCATTERPF0QPS,
	ME_VSCATTERPF1DPD,
	ME_VSCATTERPF1DPS,
	ME_VSCATTERPF1QPD,
	ME_VSCATTERPF1QPS
} me_opcode;



void me_op_aaa(Mirtille_VirtualMachine *me);
void me_op_aad(Mirtille_VirtualMachine *me);
void me_op_aam(Mirtille_VirtualMachine *me);
void me_op_aas(Mirtille_VirtualMachine *me);
void me_op_adc(Mirtille_VirtualMachine *me);
void me_op_adcx(Mirtille_VirtualMachine *me);
void me_op_add(Mirtille_VirtualMachine *me);
void me_op_addpd(Mirtille_VirtualMachine *me);
void me_op_addps(Mirtille_VirtualMachine *me);
void me_op_addsd(Mirtille_VirtualMachine *me);
void me_op_addss(Mirtille_VirtualMachine *me);
void me_op_addsubpd(Mirtille_VirtualMachine *me);
void me_op_addsubps(Mirtille_VirtualMachine *me);
void me_op_adox(Mirtille_VirtualMachine *me);
void me_op_aesdec(Mirtille_VirtualMachine *me);
void me_op_aesdec128kl(Mirtille_VirtualMachine *me);
void me_op_aesdec256kl(Mirtille_VirtualMachine *me);
void me_op_aesdeclast(Mirtille_VirtualMachine *me);
void me_op_aesdecwide128kl(Mirtille_VirtualMachine *me);
void me_op_aesdecwide256kl(Mirtille_VirtualMachine *me);
void me_op_aesenc(Mirtille_VirtualMachine *me);
void me_op_aesenc128kl(Mirtille_VirtualMachine *me);
void me_op_aesenc256kl(Mirtille_VirtualMachine *me);
void me_op_aesenclast(Mirtille_VirtualMachine *me);
void me_op_aesencwide128kl(Mirtille_VirtualMachine *me);
void me_op_aesencwide256kl(Mirtille_VirtualMachine *me);
void me_op_aesimc(Mirtille_VirtualMachine *me);
void me_op_aeskeygenassist(Mirtille_VirtualMachine *me);
void me_op_and(Mirtille_VirtualMachine *me);
void me_op_andn(Mirtille_VirtualMachine *me);
void me_op_andnpd(Mirtille_VirtualMachine *me);
void me_op_andnps(Mirtille_VirtualMachine *me);
void me_op_andpd(Mirtille_VirtualMachine *me);
void me_op_andps(Mirtille_VirtualMachine *me);
void me_op_arpl(Mirtille_VirtualMachine *me);
void me_op_bextr(Mirtille_VirtualMachine *me);
void me_op_blendpd(Mirtille_VirtualMachine *me);
void me_op_blendps(Mirtille_VirtualMachine *me);
void me_op_blendvpd(Mirtille_VirtualMachine *me);
void me_op_blendvps(Mirtille_VirtualMachine *me);
void me_op_blsi(Mirtille_VirtualMachine *me);
void me_op_blsmsk(Mirtille_VirtualMachine *me);
void me_op_blsr(Mirtille_VirtualMachine *me);
void me_op_bndcl(Mirtille_VirtualMachine *me);
void me_op_bndcn(Mirtille_VirtualMachine *me);
void me_op_bndcu(Mirtille_VirtualMachine *me);
void me_op_bndldx(Mirtille_VirtualMachine *me);
void me_op_bndmk(Mirtille_VirtualMachine *me);
void me_op_bndmov(Mirtille_VirtualMachine *me);
void me_op_bndstx(Mirtille_VirtualMachine *me);
void me_op_bound(Mirtille_VirtualMachine *me);
void me_op_bsf(Mirtille_VirtualMachine *me);
void me_op_bsr(Mirtille_VirtualMachine *me);
void me_op_bswap(Mirtille_VirtualMachine *me);
void me_op_bt(Mirtille_VirtualMachine *me);
void me_op_btc(Mirtille_VirtualMachine *me);
void me_op_btr(Mirtille_VirtualMachine *me);
void me_op_bts(Mirtille_VirtualMachine *me);
void me_op_bzhi(Mirtille_VirtualMachine *me);
void me_op_call(Mirtille_VirtualMachine *me);
void me_op_cbw(Mirtille_VirtualMachine *me);
void me_op_cdq(Mirtille_VirtualMachine *me);
void me_op_cdqe(Mirtille_VirtualMachine *me);
void me_op_clac(Mirtille_VirtualMachine *me);
void me_op_clc(Mirtille_VirtualMachine *me);
void me_op_cld(Mirtille_VirtualMachine *me);
void me_op_cldemote(Mirtille_VirtualMachine *me);
void me_op_clflush(Mirtille_VirtualMachine *me);
void me_op_clflushopt(Mirtille_VirtualMachine *me);
void me_op_cli(Mirtille_VirtualMachine *me);
void me_op_clrssbsy(Mirtille_VirtualMachine *me);
void me_op_clts(Mirtille_VirtualMachine *me);
void me_op_clui(Mirtille_VirtualMachine *me);
void me_op_clwb(Mirtille_VirtualMachine *me);
void me_op_cmc(Mirtille_VirtualMachine *me);
void me_op_cmovcc(Mirtille_VirtualMachine *me);
void me_op_cmp(Mirtille_VirtualMachine *me);
void me_op_cmppd(Mirtille_VirtualMachine *me);
void me_op_cmpps(Mirtille_VirtualMachine *me);
void me_op_cmps(Mirtille_VirtualMachine *me);
void me_op_cmpsb(Mirtille_VirtualMachine *me);
void me_op_cmpsd(Mirtille_VirtualMachine *me);
void me_op_cmpsd(Mirtille_VirtualMachine *me);
void me_op_cmpsq(Mirtille_VirtualMachine *me);
void me_op_cmpss(Mirtille_VirtualMachine *me);
void me_op_cmpsw(Mirtille_VirtualMachine *me);
void me_op_cmpxchg(Mirtille_VirtualMachine *me);
void me_op_cmpxchg16b(Mirtille_VirtualMachine *me);
void me_op_cmpxchg8b(Mirtille_VirtualMachine *me);
void me_op_comisd(Mirtille_VirtualMachine *me);
void me_op_comiss(Mirtille_VirtualMachine *me);
void me_op_cpuid(Mirtille_VirtualMachine *me);
void me_op_cqo(Mirtille_VirtualMachine *me);
void me_op_crc32(Mirtille_VirtualMachine *me);
void me_op_cvtdq2pd(Mirtille_VirtualMachine *me);
void me_op_cvtdq2ps(Mirtille_VirtualMachine *me);
void me_op_cvtpd2dq(Mirtille_VirtualMachine *me);
void me_op_cvtpd2pi(Mirtille_VirtualMachine *me);
void me_op_cvtpd2ps(Mirtille_VirtualMachine *me);
void me_op_cvtpi2pd(Mirtille_VirtualMachine *me);
void me_op_cvtpi2ps(Mirtille_VirtualMachine *me);
void me_op_cvtps2dq(Mirtille_VirtualMachine *me);
void me_op_cvtps2pd(Mirtille_VirtualMachine *me);
void me_op_cvtps2pi(Mirtille_VirtualMachine *me);
void me_op_cvtsd2si(Mirtille_VirtualMachine *me);
void me_op_cvtsd2ss(Mirtille_VirtualMachine *me);
void me_op_cvtsi2sd(Mirtille_VirtualMachine *me);
void me_op_cvtsi2ss(Mirtille_VirtualMachine *me);
void me_op_cvtss2sd(Mirtille_VirtualMachine *me);
void me_op_cvtss2si(Mirtille_VirtualMachine *me);
void me_op_cvttpd2dq(Mirtille_VirtualMachine *me);
void me_op_cvttpd2pi(Mirtille_VirtualMachine *me);
void me_op_cvttps2dq(Mirtille_VirtualMachine *me);
void me_op_cvttps2pi(Mirtille_VirtualMachine *me);
void me_op_cvttsd2si(Mirtille_VirtualMachine *me);
void me_op_cvttss2si(Mirtille_VirtualMachine *me);
void me_op_cwd(Mirtille_VirtualMachine *me);
void me_op_cwde(Mirtille_VirtualMachine *me);
void me_op_daa(Mirtille_VirtualMachine *me);
void me_op_das(Mirtille_VirtualMachine *me);
void me_op_dec(Mirtille_VirtualMachine *me);
void me_op_div(Mirtille_VirtualMachine *me);
void me_op_divpd(Mirtille_VirtualMachine *me);
void me_op_divps(Mirtille_VirtualMachine *me);
void me_op_divsd(Mirtille_VirtualMachine *me);
void me_op_divss(Mirtille_VirtualMachine *me);
void me_op_dppd(Mirtille_VirtualMachine *me);
void me_op_dpps(Mirtille_VirtualMachine *me);
void me_op_emms(Mirtille_VirtualMachine *me);
void me_op_encodekey128(Mirtille_VirtualMachine *me);
void me_op_encodekey256(Mirtille_VirtualMachine *me);
void me_op_endbr32(Mirtille_VirtualMachine *me);
void me_op_endbr64(Mirtille_VirtualMachine *me);
void me_op_enqcmd(Mirtille_VirtualMachine *me);
void me_op_enqcmds(Mirtille_VirtualMachine *me);
void me_op_enter(Mirtille_VirtualMachine *me);
void me_op_extractps(Mirtille_VirtualMachine *me);
void me_op_f2xm1(Mirtille_VirtualMachine *me);
void me_op_fabs(Mirtille_VirtualMachine *me);
void me_op_fadd(Mirtille_VirtualMachine *me);
void me_op_faddp(Mirtille_VirtualMachine *me);
void me_op_fbld(Mirtille_VirtualMachine *me);
void me_op_fbstp(Mirtille_VirtualMachine *me);
void me_op_fchs(Mirtille_VirtualMachine *me);
void me_op_fclex(Mirtille_VirtualMachine *me);
void me_op_fcmovcc(Mirtille_VirtualMachine *me);
void me_op_fcom(Mirtille_VirtualMachine *me);
void me_op_fcomi(Mirtille_VirtualMachine *me);
void me_op_fcomip(Mirtille_VirtualMachine *me);
void me_op_fcomp(Mirtille_VirtualMachine *me);
void me_op_fcompp(Mirtille_VirtualMachine *me);
void me_op_fcos(Mirtille_VirtualMachine *me);
void me_op_fdecstp(Mirtille_VirtualMachine *me);
void me_op_fdiv(Mirtille_VirtualMachine *me);
void me_op_fdivp(Mirtille_VirtualMachine *me);
void me_op_fdivr(Mirtille_VirtualMachine *me);
void me_op_fdivrp(Mirtille_VirtualMachine *me);
void me_op_ffree(Mirtille_VirtualMachine *me);
void me_op_fiadd(Mirtille_VirtualMachine *me);
void me_op_ficom(Mirtille_VirtualMachine *me);
void me_op_ficomp(Mirtille_VirtualMachine *me);
void me_op_fidiv(Mirtille_VirtualMachine *me);
void me_op_fidivr(Mirtille_VirtualMachine *me);
void me_op_fild(Mirtille_VirtualMachine *me);
void me_op_fimul(Mirtille_VirtualMachine *me);
void me_op_fincstp(Mirtille_VirtualMachine *me);
void me_op_finit(Mirtille_VirtualMachine *me);
void me_op_fist(Mirtille_VirtualMachine *me);
void me_op_fistp(Mirtille_VirtualMachine *me);
void me_op_fisttp(Mirtille_VirtualMachine *me);
void me_op_fisub(Mirtille_VirtualMachine *me);
void me_op_fisubr(Mirtille_VirtualMachine *me);
void me_op_fld(Mirtille_VirtualMachine *me);
void me_op_fld1(Mirtille_VirtualMachine *me);
void me_op_fldcw(Mirtille_VirtualMachine *me);
void me_op_fldenv(Mirtille_VirtualMachine *me);
void me_op_fldl2e(Mirtille_VirtualMachine *me);
void me_op_fldl2t(Mirtille_VirtualMachine *me);
void me_op_fldlg2(Mirtille_VirtualMachine *me);
void me_op_fldln2(Mirtille_VirtualMachine *me);
void me_op_fldpi(Mirtille_VirtualMachine *me);
void me_op_fldz(Mirtille_VirtualMachine *me);
void me_op_fmul(Mirtille_VirtualMachine *me);
void me_op_fmulp(Mirtille_VirtualMachine *me);
void me_op_fnclex(Mirtille_VirtualMachine *me);
void me_op_fninit(Mirtille_VirtualMachine *me);
void me_op_fnop(Mirtille_VirtualMachine *me);
void me_op_fnsave(Mirtille_VirtualMachine *me);
void me_op_fnstcw(Mirtille_VirtualMachine *me);
void me_op_fnstenv(Mirtille_VirtualMachine *me);
void me_op_fnstsw(Mirtille_VirtualMachine *me);
void me_op_fpatan(Mirtille_VirtualMachine *me);
void me_op_fprem(Mirtille_VirtualMachine *me);
void me_op_fprem1(Mirtille_VirtualMachine *me);
void me_op_fptan(Mirtille_VirtualMachine *me);
void me_op_frndint(Mirtille_VirtualMachine *me);
void me_op_frstor(Mirtille_VirtualMachine *me);
void me_op_fsave(Mirtille_VirtualMachine *me);
void me_op_fscale(Mirtille_VirtualMachine *me);
void me_op_fsin(Mirtille_VirtualMachine *me);
void me_op_fsincos(Mirtille_VirtualMachine *me);
void me_op_fsqrt(Mirtille_VirtualMachine *me);
void me_op_fst(Mirtille_VirtualMachine *me);
void me_op_fstcw(Mirtille_VirtualMachine *me);
void me_op_fstenv(Mirtille_VirtualMachine *me);
void me_op_fstp(Mirtille_VirtualMachine *me);
void me_op_fstsw(Mirtille_VirtualMachine *me);
void me_op_fsub(Mirtille_VirtualMachine *me);
void me_op_fsubp(Mirtille_VirtualMachine *me);
void me_op_fsubr(Mirtille_VirtualMachine *me);
void me_op_fsubrp(Mirtille_VirtualMachine *me);
void me_op_ftst(Mirtille_VirtualMachine *me);
void me_op_fucom(Mirtille_VirtualMachine *me);
void me_op_fucomi(Mirtille_VirtualMachine *me);
void me_op_fucomip(Mirtille_VirtualMachine *me);
void me_op_fucomp(Mirtille_VirtualMachine *me);
void me_op_fucompp(Mirtille_VirtualMachine *me);
void me_op_fwait(Mirtille_VirtualMachine *me);
void me_op_fxam(Mirtille_VirtualMachine *me);
void me_op_fxch(Mirtille_VirtualMachine *me);
void me_op_fxrstor(Mirtille_VirtualMachine *me);
void me_op_fxsave(Mirtille_VirtualMachine *me);
void me_op_fxtract(Mirtille_VirtualMachine *me);
void me_op_fyl2x(Mirtille_VirtualMachine *me);
void me_op_fyl2xp1(Mirtille_VirtualMachine *me);
void me_op_gf2p8affineinvqb(Mirtille_VirtualMachine *me);
void me_op_gf2p8affineqb(Mirtille_VirtualMachine *me);
void me_op_gf2p8mulb(Mirtille_VirtualMachine *me);
void me_op_haddpd(Mirtille_VirtualMachine *me);
void me_op_haddps(Mirtille_VirtualMachine *me);
void me_op_hlt(Mirtille_VirtualMachine *me);
void me_op_hreset(Mirtille_VirtualMachine *me);
void me_op_hsubpd(Mirtille_VirtualMachine *me);
void me_op_hsubps(Mirtille_VirtualMachine *me);
void me_op_idiv(Mirtille_VirtualMachine *me);
void me_op_imul(Mirtille_VirtualMachine *me);
void me_op_in(Mirtille_VirtualMachine *me);
void me_op_inc(Mirtille_VirtualMachine *me);
void me_op_incsspd(Mirtille_VirtualMachine *me);
void me_op_incsspq(Mirtille_VirtualMachine *me);
void me_op_ins(Mirtille_VirtualMachine *me);
void me_op_insb(Mirtille_VirtualMachine *me);
void me_op_insd(Mirtille_VirtualMachine *me);
void me_op_insertps(Mirtille_VirtualMachine *me);
void me_op_insw(Mirtille_VirtualMachine *me);
void me_op_int(Mirtille_VirtualMachine *me);
void me_op_int1(Mirtille_VirtualMachine *me);
void me_op_int3(Mirtille_VirtualMachine *me);
void me_op_into(Mirtille_VirtualMachine *me);
void me_op_invd(Mirtille_VirtualMachine *me);
void me_op_invlpg(Mirtille_VirtualMachine *me);
void me_op_invpcid(Mirtille_VirtualMachine *me);
void me_op_iret(Mirtille_VirtualMachine *me);
void me_op_iretd(Mirtille_VirtualMachine *me);
void me_op_iretq(Mirtille_VirtualMachine *me);
void me_op_jmp(Mirtille_VirtualMachine *me);
void me_op_jcc(Mirtille_VirtualMachine *me);
void me_op_kaddb(Mirtille_VirtualMachine *me);
void me_op_kaddd(Mirtille_VirtualMachine *me);
void me_op_kaddq(Mirtille_VirtualMachine *me);
void me_op_kaddw(Mirtille_VirtualMachine *me);
void me_op_kandb(Mirtille_VirtualMachine *me);
void me_op_kandd(Mirtille_VirtualMachine *me);
void me_op_kandnb(Mirtille_VirtualMachine *me);
void me_op_kandnd(Mirtille_VirtualMachine *me);
void me_op_kandnq(Mirtille_VirtualMachine *me);
void me_op_kandnw(Mirtille_VirtualMachine *me);
void me_op_kandq(Mirtille_VirtualMachine *me);
void me_op_kandw(Mirtille_VirtualMachine *me);
void me_op_kmovb(Mirtille_VirtualMachine *me);
void me_op_kmovd(Mirtille_VirtualMachine *me);
void me_op_kmovq(Mirtille_VirtualMachine *me);
void me_op_kmovw(Mirtille_VirtualMachine *me);
void me_op_knotb(Mirtille_VirtualMachine *me);
void me_op_knotd(Mirtille_VirtualMachine *me);
void me_op_knotq(Mirtille_VirtualMachine *me);
void me_op_knotw(Mirtille_VirtualMachine *me);
void me_op_korb(Mirtille_VirtualMachine *me);
void me_op_kord(Mirtille_VirtualMachine *me);
void me_op_korq(Mirtille_VirtualMachine *me);
void me_op_kortestb(Mirtille_VirtualMachine *me);
void me_op_kortestd(Mirtille_VirtualMachine *me);
void me_op_kortestq(Mirtille_VirtualMachine *me);
void me_op_kortestw(Mirtille_VirtualMachine *me);
void me_op_korw(Mirtille_VirtualMachine *me);
void me_op_kshiftlb(Mirtille_VirtualMachine *me);
void me_op_kshiftld(Mirtille_VirtualMachine *me);
void me_op_kshiftlq(Mirtille_VirtualMachine *me);
void me_op_kshiftlw(Mirtille_VirtualMachine *me);
void me_op_kshiftrb(Mirtille_VirtualMachine *me);
void me_op_kshiftrd(Mirtille_VirtualMachine *me);
void me_op_kshiftrq(Mirtille_VirtualMachine *me);
void me_op_kshiftrw(Mirtille_VirtualMachine *me);
void me_op_ktestb(Mirtille_VirtualMachine *me);
void me_op_ktestd(Mirtille_VirtualMachine *me);
void me_op_ktestq(Mirtille_VirtualMachine *me);
void me_op_ktestw(Mirtille_VirtualMachine *me);
void me_op_kunpckbw(Mirtille_VirtualMachine *me);
void me_op_kunpckdq(Mirtille_VirtualMachine *me);
void me_op_kunpckwd(Mirtille_VirtualMachine *me);
void me_op_kxnorb(Mirtille_VirtualMachine *me);
void me_op_kxnord(Mirtille_VirtualMachine *me);
void me_op_kxnorq(Mirtille_VirtualMachine *me);
void me_op_kxnorw(Mirtille_VirtualMachine *me);
void me_op_kxorb(Mirtille_VirtualMachine *me);
void me_op_kxord(Mirtille_VirtualMachine *me);
void me_op_kxorq(Mirtille_VirtualMachine *me);
void me_op_kxorw(Mirtille_VirtualMachine *me);
void me_op_lahf(Mirtille_VirtualMachine *me);
void me_op_lar(Mirtille_VirtualMachine *me);
void me_op_lddqu(Mirtille_VirtualMachine *me);
void me_op_ldmxcsr(Mirtille_VirtualMachine *me);
void me_op_lds(Mirtille_VirtualMachine *me);
void me_op_ldtilecfg(Mirtille_VirtualMachine *me);
void me_op_lea(Mirtille_VirtualMachine *me);
void me_op_leave(Mirtille_VirtualMachine *me);
void me_op_les(Mirtille_VirtualMachine *me);
void me_op_lfence(Mirtille_VirtualMachine *me);
void me_op_lfs(Mirtille_VirtualMachine *me);
void me_op_lgdt(Mirtille_VirtualMachine *me);
void me_op_lgs(Mirtille_VirtualMachine *me);
void me_op_lidt(Mirtille_VirtualMachine *me);
void me_op_lldt(Mirtille_VirtualMachine *me);
void me_op_lmsw(Mirtille_VirtualMachine *me);
void me_op_loadiwkey(Mirtille_VirtualMachine *me);
void me_op_lock(Mirtille_VirtualMachine *me);
void me_op_lods(Mirtille_VirtualMachine *me);
void me_op_lodsb(Mirtille_VirtualMachine *me);
void me_op_lodsd(Mirtille_VirtualMachine *me);
void me_op_lodsq(Mirtille_VirtualMachine *me);
void me_op_lodsw(Mirtille_VirtualMachine *me);
void me_op_loop(Mirtille_VirtualMachine *me);
void me_op_loopcc(Mirtille_VirtualMachine *me);
void me_op_lsl(Mirtille_VirtualMachine *me);
void me_op_lss(Mirtille_VirtualMachine *me);
void me_op_ltr(Mirtille_VirtualMachine *me);
void me_op_lzcnt(Mirtille_VirtualMachine *me);
void me_op_maskmovdqu(Mirtille_VirtualMachine *me);
void me_op_maskmovq(Mirtille_VirtualMachine *me);
void me_op_maxpd(Mirtille_VirtualMachine *me);
void me_op_maxps(Mirtille_VirtualMachine *me);
void me_op_maxsd(Mirtille_VirtualMachine *me);
void me_op_maxss(Mirtille_VirtualMachine *me);
void me_op_mfence(Mirtille_VirtualMachine *me);
void me_op_minpd(Mirtille_VirtualMachine *me);
void me_op_minps(Mirtille_VirtualMachine *me);
void me_op_minsd(Mirtille_VirtualMachine *me);
void me_op_minss(Mirtille_VirtualMachine *me);
void me_op_monitor(Mirtille_VirtualMachine *me);
void me_op_mov(Mirtille_VirtualMachine *me);
void me_op_mov(Mirtille_VirtualMachine *me);
void me_op_mov(Mirtille_VirtualMachine *me);
void me_op_movapd(Mirtille_VirtualMachine *me);
void me_op_movaps(Mirtille_VirtualMachine *me);
void me_op_movbe(Mirtille_VirtualMachine *me);
void me_op_movd(Mirtille_VirtualMachine *me);
void me_op_movddup(Mirtille_VirtualMachine *me);
void me_op_movdir64b(Mirtille_VirtualMachine *me);
void me_op_movdiri(Mirtille_VirtualMachine *me);
void me_op_movdq2q(Mirtille_VirtualMachine *me);
void me_op_movdqa(Mirtille_VirtualMachine *me);
void me_op_movdqu(Mirtille_VirtualMachine *me);
void me_op_movhlps(Mirtille_VirtualMachine *me);
void me_op_movhpd(Mirtille_VirtualMachine *me);
void me_op_movhps(Mirtille_VirtualMachine *me);
void me_op_movlhps(Mirtille_VirtualMachine *me);
void me_op_movlpd(Mirtille_VirtualMachine *me);
void me_op_movlps(Mirtille_VirtualMachine *me);
void me_op_movmskpd(Mirtille_VirtualMachine *me);
void me_op_movmskps(Mirtille_VirtualMachine *me);
void me_op_movntdq(Mirtille_VirtualMachine *me);
void me_op_movntdqa(Mirtille_VirtualMachine *me);
void me_op_movnti(Mirtille_VirtualMachine *me);
void me_op_movntpd(Mirtille_VirtualMachine *me);
void me_op_movntps(Mirtille_VirtualMachine *me);
void me_op_movntq(Mirtille_VirtualMachine *me);
void me_op_movq(Mirtille_VirtualMachine *me);
void me_op_movq(Mirtille_VirtualMachine *me);
void me_op_movq2dq(Mirtille_VirtualMachine *me);
void me_op_movs(Mirtille_VirtualMachine *me);
void me_op_movsb(Mirtille_VirtualMachine *me);
void me_op_movsd(Mirtille_VirtualMachine *me);
void me_op_movsd(Mirtille_VirtualMachine *me);
void me_op_movshdup(Mirtille_VirtualMachine *me);
void me_op_movsldup(Mirtille_VirtualMachine *me);
void me_op_movsq(Mirtille_VirtualMachine *me);
void me_op_movss(Mirtille_VirtualMachine *me);
void me_op_movsw(Mirtille_VirtualMachine *me);
void me_op_movsx(Mirtille_VirtualMachine *me);
void me_op_movsxd(Mirtille_VirtualMachine *me);
void me_op_movupd(Mirtille_VirtualMachine *me);
void me_op_movups(Mirtille_VirtualMachine *me);
void me_op_movzx(Mirtille_VirtualMachine *me);
void me_op_mpsadbw(Mirtille_VirtualMachine *me);
void me_op_mul(Mirtille_VirtualMachine *me);
void me_op_mulpd(Mirtille_VirtualMachine *me);
void me_op_mulps(Mirtille_VirtualMachine *me);
void me_op_mulsd(Mirtille_VirtualMachine *me);
void me_op_mulss(Mirtille_VirtualMachine *me);
void me_op_mulx(Mirtille_VirtualMachine *me);
void me_op_mwait(Mirtille_VirtualMachine *me);
void me_op_neg(Mirtille_VirtualMachine *me);
void me_op_nop(Mirtille_VirtualMachine *me);
void me_op_not(Mirtille_VirtualMachine *me);
void me_op_or(Mirtille_VirtualMachine *me);
void me_op_orpd(Mirtille_VirtualMachine *me);
void me_op_orps(Mirtille_VirtualMachine *me);
void me_op_out(Mirtille_VirtualMachine *me);
void me_op_outs(Mirtille_VirtualMachine *me);
void me_op_outsb(Mirtille_VirtualMachine *me);
void me_op_outsd(Mirtille_VirtualMachine *me);
void me_op_outsw(Mirtille_VirtualMachine *me);
void me_op_pabsb(Mirtille_VirtualMachine *me);
void me_op_pabsd(Mirtille_VirtualMachine *me);
void me_op_pabsq(Mirtille_VirtualMachine *me);
void me_op_pabsw(Mirtille_VirtualMachine *me);
void me_op_packssdw(Mirtille_VirtualMachine *me);
void me_op_packsswb(Mirtille_VirtualMachine *me);
void me_op_packusdw(Mirtille_VirtualMachine *me);
void me_op_packuswb(Mirtille_VirtualMachine *me);
void me_op_paddb(Mirtille_VirtualMachine *me);
void me_op_paddd(Mirtille_VirtualMachine *me);
void me_op_paddq(Mirtille_VirtualMachine *me);
void me_op_paddsb(Mirtille_VirtualMachine *me);
void me_op_paddsw(Mirtille_VirtualMachine *me);
void me_op_paddusb(Mirtille_VirtualMachine *me);
void me_op_paddusw(Mirtille_VirtualMachine *me);
void me_op_paddw(Mirtille_VirtualMachine *me);
void me_op_palignr(Mirtille_VirtualMachine *me);
void me_op_pand(Mirtille_VirtualMachine *me);
void me_op_pandn(Mirtille_VirtualMachine *me);
void me_op_pause(Mirtille_VirtualMachine *me);
void me_op_pavgb(Mirtille_VirtualMachine *me);
void me_op_pavgw(Mirtille_VirtualMachine *me);
void me_op_pblendvb(Mirtille_VirtualMachine *me);
void me_op_pblendw(Mirtille_VirtualMachine *me);
void me_op_pclmulqdq(Mirtille_VirtualMachine *me);
void me_op_pcmpeqb(Mirtille_VirtualMachine *me);
void me_op_pcmpeqd(Mirtille_VirtualMachine *me);
void me_op_pcmpeqq(Mirtille_VirtualMachine *me);
void me_op_pcmpeqw(Mirtille_VirtualMachine *me);
void me_op_pcmpestri(Mirtille_VirtualMachine *me);
void me_op_pcmpestrm(Mirtille_VirtualMachine *me);
void me_op_pcmpgtb(Mirtille_VirtualMachine *me);
void me_op_pcmpgtd(Mirtille_VirtualMachine *me);
void me_op_pcmpgtq(Mirtille_VirtualMachine *me);
void me_op_pcmpgtw(Mirtille_VirtualMachine *me);
void me_op_pcmpistri(Mirtille_VirtualMachine *me);
void me_op_pcmpistrm(Mirtille_VirtualMachine *me);
void me_op_pconfig(Mirtille_VirtualMachine *me);
void me_op_pdep(Mirtille_VirtualMachine *me);
void me_op_pext(Mirtille_VirtualMachine *me);
void me_op_pextrb(Mirtille_VirtualMachine *me);
void me_op_pextrd(Mirtille_VirtualMachine *me);
void me_op_pextrq(Mirtille_VirtualMachine *me);
void me_op_pextrw(Mirtille_VirtualMachine *me);
void me_op_phaddd(Mirtille_VirtualMachine *me);
void me_op_phaddsw(Mirtille_VirtualMachine *me);
void me_op_phaddw(Mirtille_VirtualMachine *me);
void me_op_phminposuw(Mirtille_VirtualMachine *me);
void me_op_phsubd(Mirtille_VirtualMachine *me);
void me_op_phsubsw(Mirtille_VirtualMachine *me);
void me_op_phsubw(Mirtille_VirtualMachine *me);
void me_op_pinsrb(Mirtille_VirtualMachine *me);
void me_op_pinsrd(Mirtille_VirtualMachine *me);
void me_op_pinsrq(Mirtille_VirtualMachine *me);
void me_op_pinsrw(Mirtille_VirtualMachine *me);
void me_op_pmaddubsw(Mirtille_VirtualMachine *me);
void me_op_pmaddwd(Mirtille_VirtualMachine *me);
void me_op_pmaxsb(Mirtille_VirtualMachine *me);
void me_op_pmaxsd(Mirtille_VirtualMachine *me);
void me_op_pmaxsq(Mirtille_VirtualMachine *me);
void me_op_pmaxsw(Mirtille_VirtualMachine *me);
void me_op_pmaxub(Mirtille_VirtualMachine *me);
void me_op_pmaxud(Mirtille_VirtualMachine *me);
void me_op_pmaxuq(Mirtille_VirtualMachine *me);
void me_op_pmaxuw(Mirtille_VirtualMachine *me);
void me_op_pminsb(Mirtille_VirtualMachine *me);
void me_op_pminsd(Mirtille_VirtualMachine *me);
void me_op_pminsq(Mirtille_VirtualMachine *me);
void me_op_pminsw(Mirtille_VirtualMachine *me);
void me_op_pminub(Mirtille_VirtualMachine *me);
void me_op_pminud(Mirtille_VirtualMachine *me);
void me_op_pminuq(Mirtille_VirtualMachine *me);
void me_op_pminuw(Mirtille_VirtualMachine *me);
void me_op_pmovmskb(Mirtille_VirtualMachine *me);
void me_op_pmovsx(Mirtille_VirtualMachine *me);
void me_op_pmovzx(Mirtille_VirtualMachine *me);
void me_op_pmuldq(Mirtille_VirtualMachine *me);
void me_op_pmulhrsw(Mirtille_VirtualMachine *me);
void me_op_pmulhuw(Mirtille_VirtualMachine *me);
void me_op_pmulhw(Mirtille_VirtualMachine *me);
void me_op_pmulld(Mirtille_VirtualMachine *me);
void me_op_pmullq(Mirtille_VirtualMachine *me);
void me_op_pmullw(Mirtille_VirtualMachine *me);
void me_op_pmuludq(Mirtille_VirtualMachine *me);
void me_op_pop(Mirtille_VirtualMachine *me);
void me_op_popa(Mirtille_VirtualMachine *me);
void me_op_popad(Mirtille_VirtualMachine *me);
void me_op_popcnt(Mirtille_VirtualMachine *me);
void me_op_popf(Mirtille_VirtualMachine *me);
void me_op_popfd(Mirtille_VirtualMachine *me);
void me_op_popfq(Mirtille_VirtualMachine *me);
void me_op_por(Mirtille_VirtualMachine *me);
void me_op_prefetchw(Mirtille_VirtualMachine *me);
void me_op_prefetchh(Mirtille_VirtualMachine *me);
void me_op_psadbw(Mirtille_VirtualMachine *me);
void me_op_pshufb(Mirtille_VirtualMachine *me);
void me_op_pshufd(Mirtille_VirtualMachine *me);
void me_op_pshufhw(Mirtille_VirtualMachine *me);
void me_op_pshuflw(Mirtille_VirtualMachine *me);
void me_op_pshufw(Mirtille_VirtualMachine *me);
void me_op_psignb(Mirtille_VirtualMachine *me);
void me_op_psignd(Mirtille_VirtualMachine *me);
void me_op_psignw(Mirtille_VirtualMachine *me);
void me_op_pslld(Mirtille_VirtualMachine *me);
void me_op_pslldq(Mirtille_VirtualMachine *me);
void me_op_psllq(Mirtille_VirtualMachine *me);
void me_op_psllw(Mirtille_VirtualMachine *me);
void me_op_psrad(Mirtille_VirtualMachine *me);
void me_op_psraq(Mirtille_VirtualMachine *me);
void me_op_psraw(Mirtille_VirtualMachine *me);
void me_op_psrld(Mirtille_VirtualMachine *me);
void me_op_psrldq(Mirtille_VirtualMachine *me);
void me_op_psrlq(Mirtille_VirtualMachine *me);
void me_op_psrlw(Mirtille_VirtualMachine *me);
void me_op_psubb(Mirtille_VirtualMachine *me);
void me_op_psubd(Mirtille_VirtualMachine *me);
void me_op_psubq(Mirtille_VirtualMachine *me);
void me_op_psubsb(Mirtille_VirtualMachine *me);
void me_op_psubsw(Mirtille_VirtualMachine *me);
void me_op_psubusb(Mirtille_VirtualMachine *me);
void me_op_psubusw(Mirtille_VirtualMachine *me);
void me_op_psubw(Mirtille_VirtualMachine *me);
void me_op_ptest(Mirtille_VirtualMachine *me);
void me_op_ptwrite(Mirtille_VirtualMachine *me);
void me_op_punpckhbw(Mirtille_VirtualMachine *me);
void me_op_punpckhdq(Mirtille_VirtualMachine *me);
void me_op_punpckhqdq(Mirtille_VirtualMachine *me);
void me_op_punpckhwd(Mirtille_VirtualMachine *me);
void me_op_punpcklbw(Mirtille_VirtualMachine *me);
void me_op_punpckldq(Mirtille_VirtualMachine *me);
void me_op_punpcklqdq(Mirtille_VirtualMachine *me);
void me_op_punpcklwd(Mirtille_VirtualMachine *me);
void me_op_push(Mirtille_VirtualMachine *me);
void me_op_pusha(Mirtille_VirtualMachine *me);
void me_op_pushad(Mirtille_VirtualMachine *me);
void me_op_pushf(Mirtille_VirtualMachine *me);
void me_op_pushfd(Mirtille_VirtualMachine *me);
void me_op_pushfq(Mirtille_VirtualMachine *me);
void me_op_pxor(Mirtille_VirtualMachine *me);
void me_op_rcl(Mirtille_VirtualMachine *me);
void me_op_rcpps(Mirtille_VirtualMachine *me);
void me_op_rcpss(Mirtille_VirtualMachine *me);
void me_op_rcr(Mirtille_VirtualMachine *me);
void me_op_rdfsbase(Mirtille_VirtualMachine *me);
void me_op_rdgsbase(Mirtille_VirtualMachine *me);
void me_op_rdmsr(Mirtille_VirtualMachine *me);
void me_op_rdpid(Mirtille_VirtualMachine *me);
void me_op_rdpkru(Mirtille_VirtualMachine *me);
void me_op_rdpmc(Mirtille_VirtualMachine *me);
void me_op_rdrand(Mirtille_VirtualMachine *me);
void me_op_rdseed(Mirtille_VirtualMachine *me);
void me_op_rdsspd(Mirtille_VirtualMachine *me);
void me_op_rdsspq(Mirtille_VirtualMachine *me);
void me_op_rdtsc(Mirtille_VirtualMachine *me);
void me_op_rdtscp(Mirtille_VirtualMachine *me);
void me_op_rep(Mirtille_VirtualMachine *me);
void me_op_repe(Mirtille_VirtualMachine *me);
void me_op_repne(Mirtille_VirtualMachine *me);
void me_op_repnz(Mirtille_VirtualMachine *me);
void me_op_repz(Mirtille_VirtualMachine *me);
void me_op_ret(Mirtille_VirtualMachine *me);
void me_op_rol(Mirtille_VirtualMachine *me);
void me_op_ror(Mirtille_VirtualMachine *me);
void me_op_rorx(Mirtille_VirtualMachine *me);
void me_op_roundpd(Mirtille_VirtualMachine *me);
void me_op_roundps(Mirtille_VirtualMachine *me);
void me_op_roundsd(Mirtille_VirtualMachine *me);
void me_op_roundss(Mirtille_VirtualMachine *me);
void me_op_rsm(Mirtille_VirtualMachine *me);
void me_op_rsqrtps(Mirtille_VirtualMachine *me);
void me_op_rsqrtss(Mirtille_VirtualMachine *me);
void me_op_rstorssp(Mirtille_VirtualMachine *me);
void me_op_sahf(Mirtille_VirtualMachine *me);
void me_op_sal(Mirtille_VirtualMachine *me);
void me_op_sar(Mirtille_VirtualMachine *me);
void me_op_sarx(Mirtille_VirtualMachine *me);
void me_op_saveprevssp(Mirtille_VirtualMachine *me);
void me_op_sbb(Mirtille_VirtualMachine *me);
void me_op_scas(Mirtille_VirtualMachine *me);
void me_op_scasb(Mirtille_VirtualMachine *me);
void me_op_scasd(Mirtille_VirtualMachine *me);
void me_op_scasw(Mirtille_VirtualMachine *me);
void me_op_senduipi(Mirtille_VirtualMachine *me);
void me_op_serialize(Mirtille_VirtualMachine *me);
void me_op_setssbsy(Mirtille_VirtualMachine *me);
void me_op_setcc(Mirtille_VirtualMachine *me);
void me_op_sfence(Mirtille_VirtualMachine *me);
void me_op_sgdt(Mirtille_VirtualMachine *me);
void me_op_sha1msg1(Mirtille_VirtualMachine *me);
void me_op_sha1msg2(Mirtille_VirtualMachine *me);
void me_op_sha1nexte(Mirtille_VirtualMachine *me);
void me_op_sha1rnds4(Mirtille_VirtualMachine *me);
void me_op_sha256msg1(Mirtille_VirtualMachine *me);
void me_op_sha256msg2(Mirtille_VirtualMachine *me);
void me_op_sha256rnds2(Mirtille_VirtualMachine *me);
void me_op_shl(Mirtille_VirtualMachine *me);
void me_op_shld(Mirtille_VirtualMachine *me);
void me_op_shlx(Mirtille_VirtualMachine *me);
void me_op_shr(Mirtille_VirtualMachine *me);
void me_op_shrd(Mirtille_VirtualMachine *me);
void me_op_shrx(Mirtille_VirtualMachine *me);
void me_op_shufpd(Mirtille_VirtualMachine *me);
void me_op_shufps(Mirtille_VirtualMachine *me);
void me_op_sidt(Mirtille_VirtualMachine *me);
void me_op_sldt(Mirtille_VirtualMachine *me);
void me_op_smsw(Mirtille_VirtualMachine *me);
void me_op_sqrtpd(Mirtille_VirtualMachine *me);
void me_op_sqrtps(Mirtille_VirtualMachine *me);
void me_op_sqrtsd(Mirtille_VirtualMachine *me);
void me_op_sqrtss(Mirtille_VirtualMachine *me);
void me_op_stac(Mirtille_VirtualMachine *me);
void me_op_stc(Mirtille_VirtualMachine *me);
void me_op_std(Mirtille_VirtualMachine *me);
void me_op_sti(Mirtille_VirtualMachine *me);
void me_op_stmxcsr(Mirtille_VirtualMachine *me);
void me_op_stos(Mirtille_VirtualMachine *me);
void me_op_stosb(Mirtille_VirtualMachine *me);
void me_op_stosd(Mirtille_VirtualMachine *me);
void me_op_stosq(Mirtille_VirtualMachine *me);
void me_op_stosw(Mirtille_VirtualMachine *me);
void me_op_str(Mirtille_VirtualMachine *me);
void me_op_sttilecfg(Mirtille_VirtualMachine *me);
void me_op_stui(Mirtille_VirtualMachine *me);
void me_op_sub(Mirtille_VirtualMachine *me);
void me_op_subpd(Mirtille_VirtualMachine *me);
void me_op_subps(Mirtille_VirtualMachine *me);
void me_op_subsd(Mirtille_VirtualMachine *me);
void me_op_subss(Mirtille_VirtualMachine *me);
void me_op_swapgs(Mirtille_VirtualMachine *me);
void me_op_syscall(Mirtille_VirtualMachine *me);
void me_op_sysenter(Mirtille_VirtualMachine *me);
void me_op_sysexit(Mirtille_VirtualMachine *me);
void me_op_sysret(Mirtille_VirtualMachine *me);
void me_op_tdpbf16ps(Mirtille_VirtualMachine *me);
void me_op_tdpbssd(Mirtille_VirtualMachine *me);
void me_op_tdpbsud(Mirtille_VirtualMachine *me);
void me_op_tdpbusd(Mirtille_VirtualMachine *me);
void me_op_tdpbuud(Mirtille_VirtualMachine *me);
void me_op_test(Mirtille_VirtualMachine *me);
void me_op_testui(Mirtille_VirtualMachine *me);
void me_op_tileloadd(Mirtille_VirtualMachine *me);
void me_op_tileloaddt1(Mirtille_VirtualMachine *me);
void me_op_tilerelease(Mirtille_VirtualMachine *me);
void me_op_tilestored(Mirtille_VirtualMachine *me);
void me_op_tilezero(Mirtille_VirtualMachine *me);
void me_op_tpause(Mirtille_VirtualMachine *me);
void me_op_tzcnt(Mirtille_VirtualMachine *me);
void me_op_ucomisd(Mirtille_VirtualMachine *me);
void me_op_ucomiss(Mirtille_VirtualMachine *me);
void me_op_ud(Mirtille_VirtualMachine *me);
void me_op_uiret(Mirtille_VirtualMachine *me);
void me_op_umonitor(Mirtille_VirtualMachine *me);
void me_op_umwait(Mirtille_VirtualMachine *me);
void me_op_unpckhpd(Mirtille_VirtualMachine *me);
void me_op_unpckhps(Mirtille_VirtualMachine *me);
void me_op_unpcklpd(Mirtille_VirtualMachine *me);
void me_op_unpcklps(Mirtille_VirtualMachine *me);
void me_op_vaddph(Mirtille_VirtualMachine *me);
void me_op_vaddsh(Mirtille_VirtualMachine *me);
void me_op_valignd(Mirtille_VirtualMachine *me);
void me_op_valignq(Mirtille_VirtualMachine *me);
void me_op_vblendmpd(Mirtille_VirtualMachine *me);
void me_op_vblendmps(Mirtille_VirtualMachine *me);
void me_op_vbroadcast(Mirtille_VirtualMachine *me);
void me_op_vcmpph(Mirtille_VirtualMachine *me);
void me_op_vcmpsh(Mirtille_VirtualMachine *me);
void me_op_vcomish(Mirtille_VirtualMachine *me);
void me_op_vcompresspd(Mirtille_VirtualMachine *me);
void me_op_vcompressps(Mirtille_VirtualMachine *me);
void me_op_vcompressw(Mirtille_VirtualMachine *me);
void me_op_vcvtdq2ph(Mirtille_VirtualMachine *me);
void me_op_vcvtne2ps2bf16(Mirtille_VirtualMachine *me);
void me_op_vcvtneps2bf16(Mirtille_VirtualMachine *me);
void me_op_vcvtpd2ph(Mirtille_VirtualMachine *me);
void me_op_vcvtpd2qq(Mirtille_VirtualMachine *me);
void me_op_vcvtpd2udq(Mirtille_VirtualMachine *me);
void me_op_vcvtpd2uqq(Mirtille_VirtualMachine *me);
void me_op_vcvtph2dq(Mirtille_VirtualMachine *me);
void me_op_vcvtph2pd(Mirtille_VirtualMachine *me);
void me_op_vcvtph2ps(Mirtille_VirtualMachine *me);
void me_op_vcvtph2psx(Mirtille_VirtualMachine *me);
void me_op_vcvtph2qq(Mirtille_VirtualMachine *me);
void me_op_vcvtph2udq(Mirtille_VirtualMachine *me);
void me_op_vcvtph2uqq(Mirtille_VirtualMachine *me);
void me_op_vcvtph2uw(Mirtille_VirtualMachine *me);
void me_op_vcvtph2w(Mirtille_VirtualMachine *me);
void me_op_vcvtps2ph(Mirtille_VirtualMachine *me);
void me_op_vcvtps2phx(Mirtille_VirtualMachine *me);
void me_op_vcvtps2qq(Mirtille_VirtualMachine *me);
void me_op_vcvtps2udq(Mirtille_VirtualMachine *me);
void me_op_vcvtps2uqq(Mirtille_VirtualMachine *me);
void me_op_vcvtqq2pd(Mirtille_VirtualMachine *me);
void me_op_vcvtqq2ph(Mirtille_VirtualMachine *me);
void me_op_vcvtqq2ps(Mirtille_VirtualMachine *me);
void me_op_vcvtsd2sh(Mirtille_VirtualMachine *me);
void me_op_vcvtsd2usi(Mirtille_VirtualMachine *me);
void me_op_vcvtsh2sd(Mirtille_VirtualMachine *me);
void me_op_vcvtsh2si(Mirtille_VirtualMachine *me);
void me_op_vcvtsh2ss(Mirtille_VirtualMachine *me);
void me_op_vcvtsh2usi(Mirtille_VirtualMachine *me);
void me_op_vcvtsi2sh(Mirtille_VirtualMachine *me);
void me_op_vcvtss2sh(Mirtille_VirtualMachine *me);
void me_op_vcvtss2usi(Mirtille_VirtualMachine *me);
void me_op_vcvttpd2qq(Mirtille_VirtualMachine *me);
void me_op_vcvttpd2udq(Mirtille_VirtualMachine *me);
void me_op_vcvttpd2uqq(Mirtille_VirtualMachine *me);
void me_op_vcvttph2dq(Mirtille_VirtualMachine *me);
void me_op_vcvttph2qq(Mirtille_VirtualMachine *me);
void me_op_vcvttph2udq(Mirtille_VirtualMachine *me);
void me_op_vcvttph2uqq(Mirtille_VirtualMachine *me);
void me_op_vcvttph2uw(Mirtille_VirtualMachine *me);
void me_op_vcvttph2w(Mirtille_VirtualMachine *me);
void me_op_vcvttps2qq(Mirtille_VirtualMachine *me);
void me_op_vcvttps2udq(Mirtille_VirtualMachine *me);
void me_op_vcvttps2uqq(Mirtille_VirtualMachine *me);
void me_op_vcvttsd2usi(Mirtille_VirtualMachine *me);
void me_op_vcvttsh2si(Mirtille_VirtualMachine *me);
void me_op_vcvttsh2usi(Mirtille_VirtualMachine *me);
void me_op_vcvttss2usi(Mirtille_VirtualMachine *me);
void me_op_vcvtudq2pd(Mirtille_VirtualMachine *me);
void me_op_vcvtudq2ph(Mirtille_VirtualMachine *me);
void me_op_vcvtudq2ps(Mirtille_VirtualMachine *me);
void me_op_vcvtuqq2pd(Mirtille_VirtualMachine *me);
void me_op_vcvtuqq2ph(Mirtille_VirtualMachine *me);
void me_op_vcvtuqq2ps(Mirtille_VirtualMachine *me);
void me_op_vcvtusi2sd(Mirtille_VirtualMachine *me);
void me_op_vcvtusi2sh(Mirtille_VirtualMachine *me);
void me_op_vcvtusi2ss(Mirtille_VirtualMachine *me);
void me_op_vcvtuw2ph(Mirtille_VirtualMachine *me);
void me_op_vcvtw2ph(Mirtille_VirtualMachine *me);
void me_op_vdbpsadbw(Mirtille_VirtualMachine *me);
void me_op_vdivph(Mirtille_VirtualMachine *me);
void me_op_vdivsh(Mirtille_VirtualMachine *me);
void me_op_vdpbf16ps(Mirtille_VirtualMachine *me);

void me_op_verr(Mirtille_VirtualMachine *me);
void me_op_verw(Mirtille_VirtualMachine *me);

void me_op_vexpandpd(Mirtille_VirtualMachine *me);
void me_op_vexpandps(Mirtille_VirtualMachine *me);
void me_op_vextractf128(Mirtille_VirtualMachine *me);
void me_op_vextractf32x4(Mirtille_VirtualMachine *me);
void me_op_vextractf32x8(Mirtille_VirtualMachine *me);
void me_op_vextractf64x2(Mirtille_VirtualMachine *me);
void me_op_vextractf64x4(Mirtille_VirtualMachine *me);
void me_op_vextracti128(Mirtille_VirtualMachine *me);
void me_op_vextracti32x4(Mirtille_VirtualMachine *me);
void me_op_vextracti32x8(Mirtille_VirtualMachine *me);
void me_op_vextracti64x2(Mirtille_VirtualMachine *me);
void me_op_vextracti64x4(Mirtille_VirtualMachine *me);

void me_op_vfcmaddcph(Mirtille_VirtualMachine *me);
void me_op_vfcmaddcsh(Mirtille_VirtualMachine *me);
void me_op_vfcmulcph(Mirtille_VirtualMachine *me);
void me_op_vfcmulcsh(Mirtille_VirtualMachine *me);

void me_op_vfixupimmpd(Mirtille_VirtualMachine *me);
void me_op_vfixupimmps(Mirtille_VirtualMachine *me);
void me_op_vfixupimmsd(Mirtille_VirtualMachine *me);
void me_op_vfixupimmss(Mirtille_VirtualMachine *me);
void me_op_vfmadd132pd(Mirtille_VirtualMachine *me);
void me_op_vfmadd132ph(Mirtille_VirtualMachine *me);
void me_op_vfmadd132ps(Mirtille_VirtualMachine *me);
void me_op_vfmadd132sd(Mirtille_VirtualMachine *me);
void me_op_vfmadd132sh(Mirtille_VirtualMachine *me);
void me_op_vfmadd132ss(Mirtille_VirtualMachine *me);
void me_op_vfmadd213pd(Mirtille_VirtualMachine *me);
void me_op_vfmadd213ph(Mirtille_VirtualMachine *me);
void me_op_vfmadd213ps(Mirtille_VirtualMachine *me);
void me_op_vfmadd213sd(Mirtille_VirtualMachine *me);
void me_op_vfmadd213sh(Mirtille_VirtualMachine *me);
void me_op_vfmadd213ss(Mirtille_VirtualMachine *me);
void me_op_vfmadd231pd(Mirtille_VirtualMachine *me);
void me_op_vfmadd231ph(Mirtille_VirtualMachine *me);
void me_op_vfmadd231ps(Mirtille_VirtualMachine *me);
void me_op_vfmadd231sd(Mirtille_VirtualMachine *me);
void me_op_vfmadd231sh(Mirtille_VirtualMachine *me);
void me_op_vfmadd231ss(Mirtille_VirtualMachine *me);

void me_op_vfmaddcph(Mirtille_VirtualMachine *me);
void me_op_vfmaddcsh(Mirtille_VirtualMachine *me);

void me_op_vfmaddrnd231pd(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub132pd(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub132ph(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub132ps(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub213pd(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub213ph(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub213ps(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub231pd(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub231ph(Mirtille_VirtualMachine *me);
void me_op_vfmaddsub231ps(Mirtille_VirtualMachine *me);

void me_op_vfmsub132pd(Mirtille_VirtualMachine *me);
void me_op_vfmsub132ph(Mirtille_VirtualMachine *me);
void me_op_vfmsub132ps(Mirtille_VirtualMachine *me);
void me_op_vfmsub132sd(Mirtille_VirtualMachine *me);
void me_op_vfmsub132sh(Mirtille_VirtualMachine *me);
void me_op_vfmsub132ss(Mirtille_VirtualMachine *me);
void me_op_vfmsub213pd(Mirtille_VirtualMachine *me);
void me_op_vfmsub213ph(Mirtille_VirtualMachine *me);
void me_op_vfmsub213ps(Mirtille_VirtualMachine *me);
void me_op_vfmsub213sd(Mirtille_VirtualMachine *me);
void me_op_vfmsub213sh(Mirtille_VirtualMachine *me);
void me_op_vfmsub213ss(Mirtille_VirtualMachine *me);
void me_op_vfmsub231pd(Mirtille_VirtualMachine *me);
void me_op_vfmsub231ph(Mirtille_VirtualMachine *me);
void me_op_vfmsub231ps(Mirtille_VirtualMachine *me);
void me_op_vfmsub231sd(Mirtille_VirtualMachine *me);
void me_op_vfmsub231sh(Mirtille_VirtualMachine *me);
void me_op_vfmsub231ss(Mirtille_VirtualMachine *me);

void me_op_vfmsubadd132pd(Mirtille_VirtualMachine *me);
void me_op_vfmsubadd132ph(Mirtille_VirtualMachine *me);
void me_op_vfmsubadd132ps(Mirtille_VirtualMachine *me);
void me_op_vfmsubadd213pd(Mirtille_VirtualMachine *me);
void me_op_vfmsubadd213ph(Mirtille_VirtualMachine *me);
void me_op_vfmsubadd213ps(Mirtille_VirtualMachine *me);
void me_op_vfmsubadd231pd(Mirtille_VirtualMachine *me);
void me_op_vfmsubadd231ph(Mirtille_VirtualMachine *me);
void me_op_vfmsubadd231ps(Mirtille_VirtualMachine *me);

void me_op_vfmulcph(Mirtille_VirtualMachine *me);
void me_op_vfmulcsh(Mirtille_VirtualMachine *me);

void me_op_vfnmadd132pd(Mirtille_VirtualMachine *me);
void me_op_vfnmadd132ph(Mirtille_VirtualMachine *me);
void me_op_vfnmadd132ps(Mirtille_VirtualMachine *me);
void me_op_vfnmadd132sd(Mirtille_VirtualMachine *me);
void me_op_vfnmadd132sh(Mirtille_VirtualMachine *me);
void me_op_vfnmadd132ss(Mirtille_VirtualMachine *me);
void me_op_vfnmadd213pd(Mirtille_VirtualMachine *me);
void me_op_vfnmadd213ph(Mirtille_VirtualMachine *me);
void me_op_vfnmadd213ps(Mirtille_VirtualMachine *me);
void me_op_vfnmadd213sd(Mirtille_VirtualMachine *me);
void me_op_vfnmadd213sh(Mirtille_VirtualMachine *me);
void me_op_vfnmadd213ss(Mirtille_VirtualMachine *me);
void me_op_vfnmadd231pd(Mirtille_VirtualMachine *me);
void me_op_vfnmadd231ph(Mirtille_VirtualMachine *me);
void me_op_vfnmadd231ps(Mirtille_VirtualMachine *me);
void me_op_vfnmadd231sd(Mirtille_VirtualMachine *me);
void me_op_vfnmadd231sh(Mirtille_VirtualMachine *me);
void me_op_vfnmadd231ss(Mirtille_VirtualMachine *me);
void me_op_vfnmsub132pd(Mirtille_VirtualMachine *me);
void me_op_vfnmsub132ph(Mirtille_VirtualMachine *me);
void me_op_vfnmsub132ps(Mirtille_VirtualMachine *me);
void me_op_vfnmsub132sd(Mirtille_VirtualMachine *me);
void me_op_vfnmsub132sh(Mirtille_VirtualMachine *me);
void me_op_vfnmsub132ss(Mirtille_VirtualMachine *me);
void me_op_vfnmsub213pd(Mirtille_VirtualMachine *me);
void me_op_vfnmsub213ph(Mirtille_VirtualMachine *me);
void me_op_vfnmsub213ps(Mirtille_VirtualMachine *me);
void me_op_vfnmsub213sd(Mirtille_VirtualMachine *me);
void me_op_vfnmsub213sh(Mirtille_VirtualMachine *me);
void me_op_vfnmsub213ss(Mirtille_VirtualMachine *me);
void me_op_vfnmsub231pd(Mirtille_VirtualMachine *me);
void me_op_vfnmsub231ph(Mirtille_VirtualMachine *me);
void me_op_vfnmsub231ps(Mirtille_VirtualMachine *me);
void me_op_vfnmsub231sd(Mirtille_VirtualMachine *me);
void me_op_vfnmsub231sh(Mirtille_VirtualMachine *me);
void me_op_vfnmsub231ss(Mirtille_VirtualMachine *me);
void me_op_vfpclasspd(Mirtille_VirtualMachine *me);
void me_op_vfpclassph(Mirtille_VirtualMachine *me);
void me_op_vfpclassps(Mirtille_VirtualMachine *me);
void me_op_vfpclasssd(Mirtille_VirtualMachine *me);
void me_op_vfpclasssh(Mirtille_VirtualMachine *me);
void me_op_vfpclassss(Mirtille_VirtualMachine *me);
void me_op_vgatherdpd(Mirtille_VirtualMachine *me);
void me_op_vgatherdpd(Mirtille_VirtualMachine *me);
void me_op_vgatherdps(Mirtille_VirtualMachine *me);
void me_op_vgatherdps(Mirtille_VirtualMachine *me);
void me_op_vgatherqpd(Mirtille_VirtualMachine *me);
void me_op_vgatherqpd(Mirtille_VirtualMachine *me);
void me_op_vgatherqps(Mirtille_VirtualMachine *me);
void me_op_vgatherqps(Mirtille_VirtualMachine *me);
void me_op_vgetexppd(Mirtille_VirtualMachine *me);
void me_op_vgetexpph(Mirtille_VirtualMachine *me);
void me_op_vgetexpps(Mirtille_VirtualMachine *me);
void me_op_vgetexpsd(Mirtille_VirtualMachine *me);
void me_op_vgetexpsh(Mirtille_VirtualMachine *me);
void me_op_vgetexpss(Mirtille_VirtualMachine *me);
void me_op_vgetmantpd(Mirtille_VirtualMachine *me);
void me_op_vgetmantph(Mirtille_VirtualMachine *me);
void me_op_vgetmantps(Mirtille_VirtualMachine *me);
void me_op_vgetmantsd(Mirtille_VirtualMachine *me);
void me_op_vgetmantsh(Mirtille_VirtualMachine *me);
void me_op_vgetmantss(Mirtille_VirtualMachine *me);
void me_op_vinsertf128(Mirtille_VirtualMachine *me);
void me_op_vinsertf32x4(Mirtille_VirtualMachine *me);
void me_op_vinsertf32x8(Mirtille_VirtualMachine *me);
void me_op_vinsertf64x2(Mirtille_VirtualMachine *me);
void me_op_vinsertf64x4(Mirtille_VirtualMachine *me);
void me_op_vinserti128(Mirtille_VirtualMachine *me);
void me_op_vinserti32x4(Mirtille_VirtualMachine *me);
void me_op_vinserti32x8(Mirtille_VirtualMachine *me);
void me_op_vinserti64x2(Mirtille_VirtualMachine *me);
void me_op_vinserti64x4(Mirtille_VirtualMachine *me);
void me_op_vmaskmov(Mirtille_VirtualMachine *me);
void me_op_vmaxph(Mirtille_VirtualMachine *me);
void me_op_vmaxsh(Mirtille_VirtualMachine *me);
void me_op_vminph(Mirtille_VirtualMachine *me);
void me_op_vminsh(Mirtille_VirtualMachine *me);
void me_op_vmovdqa32(Mirtille_VirtualMachine *me);
void me_op_vmovdqa64(Mirtille_VirtualMachine *me);
void me_op_vmovdqu16(Mirtille_VirtualMachine *me);
void me_op_vmovdqu32(Mirtille_VirtualMachine *me);
void me_op_vmovdqu64(Mirtille_VirtualMachine *me);
void me_op_vmovdqu8(Mirtille_VirtualMachine *me);
void me_op_vmovsh(Mirtille_VirtualMachine *me);
void me_op_vmovw(Mirtille_VirtualMachine *me);
void me_op_vmulph(Mirtille_VirtualMachine *me);
void me_op_vmulsh(Mirtille_VirtualMachine *me);
void me_op_vp2intersectd(Mirtille_VirtualMachine *me);
void me_op_vp2intersectq(Mirtille_VirtualMachine *me);
void me_op_vpblendd(Mirtille_VirtualMachine *me);
void me_op_vpblendmb(Mirtille_VirtualMachine *me);
void me_op_vpblendmd(Mirtille_VirtualMachine *me);
void me_op_vpblendmq(Mirtille_VirtualMachine *me);
void me_op_vpblendmw(Mirtille_VirtualMachine *me);
void me_op_vpbroadcast(Mirtille_VirtualMachine *me);
void me_op_vpbroadcastb(Mirtille_VirtualMachine *me);
void me_op_vpbroadcastd(Mirtille_VirtualMachine *me);
void me_op_vpbroadcastm(Mirtille_VirtualMachine *me);
void me_op_vpbroadcastq(Mirtille_VirtualMachine *me);
void me_op_vpbroadcastw(Mirtille_VirtualMachine *me);
void me_op_vpcmpb(Mirtille_VirtualMachine *me);
void me_op_vpcmpd(Mirtille_VirtualMachine *me);
void me_op_vpcmpq(Mirtille_VirtualMachine *me);
void me_op_vpcmpub(Mirtille_VirtualMachine *me);
void me_op_vpcmpud(Mirtille_VirtualMachine *me);
void me_op_vpcmpuq(Mirtille_VirtualMachine *me);
void me_op_vpcmpuw(Mirtille_VirtualMachine *me);
void me_op_vpcmpw(Mirtille_VirtualMachine *me);
void me_op_vpcompressb(Mirtille_VirtualMachine *me);
void me_op_vpcompressd(Mirtille_VirtualMachine *me);
void me_op_vpcompressq(Mirtille_VirtualMachine *me);
void me_op_vpconflictd(Mirtille_VirtualMachine *me);
void me_op_vpconflictq(Mirtille_VirtualMachine *me);
void me_op_vpdpbusd(Mirtille_VirtualMachine *me);
void me_op_vpdpbusds(Mirtille_VirtualMachine *me);
void me_op_vpdpwssd(Mirtille_VirtualMachine *me);
void me_op_vpdpwssds(Mirtille_VirtualMachine *me);
void me_op_vperm2f128(Mirtille_VirtualMachine *me);
void me_op_vperm2i128(Mirtille_VirtualMachine *me);
void me_op_vpermb(Mirtille_VirtualMachine *me);
void me_op_vpermd(Mirtille_VirtualMachine *me);
void me_op_vpermi2b(Mirtille_VirtualMachine *me);
void me_op_vpermi2d(Mirtille_VirtualMachine *me);
void me_op_vpermi2pd(Mirtille_VirtualMachine *me);
void me_op_vpermi2ps(Mirtille_VirtualMachine *me);
void me_op_vpermi2q(Mirtille_VirtualMachine *me);
void me_op_vpermi2w(Mirtille_VirtualMachine *me);
void me_op_vpermilpd(Mirtille_VirtualMachine *me);
void me_op_vpermilps(Mirtille_VirtualMachine *me);
void me_op_vpermpd(Mirtille_VirtualMachine *me);
void me_op_vpermps(Mirtille_VirtualMachine *me);
void me_op_vpermq(Mirtille_VirtualMachine *me);
void me_op_vpermt2b(Mirtille_VirtualMachine *me);
void me_op_vpermt2d(Mirtille_VirtualMachine *me);
void me_op_vpermt2pd(Mirtille_VirtualMachine *me);
void me_op_vpermt2ps(Mirtille_VirtualMachine *me);
void me_op_vpermt2q(Mirtille_VirtualMachine *me);
void me_op_vpermt2w(Mirtille_VirtualMachine *me);
void me_op_vpermw(Mirtille_VirtualMachine *me);
void me_op_vpexpandb(Mirtille_VirtualMachine *me);
void me_op_vpexpandd(Mirtille_VirtualMachine *me);
void me_op_vpexpandq(Mirtille_VirtualMachine *me);
void me_op_vpexpandw(Mirtille_VirtualMachine *me);
void me_op_vpgatherdd(Mirtille_VirtualMachine *me);
void me_op_vpgatherdd(Mirtille_VirtualMachine *me);
void me_op_vpgatherdq(Mirtille_VirtualMachine *me);
void me_op_vpgatherdq(Mirtille_VirtualMachine *me);
void me_op_vpgatherqd(Mirtille_VirtualMachine *me);
void me_op_vpgatherqd(Mirtille_VirtualMachine *me);
void me_op_vpgatherqq(Mirtille_VirtualMachine *me);
void me_op_vpgatherqq(Mirtille_VirtualMachine *me);
void me_op_vplzcntd(Mirtille_VirtualMachine *me);
void me_op_vplzcntq(Mirtille_VirtualMachine *me);
void me_op_vpmadd52huq(Mirtille_VirtualMachine *me);
void me_op_vpmadd52luq(Mirtille_VirtualMachine *me);
void me_op_vpmaskmov(Mirtille_VirtualMachine *me);
void me_op_vpmovb2m(Mirtille_VirtualMachine *me);
void me_op_vpmovd2m(Mirtille_VirtualMachine *me);
void me_op_vpmovdb(Mirtille_VirtualMachine *me);
void me_op_vpmovdw(Mirtille_VirtualMachine *me);
void me_op_vpmovm2b(Mirtille_VirtualMachine *me);
void me_op_vpmovm2d(Mirtille_VirtualMachine *me);
void me_op_vpmovm2q(Mirtille_VirtualMachine *me);
void me_op_vpmovm2w(Mirtille_VirtualMachine *me);
void me_op_vpmovq2m(Mirtille_VirtualMachine *me);
void me_op_vpmovqb(Mirtille_VirtualMachine *me);
void me_op_vpmovqd(Mirtille_VirtualMachine *me);
void me_op_vpmovqw(Mirtille_VirtualMachine *me);
void me_op_vpmovsdb(Mirtille_VirtualMachine *me);
void me_op_vpmovsdw(Mirtille_VirtualMachine *me);
void me_op_vpmovsqb(Mirtille_VirtualMachine *me);
void me_op_vpmovsqd(Mirtille_VirtualMachine *me);
void me_op_vpmovsqw(Mirtille_VirtualMachine *me);
void me_op_vpmovswb(Mirtille_VirtualMachine *me);
void me_op_vpmovusdb(Mirtille_VirtualMachine *me);
void me_op_vpmovusdw(Mirtille_VirtualMachine *me);
void me_op_vpmovusqb(Mirtille_VirtualMachine *me);
void me_op_vpmovusqd(Mirtille_VirtualMachine *me);
void me_op_vpmovusqw(Mirtille_VirtualMachine *me);
void me_op_vpmovuswb(Mirtille_VirtualMachine *me);
void me_op_vpmovw2m(Mirtille_VirtualMachine *me);
void me_op_vpmovwb(Mirtille_VirtualMachine *me);
void me_op_vpmultishiftqb(Mirtille_VirtualMachine *me);
void me_op_vpopcnt(Mirtille_VirtualMachine *me);
void me_op_vprold(Mirtille_VirtualMachine *me);
void me_op_vprolq(Mirtille_VirtualMachine *me);
void me_op_vprolvd(Mirtille_VirtualMachine *me);
void me_op_vprolvq(Mirtille_VirtualMachine *me);
void me_op_vprord(Mirtille_VirtualMachine *me);
void me_op_vprorq(Mirtille_VirtualMachine *me);
void me_op_vprorvd(Mirtille_VirtualMachine *me);
void me_op_vprorvq(Mirtille_VirtualMachine *me);
void me_op_vpscatterdd(Mirtille_VirtualMachine *me);
void me_op_vpscatterdq(Mirtille_VirtualMachine *me);
void me_op_vpscatterqd(Mirtille_VirtualMachine *me);
void me_op_vpscatterqq(Mirtille_VirtualMachine *me);
void me_op_vpshld(Mirtille_VirtualMachine *me);
void me_op_vpshldv(Mirtille_VirtualMachine *me);
void me_op_vpshrd(Mirtille_VirtualMachine *me);
void me_op_vpshrdv(Mirtille_VirtualMachine *me);
void me_op_vpshufbitqmb(Mirtille_VirtualMachine *me);
void me_op_vpsllvd(Mirtille_VirtualMachine *me);
void me_op_vpsllvq(Mirtille_VirtualMachine *me);
void me_op_vpsllvw(Mirtille_VirtualMachine *me);
void me_op_vpsravd(Mirtille_VirtualMachine *me);
void me_op_vpsravq(Mirtille_VirtualMachine *me);
void me_op_vpsravw(Mirtille_VirtualMachine *me);
void me_op_vpsrlvd(Mirtille_VirtualMachine *me);
void me_op_vpsrlvq(Mirtille_VirtualMachine *me);
void me_op_vpsrlvw(Mirtille_VirtualMachine *me);
void me_op_vpternlogd(Mirtille_VirtualMachine *me);
void me_op_vpternlogq(Mirtille_VirtualMachine *me);
void me_op_vptestmb(Mirtille_VirtualMachine *me);
void me_op_vptestmd(Mirtille_VirtualMachine *me);
void me_op_vptestmq(Mirtille_VirtualMachine *me);
void me_op_vptestmw(Mirtille_VirtualMachine *me);
void me_op_vptestnmb(Mirtille_VirtualMachine *me);
void me_op_vptestnmd(Mirtille_VirtualMachine *me);
void me_op_vptestnmq(Mirtille_VirtualMachine *me);
void me_op_vptestnmw(Mirtille_VirtualMachine *me);
void me_op_vrangepd(Mirtille_VirtualMachine *me);
void me_op_vrangeps(Mirtille_VirtualMachine *me);
void me_op_vrangesd(Mirtille_VirtualMachine *me);
void me_op_vrangess(Mirtille_VirtualMachine *me);
void me_op_vrcp14pd(Mirtille_VirtualMachine *me);
void me_op_vrcp14ps(Mirtille_VirtualMachine *me);
void me_op_vrcp14sd(Mirtille_VirtualMachine *me);
void me_op_vrcp14ss(Mirtille_VirtualMachine *me);
void me_op_vrcpph(Mirtille_VirtualMachine *me);
void me_op_vrcpsh(Mirtille_VirtualMachine *me);
void me_op_vreducepd(Mirtille_VirtualMachine *me);
void me_op_vreduceph(Mirtille_VirtualMachine *me);
void me_op_vreduceps(Mirtille_VirtualMachine *me);
void me_op_vreducesd(Mirtille_VirtualMachine *me);
void me_op_vreducesh(Mirtille_VirtualMachine *me);
void me_op_vreducess(Mirtille_VirtualMachine *me);
void me_op_vrndscalepd(Mirtille_VirtualMachine *me);
void me_op_vrndscaleph(Mirtille_VirtualMachine *me);
void me_op_vrndscaleps(Mirtille_VirtualMachine *me);
void me_op_vrndscalesd(Mirtille_VirtualMachine *me);
void me_op_vrndscalesh(Mirtille_VirtualMachine *me);
void me_op_vrndscaless(Mirtille_VirtualMachine *me);
void me_op_vrsqrt14pd(Mirtille_VirtualMachine *me);
void me_op_vrsqrt14ps(Mirtille_VirtualMachine *me);
void me_op_vrsqrt14sd(Mirtille_VirtualMachine *me);
void me_op_vrsqrt14ss(Mirtille_VirtualMachine *me);
void me_op_vrsqrtph(Mirtille_VirtualMachine *me);
void me_op_vrsqrtsh(Mirtille_VirtualMachine *me);
void me_op_vscalefpd(Mirtille_VirtualMachine *me);
void me_op_vscalefph(Mirtille_VirtualMachine *me);
void me_op_vscalefps(Mirtille_VirtualMachine *me);
void me_op_vscalefsd(Mirtille_VirtualMachine *me);
void me_op_vscalefsh(Mirtille_VirtualMachine *me);
void me_op_vscalefss(Mirtille_VirtualMachine *me);
void me_op_vscatterdpd(Mirtille_VirtualMachine *me);
void me_op_vscatterdps(Mirtille_VirtualMachine *me);
void me_op_vscatterqpd(Mirtille_VirtualMachine *me);
void me_op_vscatterqps(Mirtille_VirtualMachine *me);
void me_op_vshuff32x4(Mirtille_VirtualMachine *me);
void me_op_vshuff64x2(Mirtille_VirtualMachine *me);
void me_op_vshufi32x4(Mirtille_VirtualMachine *me);
void me_op_vshufi64x2(Mirtille_VirtualMachine *me);
void me_op_vsqrtph(Mirtille_VirtualMachine *me);
void me_op_vsqrtsh(Mirtille_VirtualMachine *me);
void me_op_vsubph(Mirtille_VirtualMachine *me);
void me_op_vsubsh(Mirtille_VirtualMachine *me);
void me_op_vtestpd(Mirtille_VirtualMachine *me);
void me_op_vtestps(Mirtille_VirtualMachine *me);
void me_op_vucomish(Mirtille_VirtualMachine *me);
void me_op_vzeroall(Mirtille_VirtualMachine *me);
void me_op_vzeroupper(Mirtille_VirtualMachine *me);
void me_op_wait(Mirtille_VirtualMachine *me);
void me_op_wbinvd(Mirtille_VirtualMachine *me);
void me_op_wbnoinvd(Mirtille_VirtualMachine *me);
void me_op_wrfsbase(Mirtille_VirtualMachine *me);
void me_op_wrgsbase(Mirtille_VirtualMachine *me);
void me_op_wrmsr(Mirtille_VirtualMachine *me);
void me_op_wrpkru(Mirtille_VirtualMachine *me);
void me_op_wrssd(Mirtille_VirtualMachine *me);
void me_op_wrssq(Mirtille_VirtualMachine *me);
void me_op_wrussd(Mirtille_VirtualMachine *me);
void me_op_wrussq(Mirtille_VirtualMachine *me);
void me_op_xabort(Mirtille_VirtualMachine *me);
void me_op_xacquire(Mirtille_VirtualMachine *me);
void me_op_xadd(Mirtille_VirtualMachine *me);
void me_op_xbegin(Mirtille_VirtualMachine *me);
void me_op_xchg(Mirtille_VirtualMachine *me);
void me_op_xend(Mirtille_VirtualMachine *me);
void me_op_xgetbv(Mirtille_VirtualMachine *me);
void me_op_xlat(Mirtille_VirtualMachine *me);
void me_op_xlatb(Mirtille_VirtualMachine *me);
void me_op_xor(Mirtille_VirtualMachine *me);
void me_op_xorpd(Mirtille_VirtualMachine *me);
void me_op_xorps(Mirtille_VirtualMachine *me);
void me_op_xrelease(Mirtille_VirtualMachine *me);
void me_op_xresldtrk(Mirtille_VirtualMachine *me);
void me_op_xrstor(Mirtille_VirtualMachine *me);
void me_op_xrstors(Mirtille_VirtualMachine *me);
void me_op_xsave(Mirtille_VirtualMachine *me);
void me_op_xsavec(Mirtille_VirtualMachine *me);
void me_op_xsaveopt(Mirtille_VirtualMachine *me);
void me_op_xsaves(Mirtille_VirtualMachine *me);
void me_op_xsetbv(Mirtille_VirtualMachine *me);
void me_op_xsusldtrk(Mirtille_VirtualMachine *me);
void me_op_xtest(Mirtille_VirtualMachine *me);
void me_op_sgx(Mirtille_VirtualMachine *me);


void me_op_encls(Mirtille_VirtualMachine *me);
void me_op_encls_eadd_(Mirtille_VirtualMachine *me);
void me_op_encls_eaug_(Mirtille_VirtualMachine *me);
void me_op_encls_eblock_(Mirtille_VirtualMachine *me);
void me_op_encls_ecreate_(Mirtille_VirtualMachine *me);
void me_op_encls_edbgrd_(Mirtille_VirtualMachine *me);
void me_op_encls_edbgwr_(Mirtille_VirtualMachine *me);
void me_op_encls_eextend_(Mirtille_VirtualMachine *me);
void me_op_encls_einit_(Mirtille_VirtualMachine *me);
void me_op_encls_eldbc_(Mirtille_VirtualMachine *me);
void me_op_encls_eldb_(Mirtille_VirtualMachine *me);
void me_op_encls_elduc_(Mirtille_VirtualMachine *me);
void me_op_encls_eldu_(Mirtille_VirtualMachine *me);
void me_op_encls_emodpr_(Mirtille_VirtualMachine *me);
void me_op_encls_emodt_(Mirtille_VirtualMachine *me);
void me_op_encls_epa_(Mirtille_VirtualMachine *me);
void me_op_encls_erdinfo_(Mirtille_VirtualMachine *me);
void me_op_encls_eremove_(Mirtille_VirtualMachine *me);
void me_op_encls_etrackc_(Mirtille_VirtualMachine *me);
void me_op_encls_etrack_(Mirtille_VirtualMachine *me);
void me_op_encls_ewb_(Mirtille_VirtualMachine *me);
void me_op_enclu(Mirtille_VirtualMachine *me);
void me_op_enclu_eacceptcopy_(Mirtille_VirtualMachine *me);
void me_op_enclu_eaccept_(Mirtille_VirtualMachine *me);
void me_op_enclu_edeccssa_(Mirtille_VirtualMachine *me);
void me_op_enclu_eenter_(Mirtille_VirtualMachine *me);
void me_op_enclu_eexit_(Mirtille_VirtualMachine *me);
void me_op_enclu_egetkey_(Mirtille_VirtualMachine *me);
void me_op_enclu_emodpe_(Mirtille_VirtualMachine *me);
void me_op_enclu_ereport_(Mirtille_VirtualMachine *me);
void me_op_enclu_eresume_(Mirtille_VirtualMachine *me);
void me_op_enclv(Mirtille_VirtualMachine *me);
void me_op_enclv_edecvirtchild_(Mirtille_VirtualMachine *me);
void me_op_enclv_eincvirtchild_(Mirtille_VirtualMachine *me);
void me_op_enclv_esetcontext_(Mirtille_VirtualMachine *me);
void me_op_smx(Mirtille_VirtualMachine *me);


void me_op_getsec_capabilities_(Mirtille_VirtualMachine *me);
void me_op_getsec_enteraccs_(Mirtille_VirtualMachine *me);
void me_op_getsec_exitac_(Mirtille_VirtualMachine *me);
void me_op_getsec_parameters_(Mirtille_VirtualMachine *me);
void me_op_getsec_senter_(Mirtille_VirtualMachine *me);
void me_op_getsec_sexit_(Mirtille_VirtualMachine *me);
void me_op_getsec_smctrl_(Mirtille_VirtualMachine *me);
void me_op_getsec_wakeup_(Mirtille_VirtualMachine *me);
void me_op_vmx(Mirtille_VirtualMachine *me);


void me_op_invept(Mirtille_VirtualMachine *me);
void me_op_invvpid(Mirtille_VirtualMachine *me);
void me_op_vmcall(Mirtille_VirtualMachine *me);
void me_op_vmclear(Mirtille_VirtualMachine *me);
void me_op_vmfunc(Mirtille_VirtualMachine *me);
void me_op_vmlaunch(Mirtille_VirtualMachine *me);
void me_op_vmptrld(Mirtille_VirtualMachine *me);
void me_op_vmptrst(Mirtille_VirtualMachine *me);
void me_op_vmread(Mirtille_VirtualMachine *me);
void me_op_vmresume(Mirtille_VirtualMachine *me);
void me_op_vmresume(Mirtille_VirtualMachine *me);
void me_op_vmwrite(Mirtille_VirtualMachine *me);
void me_op_vmxoff(Mirtille_VirtualMachine *me);
void me_op_vmxon(Mirtille_VirtualMachine *me);

void me_op_prefetchwt1(Mirtille_VirtualMachine *me);
void me_op_v4fmaddps(Mirtille_VirtualMachine *me);
void me_op_v4fmaddss(Mirtille_VirtualMachine *me);
void me_op_v4fnmaddps(Mirtille_VirtualMachine *me);
void me_op_v4fnmaddss(Mirtille_VirtualMachine *me);
void me_op_vexp2pd(Mirtille_VirtualMachine *me);
void me_op_vexp2ps(Mirtille_VirtualMachine *me);
void me_op_vgatherpf0dpd(Mirtille_VirtualMachine *me);
void me_op_vgatherpf0dps(Mirtille_VirtualMachine *me);
void me_op_vgatherpf0qpd(Mirtille_VirtualMachine *me);
void me_op_vgatherpf0qps(Mirtille_VirtualMachine *me);
void me_op_vgatherpf1dpd(Mirtille_VirtualMachine *me);
void me_op_vgatherpf1dps(Mirtille_VirtualMachine *me);
void me_op_vgatherpf1qpd(Mirtille_VirtualMachine *me);
void me_op_vgatherpf1qps(Mirtille_VirtualMachine *me);
void me_op_vp4dpwssd(Mirtille_VirtualMachine *me);
void me_op_vp4dpwssds(Mirtille_VirtualMachine *me);
void me_op_vrcp28pd(Mirtille_VirtualMachine *me);
void me_op_vrcp28ps(Mirtille_VirtualMachine *me);
void me_op_vrcp28sd(Mirtille_VirtualMachine *me);
void me_op_vrcp28ss(Mirtille_VirtualMachine *me);
void me_op_vrsqrt28pd(Mirtille_VirtualMachine *me);
void me_op_vrsqrt28ps(Mirtille_VirtualMachine *me);
void me_op_vrsqrt28sd(Mirtille_VirtualMachine *me);
void me_op_vrsqrt28ss(Mirtille_VirtualMachine *me);
void me_op_vscatterpf0dpd(Mirtille_VirtualMachine *me);
void me_op_vscatterpf0dps(Mirtille_VirtualMachine *me);
void me_op_vscatterpf0qpd(Mirtille_VirtualMachine *me);
void me_op_vscatterpf0qps(Mirtille_VirtualMachine *me);
void me_op_vscatterpf1dpd(Mirtille_VirtualMachine *me);
void me_op_vscatterpf1dps(Mirtille_VirtualMachine *me);
void me_op_vscatterpf1qpd(Mirtille_VirtualMachine *me);
void me_op_vscatterpf1qps(Mirtille_VirtualMachine *me);





#endif