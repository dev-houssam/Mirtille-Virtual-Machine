#include "../include/me_opcode.h"

//https://www.felixcloutier.com/x86/aaa

void me_op_aaa(Mirtille_VirtualMachine *me){
	//AAA — ASCII Adjust After Addition
	/*
	IF 64-Bit Mode
    THEN
        #UD;
    ELSE
        IF ((AL AND 0FH) > 9) or (AF = 1)
            THEN
                AX := AX + 106H;
                AF := 1;
                CF := 1;
            ELSE
                AF := 0;
                CF := 0;
        FI;
        AL := AL AND 0FH;
	FI;
	*/
}


void me_op_aad(Mirtille_VirtualMachine *me){
	//AAD — ASCII Adjust AX Before Division
	/*
	IF 64-Bit Mode
    THEN
        #UD;
    ELSE
        tempAL := AL;
        tempAH := AH;
        AL := (tempAL + (tempAH ∗ imm8)) AND FFH;
        (* imm8 is set to 0AH for the AAD mnemonic.*)
        AH := 0;
	FI;
	The immediate value (imm8) is taken from the second byte of the instruction.

	*/
}


void me_op_aam(Mirtille_VirtualMachine *me){
//AAM — ASCII Adjust AX After Multiply
/*
IF 64-Bit Mode
    THEN
        #UD;
    ELSE
        tempAL := AL;
        AH := tempAL / imm8; (* imm8 is set to 0AH for the AAM mnemonic *)
        AL := tempAL MOD imm8;
FI;
The immediate value (imm8) is taken from the second byte of the instruction.

*/
}


void me_op_aas(Mirtille_VirtualMachine *me){
//AAS — ASCII Adjust AL After Subtraction
/*
IF 64-bit mode
    THEN
        #UD;
    ELSE
        IF ((AL AND 0FH) > 9) or (AF = 1)
            THEN
                AX := AX – 6;
                AH := AH – 1;
                AF := 1;
                CF := 1;
                AL := AL AND 0FH;
            ELSE
                CF := 0;
                AF := 0;
                AL := AL AND 0FH;
        FI;
FI;

*/
}


void me_op_adc(Mirtille_VirtualMachine *me){
//ADC — Add With Carry
/*
DEST := DEST + SRC + CF;
*/
}


void me_op_adcx(Mirtille_VirtualMachine *me){
//ADCX — Unsigned Integer Addition of Two Operands With Carry Flag
/*
IF OperandSize is 64-bit
    THEN CF:DEST[63:0] := DEST[63:0] + SRC[63:0] + CF;
    ELSE CF:DEST[31:0] := DEST[31:0] + SRC[31:0] + CF;
FI;
*/
}


void me_op_add(Mirtille_VirtualMachine *me){
//ADD — Add
/*
DEST := DEST + SRC;
*/
}


void me_op_addpd(Mirtille_VirtualMachine *me){
//ADDPD — Add Packed Double Precision Floating-Point Values
/*
Operation ¶
VADDPD (EVEX Encoded Versions) When SRC2 Operand is a Vector Register ¶

(KL, VL) = (2, 128), (4, 256), (8, 512)
IF (VL = 512) AND (EVEX.b = 1)
    THEN
        SET_ROUNDING_MODE_FOR_THIS_INSTRUCTION(EVEX.RC);
    ELSE
        SET_ROUNDING_MODE_FOR_THIS_INSTRUCTION(MXCSR.RC);
FI;
FOR j := 0 TO KL-1
    i := j * 64
    IF k1[j] OR *no writemask*
        THEN DEST[i+63:i] := SRC1[i+63:i] + SRC2[i+63:i]
        ELSE
            IF *merging-masking* ; merging-masking
                THEN *DEST[i+63:i] remains unchanged*
                ELSE ; zeroing-masking
                    DEST[i+63:i] := 0
            FI
    FI;
ENDFOR
DEST[MAXVL-1:VL] := 0

VADDPD (EVEX Encoded Versions) When SRC2 Operand is a Memory Source ¶

(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j := 0 TO KL-1
    i := j * 64
    IF k1[j] OR *no writemask*
        THEN
            IF (EVEX.b = 1)
                THEN
                    DEST[i+63:i] := SRC1[i+63:i] + SRC2[63:0]
                ELSE
                    DEST[i+63:i] := SRC1[i+63:i] + SRC2[i+63:i]
            FI;
        ELSE
            IF *merging-masking* ; merging-masking
                THEN *DEST[i+63:i] remains unchanged*
                ELSE ; zeroing-masking
                    DEST[i+63:i] := 0
            FI
    FI;
ENDFOR
DEST[MAXVL-1:VL] := 0

VADDPD (VEX.256 Encoded Version) ¶

DEST[63:0] := SRC1[63:0] + SRC2[63:0]
DEST[127:64] := SRC1[127:64] + SRC2[127:64]
DEST[191:128] := SRC1[191:128] + SRC2[191:128]
DEST[255:192] := SRC1[255:192] + SRC2[255:192]
DEST[MAXVL-1:256] := 0
.

VADDPD (VEX.128 Encoded Version) ¶

DEST[63:0] := SRC1[63:0] + SRC2[63:0]
DEST[127:64] := SRC1[127:64] + SRC2[127:64]
DEST[MAXVL-1:128] := 0

ADDPD (128-bit Legacy SSE Version) ¶

DEST[63:0] := DEST[63:0] + SRC[63:0]
DEST[127:64] := DEST[127:64] + SRC[127:64]
DEST[MAXVL-1:128] (Unmodified)

*/
}


void me_op_addps(Mirtille_VirtualMachine *me){
//ADDPS — Add Packed Single Precision Floating-Point Values
/*
Operation ¶
VADDPS (EVEX Encoded Versions) When SRC2 Operand is a Register ¶

(KL, VL) = (4, 128), (8, 256), (16, 512)
IF (VL = 512) AND (EVEX.b = 1)
    THEN
        SET_ROUNDING_MODE_FOR_THIS_INSTRUCTION(EVEX.RC);
    ELSE
        SET_ROUNDING_MODE_FOR_THIS_INSTRUCTION(MXCSR.RC);
FI;
FOR j := 0 TO KL-1
    i := j * 32
    IF k1[j] OR *no writemask*
        THEN DEST[i+31:i] := SRC1[i+31:i] + SRC2[i+31:i]
        ELSE
            IF *merging-masking* ; merging-masking
                THEN *DEST[i+31:i] remains unchanged*
                ELSE ; zeroing-masking
                    DEST[i+31:i] := 0
            FI
    FI;
ENDFOR;
DEST[MAXVL-1:VL] := 0

VADDPS (EVEX Encoded Versions) When SRC2 Operand is a Memory Source ¶

(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j := 0 TO KL-1
    i := j * 32
    IF k1[j] OR *no writemask*
        THEN
            IF (EVEX.b = 1)
                THEN
                    DEST[i+31:i] :=
                        SRC1[i+31:i] + SRC2[31:0]
                ELSE
                    DEST[i+31:i] :=
                        SRC1[i+31:i] + SRC2[i+31:i]
            FI;
        ELSE
            IF *merging-masking*
                            ; merging-masking
                THEN *DEST[i+31:i]
                        remains unchanged*
                ELSE
                            ; zeroing-masking
                    DEST[i+31:i] :=
                        0
            FI
    FI;
ENDFOR;
DEST[MAXVL-1:VL] := 0

VADDPS (VEX.256 Encoded Version) ¶

DEST[31:0] := SRC1[31:0] + SRC2[31:0]
DEST[63:32] := SRC1[63:32] + SRC2[63:32]
DEST[95:64] := SRC1[95:64] + SRC2[95:64]
DEST[127:96] := SRC1[127:96] + SRC2[127:96]
DEST[159:128] := SRC1[159:128] + SRC2[159:128]
DEST[191:160]:= SRC1[191:160] + SRC2[191:160]
DEST[223:192] := SRC1[223:192] + SRC2[223:192]
DEST[255:224] := SRC1[255:224] + SRC2[255:224].
DEST[MAXVL-1:256] := 0

VADDPS (VEX.128 Encoded Version) ¶

DEST[31:0] := SRC1[31:0] + SRC2[31:0]
DEST[63:32] := SRC1[63:32] + SRC2[63:32]
DEST[95:64] := SRC1[95:64] + SRC2[95:64]
DEST[127:96] := SRC1[127:96] + SRC2[127:96]
DEST[MAXVL-1:128] := 0

ADDPS (128-bit Legacy SSE Version) ¶

DEST[31:0] := SRC1[31:0] + SRC2[31:0]
DEST[63:32] := SRC1[63:32] + SRC2[63:32]
DEST[95:64] := SRC1[95:64] + SRC2[95:64]
DEST[127:96] := SRC1[127:96] + SRC2[127:96]
DEST[MAXVL-1:128] (Unmodified)

*/
}


void me_op_addsd(Mirtille_VirtualMachine *me){
//ADDSD — Add Scalar Double Precision Floating-Point Values
/*
Operation ¶
VADDSD (EVEX Encoded Version) ¶

IF (EVEX.b = 1) AND SRC2 *is a register*
    THEN
        SET_ROUNDING_MODE_FOR_THIS_INSTRUCTION(EVEX.RC);
    ELSE
        SET_ROUNDING_MODE_FOR_THIS_INSTRUCTION(MXCSR.RC);
FI;
IF k1[0] or *no writemask*
    THEN DEST[63:0] := SRC1[63:0] + SRC2[63:0]
    ELSE
        IF *merging-masking* ; merging-masking
            THEN *DEST[63:0] remains unchanged*
            ELSE ; zeroing-masking
                THEN DEST[63:0] := 0
        FI;
FI;
DEST[127:64] := SRC1[127:64]
DEST[MAXVL-1:128] := 0

VADDSD (VEX.128 Encoded Version) ¶

DEST[63:0] := SRC1[63:0] + SRC2[63:0]
DEST[127:64] := SRC1[127:64]
DEST[MAXVL-1:128] := 0

ADDSD (128-bit Legacy SSE Version) ¶

DEST[63:0] := DEST[63:0] + SRC[63:0]
DEST[MAXVL-1:64] (Unmodified)

*/
}


