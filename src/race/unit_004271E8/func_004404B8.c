#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004452A8(s32, s32, s32, s32);
s32 func_0043FFE0(void *, void *);                      /* extern */

struct func_004404B8_temp_s0 {
    char pad0[0x50];
    s64 unk50;
    char pad58[0xE1];
    s8 unk139;
    s8 unk13A;
    char pad13B[0x1];
    s16 unk13C;
    s16 unk13E;
    u8 unk140;
    u8 unk141;
    s8 unk142;
    s8 unk143;
    u8 unk144;
    u8 unk145;
    s8 unk146;
    s8 unk147;
    s8 unk148;
    s8 unk149;
    s8 unk14A;
    s8 unk14B;
    s8 unk14C;
    s8 unk14D;
    s8 unk14E;
    s8 unk14F;
};
struct func_004404B8_arg2 {
    char pad0[0x84];
    u16 unk84;
    u16 unk86;
    u16 unk88;
    u16 unk8A;
    u16 unk8C;
    u16 unk8E;
    char pad90[0x3];
    u8 unk93;
    u8 unk94;
    u8 unk95;
    u8 unk96;
    u8 unk97;
    u8 unk98;
    char pad99[0x14];
    u8 unkAD;
    char padAE[0x2];
    u8 unkB0;
    char padB1[0x7];
    u8 unkB8;
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    u8 unkBC;
    u8 unkBD;
    u8 unkBE;
    u8 unkBF;
    char padC0[0xC];
    u8 unkCC;
    char padCD[0x2];
    u8 unkCF;
    char padD0[0x2];
    u8 unkD2;
    u8 unkD3;
    char padD4[0x2];
    u8 unkD6;
    char padD7[0x2];
    u8 unkD9;
    u8 unkDA;
    char padDB[0x2];
    u8 unkDD;
    char padDE[0x2];
    u8 unkE0;
    u8 unkE1;
    char padE2[0x2];
    u8 unkE4;
    char padE5[0x2];
    u8 unkE7;
    char padE8[0x2];
    u8 unkEA;
    char padEB[0x2];
    u8 unkED;
    u8 unkEE;
    char padEF[0x2];
    u8 unkF1;
};

struct func_004404B8_arg0 {
    char pad0[0x490];
    s32 unk490;
};

void func_004404B8(void *arg0, s64 arg1, struct func_004404B8_arg2 *arg2) {
    u8 temp_s2;
    u8 temp_s2_2;
    u8 temp_s2_3;
    u8 temp_s2_4;
    struct func_004404B8_temp_s0 *temp_s0;

    temp_s0 = arg0 + (((struct func_004404B8_arg0 *)arg0)->unk490 * 0x178) + 8;
    temp_s0->unk50 = arg1;
    func_0043FFE0(arg0, arg2);
    temp_s0->unk140 = (u8) arg2->unkAD;
    temp_s0->unk141 = (u8) arg2->unkB0;
    temp_s0->unk139 = func_004452A8((s32) temp_s0, (s32) arg2->unk93, (s32) arg2->unk95, (s32) arg2->unk94);
    temp_s0->unk13A = func_004452A8((s32) temp_s0, (s32) arg2->unk96, (s32) arg2->unk98, (s32) arg2->unk97);
    temp_s0->unk13C = func_004452A8((s32) temp_s0, (s32) arg2->unk84, (s32) arg2->unk88, (s32) arg2->unk86);
    temp_s0->unk13E = func_004452A8((s32) temp_s0, (s32) arg2->unk8A, (s32) arg2->unk8E, (s32) arg2->unk8C);
    temp_s0->unk142 = func_004452A8((s32) temp_s0, (s32) arg2->unkB8, (s32) arg2->unkBA, (s32) arg2->unkB9);
    temp_s0->unk143 = func_004452A8((s32) temp_s0, (s32) arg2->unkBB, (s32) arg2->unkBD, (s32) arg2->unkBC);
    temp_s0->unk144 = (u8) arg2->unkBE;
    temp_s0->unk145 = (u8) arg2->unkBF;
    temp_s2 = arg2->unkCC;
    temp_s0->unk146 = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkCF, (s32) temp_s2);
    temp_s0->unk147 = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkD2, (s32) temp_s2);
    temp_s2_2 = arg2->unkD3;
    temp_s0->unk148 = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkD6, (s32) temp_s2_2);
    temp_s0->unk149 = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkD9, (s32) temp_s2_2);
    temp_s2_3 = arg2->unkDA;
    temp_s0->unk14A = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkDD, (s32) temp_s2_3);
    temp_s0->unk14B = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkE0, (s32) temp_s2_3);
    temp_s2_4 = arg2->unkE1;
    temp_s0->unk14C = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkE4, (s32) temp_s2_4);
    temp_s0->unk14D = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkE7, (s32) temp_s2_4);
    temp_s0->unk14E = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkED, (s32) arg2->unkEA);
    temp_s0->unk14F = func_004452A8((s32) temp_s0, 1, (s32) arg2->unkF1, (s32) arg2->unkEE);
}