void me_op_addss(Mirtille_VirtualMachine *me){
//ADDSS — Add Scalar Single Precision Floating-Point Values
/*
Operation ¶
VADDSS (EVEX Encoded Versions) ¶

IF (EVEX.b = 1) AND SRC2 *is a register*
    THEN
        SET_ROUNDING_MODE_FOR_THIS_INSTRUCTION(EVEX.RC);
    ELSE
        SET_ROUNDING_MODE_FOR_THIS_INSTRUCTION(MXCSR.RC);
FI;
IF k1[0] or *no writemask*
    THEN DEST[31:0] := SRC1[31:0] + SRC2[31:0]
    ELSE
        IF *merging-masking* ; merging-masking
            THEN *DEST[31:0] remains unchanged*
            ELSE ; zeroing-masking
                THEN DEST[31:0] := 0
        FI;
FI;
DEST[127:32] := SRC1[127:32]
DEST[MAXVL-1:128] := 0

VADDSS DEST, SRC1, SRC2 (VEX.128 Encoded Version) ¶

DEST[31:0] := SRC1[31:0] + SRC2[31:0]
DEST[127:32] := SRC1[127:32]
DEST[MAXVL-1:128] := 0

ADDSS DEST, SRC (128-bit Legacy SSE Version) ¶

DEST[31:0] := DEST[31:0] + SRC[31:0]
DEST[MAXVL-1:32] (Unmodified)

*/
}


void me_op_addsubpd(Mirtille_VirtualMachine *me){
//ADDSUBPD — Packed Double Precision Floating-Point Add/Subtract
/*
Operation ¶
ADDSUBPD (128-bit Legacy SSE Version) ¶

DEST[63:0] := DEST[63:0] - SRC[63:0]
DEST[127:64] := DEST[127:64] + SRC[127:64]
DEST[MAXVL-1:128] (Unmodified)

VADDSUBPD (VEX.128 Encoded Version) ¶

DEST[63:0] := SRC1[63:0] - SRC2[63:0]
DEST[127:64] := SRC1[127:64] + SRC2[127:64]
DEST[MAXVL-1:128] := 0

VADDSUBPD (VEX.256 Encoded Version) ¶

DEST[63:0] := SRC1[63:0] - SRC2[63:0]
DEST[127:64] := SRC1[127:64] + SRC2[127:64]
DEST[191:128] := SRC1[191:128] - SRC2[191:128]
DEST[255:192] := SRC1[255:192] + SRC2[255:192]

*/
}


void me_op_addsubps(Mirtille_VirtualMachine *me){
//ADDSUBPS — Packed Single Precision Floating-Point Add/Subtract
/*
Operation ¶
ADDSUBPS (128-bit Legacy SSE Version) ¶

DEST[31:0] := DEST[31:0] - SRC[31:0]
DEST[63:32] := DEST[63:32] + SRC[63:32]
DEST[95:64] := DEST[95:64] - SRC[95:64]
DEST[127:96] := DEST[127:96] + SRC[127:96]
DEST[MAXVL-1:128] (Unmodified)

VADDSUBPS (VEX.128 Encoded Version) ¶

DEST[31:0] := SRC1[31:0] - SRC2[31:0]
DEST[63:32] := SRC1[63:32] + SRC2[63:32]
DEST[95:64] := SRC1[95:64] - SRC2[95:64]
DEST[127:96] := SRC1[127:96] + SRC2[127:96]
DEST[MAXVL-1:128] := 0

VADDSUBPS (VEX.256 Encoded Version) ¶

DEST[31:0] := SRC1[31:0] - SRC2[31:0]
DEST[63:32] := SRC1[63:32] + SRC2[63:32]
DEST[95:64] := SRC1[95:64] - SRC2[95:64]
DEST[127:96] := SRC1[127:96] + SRC2[127:96]
DEST[159:128] := SRC1[159:128] - SRC2[159:128]
DEST[191:160] := SRC1[191:160] + SRC2[191:160]
DEST[223:192] := SRC1[223:192] - SRC2[223:192]
DEST[255:224] := SRC1[255:224] + SRC2[255:224]

*/
}


void me_op_adox(Mirtille_VirtualMachine *me){
//ADOX — Unsigned Integer Addition of Two Operands With Overflow Flag
/*
Operation ¶

IF OperandSize is 64-bit
    THEN OF:DEST[63:0] := DEST[63:0] + SRC[63:0] + OF;
    ELSE OF:DEST[31:0] := DEST[31:0] + SRC[31:0] + OF;
FI;

*/
}


void me_op_aesdec(Mirtille_VirtualMachine *me){
//AESDEC — Perform One Round of an AES Decryption Flow
/*
Operation ¶
AESDEC ¶

STATE := SRC1;
RoundKey := SRC2;
STATE := InvShiftRows( STATE );
STATE := InvSubBytes( STATE );
STATE := InvMixColumns( STATE );
DEST[127:0] := STATE XOR RoundKey;
DEST[MAXVL-1:128] (Unmodified)

VAESDEC (128b and 256b VEX Encoded Versions) ¶

(KL,VL) = (1,128), (2,256)
FOR i = 0 to KL-1:
    STATE := SRC1.xmm[i]
    RoundKey := SRC2.xmm[i]
    STATE := InvShiftRows( STATE )
    STATE := InvSubBytes( STATE )
    STATE := InvMixColumns( STATE )
    DEST.xmm[i] := STATE XOR RoundKey
DEST[MAXVL-1:VL] := 0

VAESDEC (EVEX Encoded Version) ¶

(KL,VL) = (1,128), (2,256), (4,512)
FOR i = 0 to KL-1:
    STATE := SRC1.xmm[i]
    RoundKey := SRC2.xmm[i]
    STATE := InvShiftRows( STATE )
    STATE := InvSubBytes( STATE )
    STATE := InvMixColumns( STATE )
    DEST.xmm[i] := STATE XOR RoundKey
DEST[MAXVL-1:VL] :=0

*/
}


void me_op_aesdec128kl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesdec256kl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesdeclast(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesdecwide128kl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesdecwide256kl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesenc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesenc128kl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesenc256kl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesenclast(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesencwide128kl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesencwide256kl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aesimc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_aeskeygenassist(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_and(Mirtille_VirtualMachine *me){
//AND — Logical AND
/*
Operation ¶

DEST := DEST AND SRC;

*/
}


void me_op_andn(Mirtille_VirtualMachine *me){
//ANDN — Logical AND NOT
/*
Operation ¶

DEST := (NOT SRC1) bitwiseAND SRC2;
SF := DEST[OperandSize -1];
ZF := (DEST = 0);

*/
}


void me_op_andnpd(Mirtille_VirtualMachine *me){
//ANDNPD — Bitwise Logical AND NOT of Packed Double Precision Floating-Point Values
/*
Operation ¶
VANDNPD (EVEX Encoded Versions) ¶

(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j := 0 TO KL-1
    i := j * 64
    IF k1[j] OR *no writemask*
            IF (EVEX.b == 1) AND (SRC2 *is memory*)
                THEN
                    DEST[i+63:i] := (NOT(SRC1[i+63:i])) BITWISE AND SRC2[63:0]
                ELSE
                    DEST[i+63:i] := (NOT(SRC1[i+63:i])) BITWISE AND SRC2[i+63:i]
            FI;
        ELSE
            IF *merging-masking* ; merging-masking
                THEN *DEST[i+63:i] remains unchanged*
                ELSE ; zeroing-masking
                    DEST[i+63:i] = 0
            FI;
    FI;
ENDFOR
DEST[MAXVL-1:VL] := 0

VANDNPD (VEX.256 Encoded Version) ¶

DEST[63:0] := (NOT(SRC1[63:0])) BITWISE AND SRC2[63:0]
DEST[127:64] := (NOT(SRC1[127:64])) BITWISE AND SRC2[127:64]
DEST[191:128] := (NOT(SRC1[191:128])) BITWISE AND SRC2[191:128]
DEST[255:192] := (NOT(SRC1[255:192])) BITWISE AND SRC2[255:192]
DEST[MAXVL-1:256] := 0

VANDNPD (VEX.128 Encoded Version) ¶

DEST[63:0] := (NOT(SRC1[63:0])) BITWISE AND SRC2[63:0]
DEST[127:64] := (NOT(SRC1[127:64])) BITWISE AND SRC2[127:64]
DEST[MAXVL-1:128] := 0

ANDNPD (128-bit Legacy SSE Version) ¶

DEST[63:0] := (NOT(DEST[63:0])) BITWISE AND SRC[63:0]
DEST[127:64] := (NOT(DEST[127:64])) BITWISE AND SRC[127:64]
DEST[MAXVL-1:128] (Unmodified)

*/
}


void me_op_andnps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_andpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_andps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_arpl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bextr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_blendpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_blendps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_blendvpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_blendvps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_blsi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_blsmsk(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_blsr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bndcl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bndcn(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bndcu(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bndldx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bndmk(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bndmov(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bndstx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bound(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bsf(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bsr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bswap(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_btc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_btr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bts(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_bzhi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_call(Mirtille_VirtualMachine *me){
//CALL — Call Procedure
/*
Operation ¶

IF near call
    THEN IF near relative call
        THEN
            IF OperandSize = 64
                THEN
                    tempDEST := SignExtend(DEST); (* DEST is rel32 *)
                    tempRIP := RIP + tempDEST;
                    IF stack not large enough for a 8-byte return address
                        THEN #SS(0); FI;
                    Push(RIP);
                    IF ShadowStackEnabled(CPL) AND DEST != 0
                        ShadowStackPush8B(RIP);
                    FI;
                    RIP := tempRIP;
            FI;
            IF OperandSize = 32
                THEN
                    tempEIP := EIP + DEST; (* DEST is rel32 *)
                    IF tempEIP is not within code segment limit THEN #GP(0); FI;
                    IF stack not large enough for a 4-byte return address
                        THEN #SS(0); FI;
                    Push(EIP);
                    IF ShadowStackEnabled(CPL) AND DEST != 0
                        ShadowStackPush4B(EIP);
                    FI;
                    EIP := tempEIP;
            FI;
            IF OperandSize = 16
                THEN
                    tempEIP := (EIP + DEST) AND 0000FFFFH; (* DEST is rel16 *)
                    IF tempEIP is not within code segment limit THEN #GP(0); FI;
                    IF stack not large enough for a 2-byte return address
                        THEN #SS(0); FI;
                    Push(IP);
                    IF ShadowStackEnabled(CPL) AND DEST != 0
                        (* IP is zero extended and pushed as a 32 bit value on shadow stack *)
                        ShadowStackPush4B(IP);
                    FI;
                    EIP := tempEIP;
            FI;
        ELSE (* Near absolute call *)
            IF OperandSize = 64
                THEN
                    tempRIP := DEST; (* DEST is r/m64 *)
                    IF stack not large enough for a 8-byte return address
                        THEN #SS(0); FI;
                    Push(RIP);
                    IF ShadowStackEnabled(CPL)
                        ShadowStackPush8B(RIP);
                    FI;
                    RIP := tempRIP;
            FI;
            IF OperandSize = 32
                THEN
                    tempEIP := DEST; (* DEST is r/m32 *)
                    IF tempEIP is not within code segment limit THEN #GP(0); FI;
                    IF stack not large enough for a 4-byte return address
                        THEN #SS(0); FI;
                    Push(EIP);
                    IF ShadowStackEnabled(CPL)
                        ShadowStackPush4B(EIP);
                    FI;
                    EIP := tempEIP;
            FI;
            IF OperandSize = 16
                THEN
                    tempEIP := DEST AND 0000FFFFH; (* DEST is r/m16 *)
                    IF tempEIP is not within code segment limit THEN #GP(0); FI;
                    IF stack not large enough for a 2-byte return address
                        THEN #SS(0); FI;
                    Push(IP);
                    IF ShadowStackEnabled(CPL)
                        (* IP is zero extended and pushed as a 32 bit value on shadow stack *)
                        ShadowStackPush4B(IP);
                    FI;
                    EIP := tempEIP;
            FI;
    FI;rel/abs
    IF (Call near indirect, absolute indirect)
        IF EndbranchEnabledAndNotSuppressed(CPL)
            IF CPL = 3
                THEN
                    IF ( no 3EH prefix OR IA32_U_CET.NO_TRACK_EN == 0 )
                        THEN
                            IA32_U_CET.TRACKER = WAIT_FOR_ENDBRANCH
                    FI;
                ELSE
                    IF ( no 3EH prefix OR IA32_S_CET.NO_TRACK_EN == 0 )
                        THEN
                            IA32_S_CET.TRACKER = WAIT_FOR_ENDBRANCH
                    FI;
            FI;
        FI;
    FI;
FI; near
IF far call and (PE = 0 or (PE = 1 and VM = 1)) (* Real-address or virtual-8086 mode *)
    THEN
        IF OperandSize = 32
            THEN
                IF stack not large enough for a 6-byte return address
                    THEN #SS(0); FI;
                IF DEST[31:16] is not zero THEN #GP(0); FI;
                Push(CS); (* Padded with 16 high-order bits *)
                Push(EIP);
                CS := DEST[47:32]; (* DEST is ptr16:32 or [m16:32] *)
                EIP := DEST[31:0]; (* DEST is ptr16:32 or [m16:32] *)
            ELSE (* OperandSize = 16 *)
                IF stack not large enough for a 4-byte return address
                    THEN #SS(0); FI;
                Push(CS);
                Push(IP);
                CS := DEST[31:16]; (* DEST is ptr16:16 or [m16:16] *)
                EIP := DEST[15:0]; (* DEST is ptr16:16 or [m16:16]; clear upper 16 bits *)
        FI;
FI;
IF far call and (PE = 1 and VM = 0) (* Protected mode or IA-32e Mode, not virtual-8086 mode*)
    THEN
        IF segment selector in target operand NULL
            THEN #GP(0); FI;
        IF segment selector index not within descriptor table limits
            THEN #GP(new code segment selector); FI;
        Read type and access rights of selected segment descriptor;
        IF IA32_EFER.LMA = 0
            THEN
                IF segment type is not a conforming or nonconforming code segment, call
                gate, task gate, or TSS
                    THEN #GP(segment selector); FI;
            ELSE
                IF segment type is not a conforming or nonconforming code segment or
                64-bit call gate,
                    THEN #GP(segment selector); FI;
        FI;
        Depending on type and access rights:
            GO TO CONFORMING-CODE-SEGMENT;
            GO TO NONCONFORMING-CODE-SEGMENT;
            GO TO CALL-GATE;
            GO TO TASK-GATE;
            GO TO TASK-STATE-SEGMENT;
FI;
CONFORMING-CODE-SEGMENT:
    IF L bit = 1 and D bit = 1 and IA32_EFER.LMA = 1
        THEN GP(new code segment selector); FI;
    IF DPL > CPL
        THEN #GP(new code segment selector); FI;
    IF segment not present
        THEN #NP(new code segment selector); FI;
    IF stack not large enough for return address
        THEN #SS(0); FI;
    tempEIP := DEST(Offset);
    IF target mode = Compatibility mode
        THEN tempEIP := tempEIP AND 00000000_FFFFFFFFH; FI;
    IF OperandSize = 16
        THEN
            tempEIP := tempEIP AND 0000FFFFH; FI; (* Clear upper 16 bits *)
    IF (IA32_EFER.LMA = 0 or target mode = Compatibility mode) and (tempEIP outside new code segment limit)
        THEN #GP(0); FI;
    IF tempEIP is non-canonical
        THEN #GP(0); FI;
    IF ShadowStackEnabled(CPL)
        IF OperandSize = 32
            THEN
                tempPushLIP = CSBASE + EIP;
            ELSE
                IF OperandSize = 16
                    THEN
                        tempPushLIP = CSBASE + IP;
                    ELSE (* OperandSize = 64 *)
                        tempPushLIP = RIP;
                FI;
        FI;
        tempPushCS = CS;
    FI;
    IF OperandSize = 32
        THEN
            Push(CS); (* Padded with 16 high-order bits *)
            Push(EIP);
            CS := DEST(CodeSegmentSelector);
            (* Segment descriptor information also loaded *)
            CS(RPL) := CPL;
            EIP := tempEIP;
        ELSE
            IF OperandSize = 16
                THEN
                    Push(CS);
                    Push(IP);
                    CS := DEST(CodeSegmentSelector);
                    (* Segment descriptor information also loaded *)
                    CS(RPL) := CPL;
                    EIP := tempEIP;
                ELSE (* OperandSize = 64 *)
                    Push(CS); (* Padded with 48 high-order bits *)
                    Push(RIP);
                    CS := DEST(CodeSegmentSelector);
                    (* Segment descriptor information also loaded *)
                    CS(RPL) := CPL;
                    RIP := tempEIP;
            FI;
    FI;
    IF ShadowStackEnabled(CPL)
        IF (IA32_EFER.LMA and DEST(CodeSegmentSelector).L) = 0
            (* If target is legacy or compatibility mode then the SSP must be in low 4GB *)
            IF (SSP & 0xFFFFFFFF00000000 != 0)
                THEN #GP(0); FI;
        FI;
        (* align to 8 byte boundary if not already aligned *)
        tempSSP = SSP;
        Shadow_stack_store 4 bytes of 0 to (SSP – 4)
        SSP = SSP & 0xFFFFFFFFFFFFFFF8H
        ShadowStackPush8B(tempPushCS); (* Padded with 48 high-order bits of 0 *)
        ShadowStackPush8B(tempPushLIP); (* Padded with 32 high-order bits of 0 for 32 bit LIP*)
        ShadowStackPush8B(tempSSP);
    FI;
    IF EndbranchEnabled(CPL)
        IF CPL = 3
            THEN
                IA32_U_CET.TRACKER = WAIT_FOR_ENDBRANCH
                IA32_U_CET.SUPPRESS = 0
            ELSE
                IA32_S_CET.TRACKER = WAIT_FOR_ENDBRANCH
                IA32_S_CET.SUPPRESS = 0
        FI;
    FI;
END;
NONCONFORMING-CODE-SEGMENT:
    IF L-Bit = 1 and D-BIT = 1 and IA32_EFER.LMA = 1
        THEN GP(new code segment selector); FI;
    IF (RPL > CPL) or (DPL ≠ CPL)
        THEN #GP(new code segment selector); FI;
    IF segment not present
        THEN #NP(new code segment selector); FI;
    IF stack not large enough for return address
        THEN #SS(0); FI;
    tempEIP := DEST(Offset);
    IF target mode = Compatibility mode
        THEN tempEIP := tempEIP AND 00000000_FFFFFFFFH; FI;
    IF OperandSize = 16
        THEN tempEIP := tempEIP AND 0000FFFFH; FI; (* Clear upper 16 bits *)
    IF (IA32_EFER.LMA = 0 or target mode = Compatibility mode) and (tempEIP outside new code segment limit)
        THEN #GP(0); FI;
    IF tempEIP is non-canonical
        THEN #GP(0); FI;
    IF ShadowStackEnabled(CPL)
        IF IA32_EFER.LMA & CS.L
            tempPushLIP = RIP
        ELSE
            tempPushLIP = CSBASE + EIP;
        FI;
        tempPushCS = CS;
    FI;
    IF OperandSize = 32
        THEN
            Push(CS); (* Padded with 16 high-order bits *)
            Push(EIP);
            CS := DEST(CodeSegmentSelector);
            (* Segment descriptor information also loaded *)
            CS(RPL) := CPL;
            EIP := tempEIP;
        ELSE
            IF OperandSize = 16
                THEN
                    Push(CS);
                    Push(IP);
                    CS := DEST(CodeSegmentSelector);
                    (* Segment descriptor information also loaded *)
                    CS(RPL) := CPL;
                    EIP := tempEIP;
                ELSE (* OperandSize = 64 *)
                    Push(CS); (* Padded with 48 high-order bits *)
                    Push(RIP);
                    CS := DEST(CodeSegmentSelector);
                    (* Segment descriptor information also loaded *)
                    CS(RPL) := CPL;
                    RIP := tempEIP;
            FI;
    FI;
    IF ShadowStackEnabled(CPL)
        IF (IA32_EFER.LMA and DEST(CodeSegmentSelector).L) = 0
            (* If target is legacy or compatibility mode then the SSP must be in low 4GB *)
            IF (SSP & 0xFFFFFFFF00000000 != 0)
                THEN #GP(0); FI;
        FI;
    (* align to 8 byte boundary if not already aligned *)
    tempSSP = SSP;
    Shadow_stack_store 4 bytes of 0 to (SSP – 4)
    SSP = SSP & 0xFFFFFFFFFFFFFFF8H
    ShadowStackPush8B(tempPushCS); (* Padded with 48 high-order 0 bits *)
    ShadowStackPush8B(tempPushLIP); (* Padded 32 high-order bits of 0 for 32 bit LIP*)
    ShadowStackPush8B(tempSSP);
    FI;
    IF EndbranchEnabled(CPL)
        IF CPL = 3
            THEN
                IA32_U_CET.TRACKER = WAIT_FOR_ENDBRANCH
                IA32_U_CET.SUPPRESS = 0
            ELSE
                IA32_S_CET.TRACKER = WAIT_FOR_ENDBRANCH
                IA32_S_CET.SUPPRESS = 0
        FI;
    FI;
END;
CALL-GATE:
    IF call gate (DPL < CPL) or (RPL > DPL)
        THEN #GP(call-gate selector); FI;
    IF call gate not present
        THEN #NP(call-gate selector); FI;
    IF call-gate code-segment selector is NULL
        THEN #GP(0); FI;
    IF call-gate code-segment selector index is outside descriptor table limits
        THEN #GP(call-gate code-segment selector); FI;
    Read call-gate code-segment descriptor;
    IF call-gate code-segment descriptor does not indicate a code segment
    or call-gate code-segment descriptor DPL > CPL
        THEN #GP(call-gate code-segment selector); FI;
    IF IA32_EFER.LMA = 1 AND (call-gate code-segment descriptor is
    not a 64-bit code segment or call-gate code-segment descriptor has both L-bit and D-bit set)
        THEN #GP(call-gate code-segment selector); FI;
    IF call-gate code segment not present
        THEN #NP(call-gate code-segment selector); FI;
    IF call-gate code segment is non-conforming and DPL < CPL
        THEN go to MORE-PRIVILEGE;
        ELSE go to SAME-PRIVILEGE;
    FI;
END;
MORE-PRIVILEGE:
    IF current TSS is 32-bit
        THEN
            TSSstackAddress := (new code-segment DPL ∗ 8) + 4;
            IF (TSSstackAddress + 5) > current TSS limit
                THEN #TS(current TSS selector); FI;
            NewSS := 2 bytes loaded from (TSS base + TSSstackAddress + 4);
            NewESP := 4 bytes loaded from (TSS base + TSSstackAddress);
        ELSE
            IF current TSS is 16-bit
                THEN
                    TSSstackAddress := (new code-segment DPL ∗ 4) + 2
                    IF (TSSstackAddress + 3) > current TSS limit
                        THEN #TS(current TSS selector); FI;
                    NewSS := 2 bytes loaded from (TSS base + TSSstackAddress + 2);
                    NewESP := 2 bytes loaded from (TSS base + TSSstackAddress);
                ELSE (* current TSS is 64-bit *)
                    TSSstackAddress := (new code-segment DPL ∗ 8) + 4;
                    IF (TSSstackAddress + 7) > current TSS limit
                        THEN #TS(current TSS selector); FI;
                    NewSS := new code-segment DPL; (* NULL selector with RPL = new CPL *)
                    NewRSP := 8 bytes loaded from (current TSS base + TSSstackAddress);
            FI;
    FI;
    IF IA32_EFER.LMA = 0 and NewSS is NULL
        THEN #TS(NewSS); FI;
    Read new stack-segment descriptor;
    IF IA32_EFER.LMA = 0 and (NewSS RPL ≠ new code-segment DPL
    or new stack-segment DPL ≠ new code-segment DPL or new stack segment is not a
    writable data segment)
        THEN #TS(NewSS); FI
    IF IA32_EFER.LMA = 0 and new stack segment not present
        THEN #SS(NewSS); FI;
    IF CallGateSize = 32
        THEN
            IF new stack does not have room for parameters plus 16 bytes
                THEN #SS(NewSS); FI;
            IF CallGate(InstructionPointer) not within new code-segment limit
                THEN #GP(0); FI;
            SS:=newSS; (*Segmentdescriptorinformationalsoloaded*)
            ESP := newESP;
            CS:EIP := CallGate(CS:InstructionPointer);
            (* Segment descriptor information also loaded *)
            Push(oldSS:oldESP); (* From calling procedure *)
            temp := parameter count from call gate, masked to 5 bits;
            Push(parameters from calling procedure’s stack, temp)
            Push(oldCS:oldEIP); (* Return address to calling procedure *)
        ELSE
            IF CallGateSize = 16
                THEN
                    IF new stack does not have room for parameters plus 8 bytes
                        THEN #SS(NewSS); FI;
                    IF (CallGate(InstructionPointer) AND FFFFH) not in new code-segment limit
                        THEN #GP(0); FI;
                    SS:=newSS; (*Segmentdescriptorinformationalsoloaded*)
                    ESP := newESP;
                    CS:IP := CallGate(CS:InstructionPointer);
                    (* Segment descriptor information also loaded *)
                    Push(oldSS:oldESP); (* From calling procedure *)
                    temp := parameter count from call gate, masked to 5 bits;
                    Push(parameters from calling procedure’s stack, temp)
                    Push(oldCS:oldEIP); (* Return address to calling procedure *)
                ELSE (* CallGateSize = 64 *)
                    IF pushing 32 bytes on the stack would use a non-canonical address
                        THEN #SS(NewSS); FI;
                    IF (CallGate(InstructionPointer) is non-canonical)
                        THEN #GP(0); FI;
                    SS := NewSS; (* NewSS is NULL)
                    RSP := NewESP;
                    CS:IP := CallGate(CS:InstructionPointer);
                    (* Segment descriptor information also loaded *)
                    Push(oldSS:oldESP); (* From calling procedure *)
                    Push(oldCS:oldEIP); (* Return address to calling procedure *)
            FI;
    FI;
    IF ShadowStackEnabled(CPL) AND CPL = 3
        THEN
            IF IA32_EFER.LMA = 0
                THEN IA32_PL3_SSP := SSP;
                ELSE (* adjust so bits 63:N get the value of bit N–1, where N is the CPU’s maximum linear-address width *)
                    IA32_PL3_SSP := LA_adjust(SSP);
            FI;
    FI;
    CPL := CodeSegment(DPL)
    CS(RPL) := CPL
    IF ShadowStackEnabled(CPL)
        oldSSP := SSP
        SSP := IA32_PLi_SSP; (* where i is the CPL *)
        IF SSP & 0x07 != 0 (* if SSP not aligned to 8 bytes then #GP *)
            THEN #GP(0); FI;
        (* Token and CS:LIP:oldSSP pushed on shadow stack must be contained in a naturally aligned 32-byte region*)
        IF (SSP & ~0x1F) != ((SSP – 24) & ~0x1F)
            #GP(0); FI;
        IF ((IA32_EFER.LMA and CS.L) = 0 AND SSP[63:32] != 0)
            THEN #GP(0); FI;
        expected_token_value = SSP (* busy bit - bit position 0 - must be clear *)
        new_token_value = SSP | BUSY_BIT (* Set the busy bit *)
        IF shadow_stack_lock_cmpxchg8b(SSP, new_token_value, expected_token_value) != expected_token_value
            THEN #GP(0); FI;
        IF oldSS.DPL != 3
            ShadowStackPush8B(oldCS); (* Padded with 48 high-order bits of 0 *)
            ShadowStackPush8B(oldCSBASE+oldRIP); (* Padded with 32 high-order bits of 0 for 32 bit LIP*)
            ShadowStackPush8B(oldSSP);
        FI;
    FI;
    IF EndbranchEnabled (CPL)
        IA32_S_CET.TRACKER = WAIT_FOR_ENDBRANCH
        IA32_S_CET.SUPPRESS = 0
    FI;
END;
SAME-PRIVILEGE:
    IF CallGateSize = 32
        THEN
            IF stack does not have room for 8 bytes
                THEN #SS(0); FI;
            IF CallGate(InstructionPointer) not within code segment limit
                THEN #GP(0); FI;
            CS:EIP := CallGate(CS:EIP) (* Segment descriptor information also loaded *)
            Push(oldCS:oldEIP); (* Return address to calling procedure *)
        ELSE
            If CallGateSize = 16
                THEN
                    IF stack does not have room for 4 bytes
                        THEN #SS(0); FI;
                    IF CallGate(InstructionPointer) not within code segment limit
                        THEN #GP(0); FI;
                    CS:IP := CallGate(CS:instruction pointer);
                    (* Segment descriptor information also loaded *)
                    Push(oldCS:oldIP); (* Return address to calling procedure *)
                ELSE (* CallGateSize = 64)
                    IF pushing 16 bytes on the stack touches non-canonical addresses
                        THEN #SS(0); FI;
                    IF RIP non-canonical
                        THEN #GP(0); FI;
                    CS:IP := CallGate(CS:instruction pointer);
                    (* Segment descriptor information also loaded *)
                    Push(oldCS:oldIP); (* Return address to calling procedure *)
            FI;
    FI;
    CS(RPL) := CPL
    IF ShadowStackEnabled(CPL)
        (* Align to next 8 byte boundary *)
        tempSSP = SSP;
        Shadow_stack_store 4 bytes of 0 to (SSP – 4)
        SSP = SSP & 0xFFFFFFFFFFFFFFF8H;
        (* push cs:lip:ssp on shadow stack *)
        ShadowStackPush8B(oldCS); (* Padded with 48 high-order bits of 0 *)
        ShadowStackPush8B(oldCSBASE + oldRIP); (* Padded with 32 high-order bits of 0 for 32 bit LIP*)
        ShadowStackPush8B(tempSSP);
    FI;
    IF EndbranchEnabled (CPL)
        IF CPL = 3
            THEN
                IA32_U_CET.TRACKER = WAIT_FOR_ENDBRANCH;
                IA32_U_CET.SUPPRESS = 0
            ELSE
                IA32_S_CET.TRACKER = WAIT_FOR_ENDBRANCH;
                IA32_S_CET.SUPPRESS = 0
        FI;
    FI;
END;
TASK-GATE:
    IF task gate DPL < CPL or RPL
        THEN #GP(task gate selector); FI;
    IF task gate not present
        THEN #NP(task gate selector); FI;
    Read the TSS segment selector in the task-gate descriptor;
    IF TSS segment selector local/global bit is set to local
    or index not within GDT limits
        THEN #GP(TSS selector); FI;
    Access TSS descriptor in GDT;
    IF descriptor is not a TSS segment
        THEN #GP(TSS selector); FI;
    IF TSS descriptor specifies that the TSS is busy
        THEN #GP(TSS selector); FI;
    IF TSS not present
        THEN #NP(TSS selector); FI;
    SWITCH-TASKS (with nesting) to TSS;
    IF EIP not within code segment limit
        THEN #GP(0); FI;
END;
TASK-STATE-SEGMENT:
    IF TSS DPL < CPL or RPL
    or TSS descriptor indicates TSS not available
        THEN #GP(TSS selector); FI;
    IF TSS is not present
        THEN #NP(TSS selector); FI;
    SWITCH-TASKS (with nesting) to TSS;
    IF EIP not within code segment limit
        THEN #GP(0); FI;
END;

*/
}


void me_op_cbw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cdqe(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_clac(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_clc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cldemote(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_clflush(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_clflushopt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cli(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_clrssbsy(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_clts(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_clui(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_clwb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmovcc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmp(Mirtille_VirtualMachine *me){
//CMP — Compare Two Operands
/*
Operation ¶

temp := SRC1 − SignExtend(SRC2);
ModifyStatusFlags; (* Modify status flags in the same manner as the SUB instruction*)


*/
}


void me_op_cmppd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpsq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpxchg(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpxchg16b(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cmpxchg8b(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_comisd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_comiss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cpuid(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cqo(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_crc32(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtdq2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtdq2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtpd2dq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtpd2pi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtpd2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtpi2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtpi2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtps2dq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtps2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtps2pi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtsd2si(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtsd2ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtsi2sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtsi2ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtss2sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvtss2si(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvttpd2dq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvttpd2pi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvttps2dq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvttps2pi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvttsd2si(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cvttss2si(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cwd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_cwde(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_daa(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_das(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_dec(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_div(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_divpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_divps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_divsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_divss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_dppd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_dpps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_emms(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encodekey128(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encodekey256(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_endbr32(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_endbr64(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enqcmd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enqcmds(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enter(Mirtille_VirtualMachine *me){
//ENTER — Make Stack Frame for Procedure Parameters
/*
Operation ¶

AllocSize := imm16;
NestingLevel := imm8 MOD 32;
IF (OperandSize = 64)
    THEN
        Push(RBP); (* RSP decrements by 8 *)
        FrameTemp := RSP;
    ELSE IF OperandSize = 32
        THEN
            Push(EBP); (* (E)SP decrements by 4 *)
            FrameTemp := ESP; FI;
    ELSE (* OperandSize = 16 *)
            Push(BP); (* RSP or (E)SP decrements by 2 *)
            FrameTemp := SP;
FI;
IF NestingLevel = 0
    THEN GOTO CONTINUE;
FI;
IF (NestingLevel > 1)
    THEN FOR i := 1 to (NestingLevel - 1)
        DO
            IF (OperandSize = 64)
                THEN
                    RBP := RBP - 8;
                    Push([RBP]); (* Quadword push *)
                ELSE IF OperandSize = 32
                    THEN
                        IF StackSize = 32
                            EBP := EBP - 4;
                            Push([EBP]); (* Doubleword push *)
                        ELSE (* StackSize = 16 *)
                            BP := BP - 4;
                            Push([BP]); (* Doubleword push *)
                        FI;
                    FI;
                ELSE (* OperandSize = 16 *)
                    IF StackSize = 64
                        THEN
                            RBP := RBP - 2;
                            Push([RBP]); (* Word push *)
                    ELSE IF StackSize = 32
                        THEN
                            EBP := EBP - 2;
                            Push([EBP]); (* Word push *)
                        ELSE (* StackSize = 16 *)
                            BP := BP - 2;
                            Push([BP]); (* Word push *)
                    FI;
                FI;
    OD;
FI;
IF (OperandSize = 64) (* nestinglevel 1 *)
    THEN
        Push(FrameTemp); (* Quadword push and RSP decrements by 8 *)
    ELSE IF OperandSize = 32
        THEN
            Push(FrameTemp); FI; (* Doubleword push and (E)SP decrements by 4 *)
    ELSE (* OperandSize = 16 *)
            Push(FrameTemp); (* Word push and RSP|ESP|SP decrements by 2 *)
FI;
CONTINUE:
IF 64-Bit Mode (StackSize = 64)
    THEN
            RBP := FrameTemp;
            RSP := RSP − AllocSize;
    ELSE IF OperandSize = 32
        THEN
            EBP := FrameTemp;
            ESP := ESP − AllocSize; FI;
    ELSE (* OperandSize = 16 *)
            BP := FrameTemp[15:1]; (* Bits 16 and above of applicable RBP/EBP are unmodified *)
            SP := SP − AllocSize;
FI;
END;

*/
}


void me_op_extractps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_f2xm1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fabs(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fadd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_faddp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fbld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fbstp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fchs(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fclex(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fcmovcc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fcom(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fcomi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fcomip(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fcomp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fcompp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fcos(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fdecstp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fdiv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fdivp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fdivr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fdivrp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ffree(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fiadd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ficom(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ficomp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fidiv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fidivr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fild(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fimul(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fincstp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_finit(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fist(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fistp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fisttp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fisub(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fisubr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fld1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fldcw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fldenv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fldl2e(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fldl2t(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fldlg2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fldln2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fldpi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fldz(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fmul(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fmulp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fnclex(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fninit(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fnop(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fnsave(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fnstcw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fnstenv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fnstsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fpatan(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fprem(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fprem1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fptan(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_frndint(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_frstor(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fsave(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fscale(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fsin(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fsincos(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fsqrt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fst(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fstcw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fstenv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fstp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fstsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fsub(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fsubp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fsubr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fsubrp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ftst(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fucom(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fucomi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fucomip(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fucomp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fucompp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fwait(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fxam(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fxch(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fxrstor(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fxsave(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fxtract(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fyl2x(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_fyl2xp1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_gf2p8affineinvqb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_gf2p8affineqb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_gf2p8mulb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_haddpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_haddps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_hlt(Mirtille_VirtualMachine *me){
//HLT — Halt
/*
Operation ¶

Enter Halt state;

*/
}


void me_op_hreset(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_hsubpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_hsubps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_idiv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_imul(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_in(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_inc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_incsspd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_incsspq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ins(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_insb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_insd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_insertps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_insw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_int(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_int1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_int3(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_into(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_invd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_invlpg(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_invpcid(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_iret(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_iretd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_iretq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_jmp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_jcc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kaddb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kaddd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kaddq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kaddw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kandb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kandd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kandnb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kandnd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kandnq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kandnw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kandq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kandw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kmovb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kmovd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kmovq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kmovw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_knotb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_knotd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_knotq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_knotw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_korb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kord(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_korq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kortestb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kortestd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kortestq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kortestw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_korw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kshiftlb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kshiftld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kshiftlq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kshiftlw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kshiftrb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kshiftrd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kshiftrq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kshiftrw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ktestb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ktestd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ktestq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ktestw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kunpckbw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kunpckdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kunpckwd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kxnorb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kxnord(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kxnorq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kxnorw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kxorb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kxord(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kxorq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_kxorw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lahf(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lar(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lddqu(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ldmxcsr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lds(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ldtilecfg(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lea(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_leave(Mirtille_VirtualMachine *me){
//LEA — Load Effective Address
/*
Operation ¶

IF OperandSize = 16 and AddressSize = 16
    THEN
        DEST := EffectiveAddress(SRC); (* 16-bit address *)
    ELSE IF OperandSize = 16 and AddressSize = 32
        THEN
            temp := EffectiveAddress(SRC); (* 32-bit address *)
            DEST := temp[0:15]; (* 16-bit address *)
        FI;
    ELSE IF OperandSize = 32 and AddressSize = 16
        THEN
            temp := EffectiveAddress(SRC); (* 16-bit address *)
            DEST := ZeroExtend(temp); (* 32-bit address *)
        FI;
    ELSE IF OperandSize = 32 and AddressSize = 32
        THEN
            DEST := EffectiveAddress(SRC); (* 32-bit address *)
        FI;
    ELSE IF OperandSize = 16 and AddressSize = 64
        THEN
            temp := EffectiveAddress(SRC); (* 64-bit address *)
            DEST := temp[0:15]; (* 16-bit address *)
        FI;
    ELSE IF OperandSize = 32 and AddressSize = 64
        THEN
            temp := EffectiveAddress(SRC); (* 64-bit address *)
            DEST := temp[0:31]; (* 16-bit address *)
        FI;
    ELSE IF OperandSize = 64 and AddressSize = 64
        THEN
            DEST := EffectiveAddress(SRC); (* 64-bit address *)
        FI;
FI;

*/
}


void me_op_les(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lfence(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lfs(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lgdt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lgs(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lidt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lldt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lmsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_loadiwkey(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lock(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lods(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lodsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lodsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lodsq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lodsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_loop(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_loopcc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lsl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ltr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_lzcnt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_maskmovdqu(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_maskmovq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_maxpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_maxps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_maxsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_maxss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mfence(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_minpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_minps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_minsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_minss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_monitor(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mov_Move(Mirtille_VirtualMachine *me){
//MOV — Move
/*
Operation ¶

DEST := SRC;
Loading a segment register while in protected mode results in special checks and actions, as described in the following listing. These
checks are performed on the segment selector and the segment descriptor to which it points.
IF SS is loaded
    THEN
        IF segment selector is NULL
            THEN #GP(0); FI;
        IF segment selector index is outside descriptor table limits
        OR segment selector's RPL ≠ CPL
        OR segment is not a writable data segment
        OR DPL ≠ CPL
            THEN #GP(selector); FI;
        IF segment not marked present
            THEN #SS(selector);
            ELSE
                SS := segment selector;
                SS := segment descriptor; FI;
FI;
IF DS, ES, FS, or GS is loaded with non-NULL selector
THEN
    IF segment selector index is outside descriptor table limits
    OR segment is not a data or readable code segment
    OR ((segment is a data or nonconforming code segment) AND ((RPL > DPL) or (CPL > DPL)))
        THEN #GP(selector); FI;
    IF segment not marked present
        THEN #NP(selector);
        ELSE
            SegmentRegister := segment selector;
            SegmentRegister := segment descriptor; FI;
FI;
IF DS, ES, FS, or GS is loaded with NULL selector
    THEN
        SegmentRegister := segment selector;
        SegmentRegister := segment descriptor;
FI;

*/
}


void me_op_mov_Control_Registers(Mirtille_VirtualMachine *me){
//MOV — Move to/from Control Registers
/*
Operation ¶

DEST := SRC;

*/
}


void me_op_mov_Debug_Registers(Mirtille_VirtualMachine *me){
//MOV — Move to/from Debug Registers
/*
Operation ¶

IF ((DE = 1) and (SRC or DEST = DR4 or DR5))
    THEN
        #UD;
    ELSE
        DEST := SRC;
FI;

*/
}


void me_op_movapd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movaps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movbe(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movddup(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movdir64b(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movdiri(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movdq2q(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movdqa(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movdqu(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movhlps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movhpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movhps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movlhps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movlpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movlps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movmskpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movmskps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movntdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movntdqa(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movnti(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movntpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movntps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movntq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movq2dq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movs(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movshdup(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movsldup(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movsq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movsx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movsxd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movupd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movups(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_movzx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mpsadbw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mul(Mirtille_VirtualMachine *me){
//MUL — Unsigned Multiply
/*
Operation ¶

IF (Byte operation)
    THEN
        AX := AL ∗ SRC;
    ELSE (* Word or doubleword operation *)
        IF OperandSize = 16
            THEN
                DX:AX := AX ∗ SRC;
            ELSE IF OperandSize = 32
                THEN EDX:EAX := EAX ∗ SRC; FI;
            ELSE (* OperandSize = 64 *)
                RDX:RAX := RAX ∗ SRC;
        FI;
FI;

*/
}


void me_op_mulpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mulps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mulsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mulss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mulx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_mwait(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_neg(Mirtille_VirtualMachine *me){
//NEG — Two's Complement Negation
/*
Operation ¶

IF DEST = 0
    THEN CF := 0;
    ELSE CF := 1;
FI;
DEST := [– (DEST)]

*/
}


void me_op_nop(Mirtille_VirtualMachine *me){
//NOP — No Operation
/*
Operation ¶

The one-byte NOP instruction is an alias mnemonic for the XCHG (E)AX, (E)AX instruction.
The multi-byte NOP instruction performs no operation on supported processors and generates undefined opcode
exception on processors that do not support the multi-byte NOP instruction.
The memory operand form of the instruction allows software to create a byte sequence of “no operation” as one
instruction. For situations where multiple-byte NOPs are needed, the recommended operations (32-bit mode and
64-bit mode) are:

Length: 	
2 bytes 
3 bytes 
4 bytes 
5 bytes 
6 bytes 
7 bytes 
8 bytes 
9 bytes 	

Assembly:
66 NOP NOP DWORD ptr [EAX] NOP 
DWORD ptr [EAX + 00H] NOP DWORD ptr
[EAX + EAX*1 + 00H] 66 NOP DWORD ptr 
[EAX + EAX*1 + 00H] NOP DWORD ptr 
[EAX + 00000000H] NOP DWORD ptr 
[EAX + EAX*1 + 00000000H] 66 NOP DWORD 
ptr [EAX + EAX*1 + 00000000H] 	

Byte Sequence:
66 90H 0F 1F 00H 0F 1F 40 
00H 0F 1F 44 00 00H 66 0F 
1F 44 00 00H 0F 1F 80 00 
00 00 00H 0F 1F 84 00 00 
00 00 00H 66 0F 1F 84 00 
00 00 00 00H
*/
}


void me_op_not(Mirtille_VirtualMachine *me){
//NOT — One's Complement Negation
/*
Operation ¶

DEST := NOT DEST;

*/
}


void me_op_or(Mirtille_VirtualMachine *me){
//OR — Logical Inclusive OR
/*
Operation ¶

DEST := DEST OR SRC;

*/
}


void me_op_orpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_orps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_out(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_outs(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_outsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_outsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_outsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pabsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pabsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pabsq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pabsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_packssdw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_packsswb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_packusdw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_packuswb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_paddb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_paddd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_paddq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_paddsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_paddsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_paddusb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_paddusw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_paddw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_palignr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pand(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pandn(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pause(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pavgb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pavgw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pblendvb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pblendw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pclmulqdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpeqb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpeqd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpeqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpeqw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpestri(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpestrm(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpgtb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpgtd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpgtq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpgtw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpistri(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pcmpistrm(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pconfig(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pdep(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pext(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pextrb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pextrd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pextrq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pextrw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_phaddd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_phaddsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_phaddw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_phminposuw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_phsubd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_phsubsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_phsubw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pinsrb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pinsrd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pinsrq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pinsrw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaddubsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaddwd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaxsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaxsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaxsq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaxsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaxub(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaxud(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaxuq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmaxuw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pminsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pminsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pminsq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pminsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pminub(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pminud(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pminuq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pminuw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmovmskb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmovsx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmovzx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmuldq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmulhrsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmulhuw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmulhw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmulld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmullq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmullw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pmuludq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pop(Mirtille_VirtualMachine *me){
//POP — Pop a Value From the Stack
/*
Operation ¶

IF StackAddrSize = 32
    THEN
        IF OperandSize = 32
                THEN
                    DEST := SS:ESP; (* Copy a doubleword *)
                    ESP := ESP + 4;
                ELSE (* OperandSize = 16*)
                    DEST := SS:ESP; (* Copy a word *)
                    ESP := ESP + 2;
        FI;
    ELSE IF StackAddrSize = 64
        THEN
                IF OperandSize = 64
                    THEN
                        DEST := SS:RSP; (* Copy quadword *)
                        RSP := RSP + 8;
                    ELSE (* OperandSize = 16*)
                        DEST := SS:RSP; (* Copy a word *)
                        RSP := RSP + 2;
                FI;
        FI;
    ELSE StackAddrSize = 16
        THEN
                IF OperandSize = 16
                    THEN
                        DEST := SS:SP; (* Copy a word *)
                        SP := SP + 2;
                    ELSE (* OperandSize = 32 *)
                        DEST := SS:SP; (* Copy a doubleword *)
                        SP := SP + 4;
                FI;
FI;
Loading a segment register while in protected mode results in special actions, as described in the following listing.
These checks are performed on the segment selector and the segment descriptor it points to.
64-BIT_MODE
IF FS, or GS is loaded with non-NULL selector;
    THEN
        IF segment selector index is outside descriptor table limits
                OR segment is not a data or readable code segment
                OR ((segment is a data or nonconforming code segment)
                    AND ((RPL > DPL) or (CPL > DPL))
                        THEN #GP(selector);
                IF segment not marked present
                    THEN #NP(selector);
        ELSE
                SegmentRegister := segment selector;
                SegmentRegister := segment descriptor;
        FI;
FI;
IF FS, or GS is loaded with a NULL selector;
        THEN
                SegmentRegister := segment selector;
                SegmentRegister := segment descriptor;
FI;
PREOTECTED MODE OR COMPATIBILITY MODE;
IF SS is loaded;
    THEN
        IF segment selector is NULL
                THEN #GP(0);
        FI;
        IF segment selector index is outside descriptor table limits
                or segment selector's RPL ≠ CPL
                or segment is not a writable data segment
                or DPL ≠ CPL
                    THEN #GP(selector);
        FI;
        IF segment not marked present
                THEN #SS(selector);
                ELSE
                    SS := segment selector;
                    SS := segment descriptor;
        FI;
FI;
IF DS, ES, FS, or GS is loaded with non-NULL selector;
    THEN
        IF segment selector index is outside descriptor table limits
                or segment is not a data or readable code segment
                or ((segment is a data or nonconforming code segment)
                and ((RPL > DPL) or (CPL > DPL))
                    THEN #GP(selector);
        FI;
        IF segment not marked present
                THEN #NP(selector);
                ELSE
                    SegmentRegister := segment selector;
                    SegmentRegister := segment descriptor;
            FI;
FI;
IF DS, ES, FS, or GS is loaded with a NULL selector
    THEN
        SegmentRegister := segment selector;
        SegmentRegister := segment descriptor;
FI;

*/
}


void me_op_popa(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_popad(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_popcnt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_popf(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_popfd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_popfq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_por(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_prefetchw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_prefetchh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psadbw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pshufb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pshufd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pshufhw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pshuflw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pshufw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psignb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psignd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psignw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pslld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pslldq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psllq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psllw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psrad(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psraq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psraw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psrld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psrldq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psrlq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psrlw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psubb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psubd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psubq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psubsb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psubsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psubusb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psubusw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_psubw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ptest(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ptwrite(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_punpckhbw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_punpckhdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_punpckhqdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_punpckhwd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_punpcklbw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_punpckldq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_punpcklqdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_punpcklwd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_push(Mirtille_VirtualMachine *me){
//PUSH — Push Word, Doubleword, or Quadword Onto the Stack
/*
Operation ¶

(* See Description section for possible sign-extension or zero-extension of source operand and for *)
(* a case in which the size of the memory store may be
                    smaller than the instruction’s operand size *)
IF StackAddrSize = 64
    THEN
        IF OperandSize = 64
            THEN
                RSP := RSP – 8;
                Memory[SS:RSP] := SRC;
                    (* push quadword *)
        ELSE IF OperandSize = 32
            THEN
                RSP := RSP – 4;
                Memory[SS:RSP] := SRC;
                    (* push dword *)
            ELSE (* OperandSize = 16 *)
                RSP := RSP – 2;
                Memory[SS:RSP] := SRC;
                    (* push word *)
        FI;
ELSE IF StackAddrSize = 32
    THEN
        IF OperandSize = 64
            THEN
                ESP := ESP – 8;
                Memory[SS:ESP] := SRC;
                    (* push quadword *)
        ELSE IF OperandSize = 32
            THEN
                ESP := ESP – 4;
                Memory[SS:ESP] := SRC;
                    (* push dword *)
            ELSE (* OperandSize = 16 *)
                ESP := ESP – 2;
                Memory[SS:ESP] := SRC;
                    (* push word *)
        FI;
    ELSE (* StackAddrSize = 16 *)
        IF OperandSize = 32
            THEN
                SP := SP – 4;
                Memory[SS:SP] := SRC;
                    (* push dword *)
            ELSE (* OperandSize = 16 *)
                SP := SP – 2;
                Memory[SS:SP] := SRC;
                    (* push word *)
        FI;
FI;

*/
}


void me_op_pusha(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pushad(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pushf(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pushfd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pushfq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_pxor(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rcl(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rcpps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rcpss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rcr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdfsbase(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdgsbase(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdmsr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdpid(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdpkru(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdpmc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdrand(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdseed(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdsspd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdsspq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdtsc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rdtscp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rep(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_repe(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_repne(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_repnz(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_repz(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ret(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rol(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ror(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rorx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_roundpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_roundps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_roundsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_roundss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rsm(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rsqrtps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rsqrtss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_rstorssp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sahf(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sal(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sar(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sarx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_saveprevssp(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sbb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_scas(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_scasb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_scasd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_scasw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_senduipi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_serialize(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_setssbsy(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_setcc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sfence(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sgdt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sha1msg1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sha1msg2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sha1nexte(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sha1rnds4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sha256msg1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sha256msg2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sha256rnds2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_shl(Mirtille_VirtualMachine *me){
//SAL/SAR/SHL/SHR — Shift
/*
Operation ¶

IF OperandSize = 64
    THEN
        countMASK := 3FH;
    ELSE
        countMASK := 1FH;
FI
tempCOUNT := (COUNT AND countMASK);
tempDEST := DEST;
WHILE (tempCOUNT ≠ 0)
DO
    IF instruction is SAL or SHL
        THEN
            CF := MSB(DEST);
        ELSE (* Instruction is SAR or SHR *)
            CF := LSB(DEST);
    FI;
    IF instruction is SAL or SHL
        THEN
            DEST := DEST ∗ 2;
        ELSE
            IF instruction is SAR
                THEN
                    DEST := DEST / 2; (* Signed divide, rounding toward negative infinity *)
                ELSE (* Instruction is SHR *)
                    DEST := DEST / 2 ; (* Unsigned divide *)
            FI;
    FI;
    tempCOUNT := tempCOUNT – 1;
OD;
(* Determine overflow for the various instructions *)
IF (COUNT and countMASK) = 1
    THEN
        IF instruction is SAL or SHL
            THEN
                OF := MSB(DEST) XOR CF;
            ELSE
                IF instruction is SAR
                    THEN
                        OF := 0;
                    ELSE (* Instruction is SHR *)
                        OF := MSB(tempDEST);
                FI;
        FI;
    ELSE IF (COUNT AND countMASK) = 0
        THEN
            All flags unchanged;
        ELSE (* COUNT not 1 or 0 *)
            OF := undefined;
    FI;
FI;

*/
}


void me_op_shld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_shlx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_shr(Mirtille_VirtualMachine *me){
//SAL/SAR/SHL/SHR — Shift
/*
Operation ¶

IF OperandSize = 64
    THEN
        countMASK := 3FH;
    ELSE
        countMASK := 1FH;
FI
tempCOUNT := (COUNT AND countMASK);
tempDEST := DEST;
WHILE (tempCOUNT ≠ 0)
DO
    IF instruction is SAL or SHL
        THEN
            CF := MSB(DEST);
        ELSE (* Instruction is SAR or SHR *)
            CF := LSB(DEST);
    FI;
    IF instruction is SAL or SHL
        THEN
            DEST := DEST ∗ 2;
        ELSE
            IF instruction is SAR
                THEN
                    DEST := DEST / 2; (* Signed divide, rounding toward negative infinity *)
                ELSE (* Instruction is SHR *)
                    DEST := DEST / 2 ; (* Unsigned divide *)
            FI;
    FI;
    tempCOUNT := tempCOUNT – 1;
OD;
(* Determine overflow for the various instructions *)
IF (COUNT and countMASK) = 1
    THEN
        IF instruction is SAL or SHL
            THEN
                OF := MSB(DEST) XOR CF;
            ELSE
                IF instruction is SAR
                    THEN
                        OF := 0;
                    ELSE (* Instruction is SHR *)
                        OF := MSB(tempDEST);
                FI;
        FI;
    ELSE IF (COUNT AND countMASK) = 0
        THEN
            All flags unchanged;
        ELSE (* COUNT not 1 or 0 *)
            OF := undefined;
    FI;
FI;

*/
}


void me_op_shrd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_shrx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_shufpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_shufps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sidt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sldt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_smsw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sqrtpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sqrtps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sqrtsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sqrtss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stac(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_std(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sti(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stmxcsr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stos(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stosb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stosd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stosq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stosw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_str(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sttilecfg(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_stui(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sub(Mirtille_VirtualMachine *me){
//SUB — Subtract
/*
Operation ¶

DEST := (DEST – SRC);

*/
}


void me_op_subpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_subps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_subsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_subss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_swapgs(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_syscall(Mirtille_VirtualMachine *me){
//SYSCALL — Fast System Call
/*
Operation ¶

IF (CS.L ≠ 1 ) or (IA32_EFER.LMA ≠ 1) or (IA32_EFER.SCE ≠ 1)
(* Not in 64-Bit Mode or SYSCALL/SYSRET not enabled in IA32_EFER *)
    THEN #UD;
FI;
RCX := RIP; (* Will contain address of next instruction *)
RIP := IA32_LSTAR;
R11 := RFLAGS;
RFLAGS := RFLAGS AND NOT(IA32_FMASK);
CS.Selector := IA32_STAR[47:32] AND FFFCH (* Operating system provides CS; RPL forced to 0 *)
(* Set rest of CS to a fixed value *)
CS.Base := 0;
                (* Flat segment *)
CS.Limit := FFFFFH;
                (* With 4-KByte granularity, implies a 4-GByte limit *)
CS.Type := 11;
                (* Execute/read code, accessed *)
CS.S := 1;
CS.DPL := 0;
CS.P := 1;
CS.L := 1;
                (* Entry is to 64-bit mode *)
CS.D := 0;
                (* Required if CS.L = 1 *)
CS.G := 1;
                (* 4-KByte granularity *)
IF ShadowStackEnabled(CPL)
    THEN (* adjust so bits 63:N get the value of bit N–1, where N is the CPU’s maximum linear-address width *)
        IA32_PL3_SSP := LA_adjust(SSP);
            (* With shadow stacks enabled the system call is supported from Ring 3 to Ring 0 *)
            (* OS supporting Ring 0 to Ring 0 system calls or Ring 1/2 to ring 0 system call *)
            (* Must preserve the contents of IA32_PL3_SSP to avoid losing ring 3 state *)
FI;
CPL := 0;
IF ShadowStackEnabled(CPL)
    SSP := 0;
FI;
IF EndbranchEnabled(CPL)
    IA32_S_CET.TRACKER = WAIT_FOR_ENDBRANCH
    IA32_S_CET.SUPPRESS = 0
FI;
SS.Selector := IA32_STAR[47:32] + 8;
                (* SS just above CS *)
(* Set rest of SS to a fixed value *)
SS.Base := 0;
                (* Flat segment *)
SS.Limit := FFFFFH;
                (* With 4-KByte granularity, implies a 4-GByte limit *)
SS.Type := 3;
                (* Read/write data, accessed *)
SS.S := 1;
SS.DPL := 0;
SS.P := 1;
SS.B := 1;
                (* 32-bit stack segment *)
SS.G := 1;
                (* 4-KByte granularity *)

*/
}


void me_op_sysenter(Mirtille_VirtualMachine *me){
//SYSENTER — Fast System Call
/*
Operation ¶

IF CR0.PE = 0 OR IA32_SYSENTER_CS[15:2] = 0 THEN #GP(0); FI;
RFLAGS.VM := 0;
                    (* Ensures protected mode execution *)
RFLAGS.IF := 0;
                    (* Mask interrupts *)
IF in IA-32e mode
    THEN
        RSP := IA32_SYSENTER_ESP;
        RIP := IA32_SYSENTER_EIP;
ELSE
        ESP := IA32_SYSENTER_ESP[31:0];
        EIP := IA32_SYSENTER_EIP[31:0];
FI;
CS.Selector := IA32_SYSENTER_CS[15:0] AND
                    FFFCH;
                    (* Operating system provides CS; RPL forced to 0 *)
(* Set rest of CS to a fixed value *)
CS.Base := 0;
                    (* Flat segment *)
CS.Limit := FFFFFH;
                    (* With 4-KByte granularity, implies a 4-GByte limit *)
CS.Type := 11;
                    (* Execute/read code, accessed *)
CS.S := 1;
CS.DPL := 0;
CS.P := 1;
IF in IA-32e mode
    THEN
        CS.L := 1;
                    (* Entry is to 64-bit mode *)
        CS.D := 0;
                    (* Required if CS.L = 1 *)
    ELSE
        CS.L := 0;
        CS.D := 1;
                    (* 32-bit code segment*)
FI;
CS.G := 1;
                    (* 4-KByte granularity *)
IF ShadowStackEnabled(CPL)
    THEN
        IF IA32_EFER.LMA = 0
            THEN IA32_PL3_SSP := SSP;
            ELSE (* adjust so bits 63:N get the value of bit N–1, where N is the CPU’s maximum linear-address width *)
                IA32_PL3_SSP := LA_adjust(SSP);
        FI;
FI;
CPL := 0;
IF ShadowStackEnabled(CPL)
    SSP := 0;
FI;
IF EndbranchEnabled(CPL)
    IA32_S_CET.TRACKER = WAIT_FOR_ENDBRANCH
    IA32_S_CET.SUPPRESS = 0
FI;
SS.Selector := CS.Selector + 8;
                    (* SS just above CS *)
(* Set rest of SS to a fixed value *)
SS.Base := 0;
                    (* Flat segment *)
SS.Limit := FFFFFH;
                    (* With 4-KByte granularity, implies a 4-GByte limit *)
SS.Type := 3;
                    (* Read/write data, accessed *)
SS.S := 1;
SS.DPL := 0;
SS.P := 1;
SS.B := 1;
                    (* 32-bit stack segment*)
SS.G := 1;
                    (* 4-KByte granularity *)

*/
}


void me_op_sysexit(Mirtille_VirtualMachine *me){
//SYSEXIT — Fast Return from Fast System Call
/*
Operation ¶

IF IA32_SYSENTER_CS[15:2] = 0 OR CR0.PE = 0 OR CPL ≠ 0 THEN #GP(0); FI;
IF operand size is 64-bit
    THEN (* Return to 64-bit mode *)
        RSP := RCX;
        RIP := RDX;
    ELSE (* Return to protected mode or compatibility mode *)
        RSP := ECX;
        RIP := EDX;
FI;
IF operand size is 64-bit (* Operating system provides CS; RPL forced to 3 *)
    THEN CS.Selector := IA32_SYSENTER_CS[15:0] + 32;
    ELSE CS.Selector := IA32_SYSENTER_CS[15:0] + 16;
FI;
CS.Selector := CS.Selector OR 3;
            (* RPL forced to 3 *)
(* Set rest of CS to a fixed value *)
CS.Base := 0;
            (* Flat segment *)
CS.Limit := FFFFFH;
            (* With 4-KByte granularity, implies a 4-GByte limit *)
CS.Type := 11;
            (* Execute/read code, accessed *)
CS.S := 1;
CS.DPL := 3;
CS.P := 1;
IF operand size is 64-bit
    THEN (* return to 64-bit mode *)
        CS.L := 1;
            (* 64-bit code segment *)
        CS.D := 0;
    ELSE (* return to protected mode or compatibility mode *)
        CS.L := 0;
        CS.D := 1;
            (* 32-bit code segment*)
FI;
CS.G := 1;
            (* 4-KByte granularity *)
CPL := 3;
IF ShadowStackEnabled(CPL)
    THEN SSP := IA32_PL3_SSP;
FI;
SS.Selector := CS.Selector + 8;
            (* SS just above CS *)
(* Set rest of SS to a fixed value *)
SS.Base := 0;
            (* Flat segment *)
SS.Limit := FFFFFH;
            (* With 4-KByte granularity, implies a 4-GByte limit *)
SS.Type := 3;
            (* Read/write data, accessed *)
SS.S := 1;
SS.DPL := 3;
SS.P := 1;
SS.B := 1;
            (* 32-bit stack segment*)
SS.G := 1; (* 4-KByte granularity *)

*/
}


void me_op_sysret(Mirtille_VirtualMachine *me){
//SYSRET — Return From Fast System Call
/*
Operation ¶

IF (CS.L ≠ 1 ) or (IA32_EFER.LMA ≠ 1) or (IA32_EFER.SCE ≠ 1)
(* Not in 64-Bit Mode or SYSCALL/SYSRET not enabled in IA32_EFER *)
    THEN #UD; FI;
IF (CPL ≠ 0) THEN #GP(0); FI;
IF (operand size is 64-bit)
    THEN (* Return to 64-Bit Mode *)
        IF (RCX is not canonical) THEN #GP(0);
        RIP := RCX;
    ELSE (* Return to Compatibility Mode *)
        RIP := ECX;
FI;
RFLAGS := (R11 & 3C7FD7H) | 2; (*
                Clear RF, VM, reserved bits; set bit 1 *)
IF (operand size is 64-bit)
    THEN CS.Selector := IA32_STAR[63:48]+16;
    ELSE CS.Selector := IA32_STAR[63:48];
FI;
CS.Selector := CS.Selector OR 3;
            (* RPL forced to 3 *)
(* Set rest of CS to a fixed value *)
CS.Base := 0;
            (* Flat segment *)
CS.Limit := FFFFFH;
            (* With 4-KByte granularity, implies a 4-GByte limit *)
CS.Type := 11;
            (* Execute/read code, accessed *)
CS.S := 1;
CS.DPL := 3;
CS.P := 1;
IF (operand size is 64-bit)
    THEN (* Return to 64-Bit Mode *)
        CS.L := 1;
            (* 64-bit code segment *)
        CS.D := 0;
            (* Required if CS.L = 1 *)
    ELSE (* Return to Compatibility Mode *)
        CS.L := 0;
            (* Compatibility mode *)
        CS.D := 1;
            (* 32-bit code segment *)
FI;
CS.G := 1;
            (* 4-KByte granularity *)
CPL := 3;
IF ShadowStackEnabled(CPL)
    SSP := IA32_PL3_SSP;
FI;
SS.Selector := (IA32_STAR[63:48]+8) OR 3;
            (* RPL forced to 3 *)
(* Set rest of SS to a fixed value *)
SS.Base := 0;
            (* Flat segment *)
SS.Limit := FFFFFH;
            (* With 4-KByte granularity, implies a 4-GByte limit *)
SS.Type := 3;
            (* Read/write data, accessed *)
SS.S := 1;
SS.DPL := 3;
SS.P := 1;
SS.B := 1;
            (* 32-bit stack segment*)
SS.G := 1;
            (* 4-KByte granularity *)

*/
}


void me_op_tdpbf16ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tdpbssd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tdpbsud(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tdpbusd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tdpbuud(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_test(Mirtille_VirtualMachine *me){
//TEST — Logical Compare
/*
Operation ¶

TEMP := SRC1 AND SRC2;
SF := MSB(TEMP);
IF TEMP = 0
    THEN ZF := 1;
    ELSE ZF := 0;
FI:
PF := BitwiseXNOR(TEMP[0:7]);
CF := 0;
OF := 0;
(* AF is undefined *)

*/
}


void me_op_testui(Mirtille_VirtualMachine *me){
//TESTUI — Determine User Interrupt Flag
/*
Operation ¶

CF := UIF;
ZF := AF := OF := PF := SF := 0;

*/
}


void me_op_tileloadd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tileloaddt1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tilerelease(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tilestored(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tilezero(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tpause(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_tzcnt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ucomisd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ucomiss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_ud(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_uiret(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_umonitor(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_umwait(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_unpckhpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_unpckhps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_unpcklpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_unpcklps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vaddph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vaddsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_valignd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_valignq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vblendmpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vblendmps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vbroadcast(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcmpph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcmpsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcomish(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcompresspd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcompressps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcompressw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtdq2ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtne2ps2bf16(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtneps2bf16(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtpd2ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtpd2qq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtpd2udq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtpd2uqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2dq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2psx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2qq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2udq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2uqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2uw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtph2w(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtps2ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtps2phx(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtps2qq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtps2udq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtps2uqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtqq2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtqq2ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtqq2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtsd2sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtsd2usi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtsh2sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtsh2si(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtsh2ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtsh2usi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtsi2sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtss2sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtss2usi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttpd2qq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttpd2udq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttpd2uqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttph2dq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttph2qq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttph2udq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttph2uqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttph2uw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttph2w(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttps2qq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttps2udq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttps2uqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttsd2usi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttsh2si(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttsh2usi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvttss2usi(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtudq2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtudq2ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtudq2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtuqq2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtuqq2ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtuqq2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtusi2sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtusi2sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtusi2ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtuw2ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vcvtw2ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vdbpsadbw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vdivph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vdivsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vdpbf16ps(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_verr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_verw(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vexpandpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vexpandps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextractf128(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextractf32x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextractf32x8(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextractf64x2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextractf64x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextracti128(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextracti32x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextracti32x8(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextracti64x2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vextracti64x4(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vfcmaddcph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfcmaddcsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfcmulcph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfcmulcsh(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vfixupimmpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfixupimmps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfixupimmsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfixupimmss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd132pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd132ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd132ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd132sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd132sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd132ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd213pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd213ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd213ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd213sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd213sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd213ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd231pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd231ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd231ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd231sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd231sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmadd231ss(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vfmaddcph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddcsh(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vfmaddrnd231pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub132pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub132ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub132ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub213pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub213ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub213ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub231pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub231ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmaddsub231ps(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vfmsub132pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub132ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub132ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub132sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub132sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub132ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub213pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub213ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub213ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub213sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub213sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub213ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub231pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub231ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub231ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub231sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub231sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsub231ss(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vfmsubadd132pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsubadd132ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsubadd132ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsubadd213pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsubadd213ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsubadd213ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsubadd231pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsubadd231ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmsubadd231ps(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vfmulcph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfmulcsh(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_vfnmadd132pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd132ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd132ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd132sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd132sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd132ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd213pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd213ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd213ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd213sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd213sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd213ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd231pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd231ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd231ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd231sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd231sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmadd231ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub132pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub132ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub132ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub132sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub132sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub132ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub213pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub213ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub213ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub213sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub213sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub213ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub231pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub231ph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub231ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub231sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub231sh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfnmsub231ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfpclasspd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfpclassph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfpclassps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfpclasssd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfpclasssh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vfpclassss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherdpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherdpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherdps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherdps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherqpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherqpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherqps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherqps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetexppd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetexpph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetexpps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetexpsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetexpsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetexpss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetmantpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetmantph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetmantps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetmantsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetmantsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgetmantss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinsertf128(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinsertf32x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinsertf32x8(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinsertf64x2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinsertf64x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinserti128(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinserti32x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinserti32x8(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinserti64x2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vinserti64x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmaskmov(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmaxph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmaxsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vminph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vminsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmovdqa32(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmovdqa64(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmovdqu16(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmovdqu32(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmovdqu64(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmovdqu8(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmovsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmovw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmulph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmulsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vp2intersectd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vp2intersectq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpblendd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpblendmb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpblendmd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpblendmq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpblendmw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpbroadcast(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpbroadcastb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpbroadcastd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpbroadcastm(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpbroadcastq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpbroadcastw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcmpb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcmpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcmpq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcmpub(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcmpud(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcmpuq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcmpuw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcmpw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcompressb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcompressd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpcompressq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpconflictd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpconflictq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpdpbusd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpdpbusds(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpdpwssd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpdpwssds(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vperm2f128(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vperm2i128(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermi2b(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermi2d(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermi2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermi2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermi2q(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermi2w(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermilpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermilps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermt2b(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermt2d(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermt2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermt2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermt2q(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermt2w(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpermw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpexpandb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpexpandd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpexpandq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpexpandw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpgatherdd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpgatherdd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpgatherdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpgatherdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpgatherqd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpgatherqd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpgatherqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpgatherqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vplzcntd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vplzcntq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmadd52huq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmadd52luq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmaskmov(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovb2m(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovd2m(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovdb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovdw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovm2b(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovm2d(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovm2q(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovm2w(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovq2m(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovqb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovqd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovqw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovsdb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovsdw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovsqb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovsqd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovsqw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovswb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovusdb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovusdw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovusqb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovusqd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovusqw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovuswb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovw2m(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmovwb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpmultishiftqb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpopcnt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vprold(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vprolq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vprolvd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vprolvq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vprord(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vprorq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vprorvd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vprorvq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpscatterdd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpscatterdq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpscatterqd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpscatterqq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpshld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpshldv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpshrd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpshrdv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpshufbitqmb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsllvd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsllvq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsllvw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsravd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsravq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsravw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsrlvd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsrlvq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpsrlvw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpternlogd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vpternlogq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vptestmb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vptestmd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vptestmq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vptestmw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vptestnmb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vptestnmd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vptestnmq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vptestnmw(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrangepd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrangeps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrangesd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrangess(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcp14pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcp14ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcp14sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcp14ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcpph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcpsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vreducepd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vreduceph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vreduceps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vreducesd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vreducesh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vreducess(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrndscalepd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrndscaleph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrndscaleps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrndscalesd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrndscalesh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrndscaless(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrt14pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrt14ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrt14sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrt14ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrtph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrtsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscalefpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscalefph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscalefps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscalefsd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscalefsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscalefss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterdpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterdps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterqpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterqps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vshuff32x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vshuff64x2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vshufi32x4(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vshufi64x2(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vsqrtph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vsqrtsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vsubph(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vsubsh(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vtestpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vtestps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vucomish(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vzeroall(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vzeroupper(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wait(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wbinvd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wbnoinvd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wrfsbase(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wrgsbase(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wrmsr(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wrpkru(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wrssd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wrssq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wrussd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_wrussq(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xabort(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xacquire(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xadd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xbegin(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xchg(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xend(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xgetbv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xlat(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xlatb(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xor(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xorpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xorps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xrelease(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xresldtrk(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xrstor(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xrstors(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xsave(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xsavec(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xsaveopt(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xsaves(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xsetbv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xsusldtrk(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_xtest(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_sgx(Mirtille_VirtualMachine *me){
//
/*

*/
}




void me_op_encls(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_eadd_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_eaug_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_eblock_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_ecreate_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_edbgrd_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_edbgwr_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_eextend_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_einit_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_eldbc_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_eldb_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_elduc_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_eldu_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_emodpr_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_emodt_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_epa_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_erdinfo_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_eremove_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_etrackc_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_etrack_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_encls_ewb_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_eacceptcopy_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_eaccept_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_edeccssa_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_eenter_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_eexit_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_egetkey_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_emodpe_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_ereport_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclu_eresume_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclv(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclv_edecvirtchild_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclv_eincvirtchild_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_enclv_esetcontext_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_smx(Mirtille_VirtualMachine *me){
//
/*

*/
}




void me_op_getsec_capabilities_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_getsec_enteraccs_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_getsec_exitac_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_getsec_parameters_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_getsec_senter_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_getsec_sexit_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_getsec_smctrl_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_getsec_wakeup_(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmx(Mirtille_VirtualMachine *me){
//
/*

*/
}




void me_op_invept(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_invvpid(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmcall(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmclear(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmfunc(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmlaunch(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmptrld(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmptrst(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmread(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmresume(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmresume(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmwrite(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmxoff(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vmxon(Mirtille_VirtualMachine *me){
//
/*

*/
}



void me_op_prefetchwt1(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_v4fmaddps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_v4fmaddss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_v4fnmaddps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_v4fnmaddss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vexp2pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vexp2ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherpf0dpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherpf0dps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherpf0qpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherpf0qps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherpf1dpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherpf1dps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherpf1qpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vgatherpf1qps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vp4dpwssd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vp4dpwssds(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcp28pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcp28ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcp28sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrcp28ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrt28pd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrt28ps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrt28sd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vrsqrt28ss(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterpf0dpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterpf0dps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterpf0qpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterpf0qps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterpf1dpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterpf1dps(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterpf1qpd(Mirtille_VirtualMachine *me){
//
/*

*/
}


void me_op_vscatterpf1qps(Mirtille_VirtualMachine *me){
//
/*

*/
}