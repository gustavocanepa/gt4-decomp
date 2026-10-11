#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00442AE8_arg1 {
    char pad0[0xBD];
    u8 unkBD;
    char padBE[0x2];
    u8 unkC0;
    u8 unkC1;
    u8 unkC2;
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
    u8 unkC8;
    u8 unkC9;
    u8 unkCA;
    u8 unkCB;
    u8 unkCC;
    u8 unkCD;
    u8 unkCE;
    u8 unkCF;
    char padD0[0x3A];
    u16 unk10A;
    u8 unk10C;
};
struct func_00442AE8_arg2 {
    char pad0[0x4];
    u16 unk4;
    u16 unk6;
    char pad8[0x1];
    u8 unk9;
    u8 unkA;
};

void func_00442AE8(s32 arg0, struct func_00442AE8_arg1 *arg1, struct func_00442AE8_arg2 *arg2) {
    arg1->unkC0 = (u8) (arg1->unkC0 + arg2->unk9);
    arg1->unkC1 = (u8) (arg1->unkC1 + arg2->unk9);
    arg1->unkC2 = (u8) (arg1->unkC2 + arg2->unk9);
    arg1->unkC3 = (u8) (arg1->unkC3 + arg2->unk9);
    arg1->unkC4 = (u8) (arg1->unkC4 + arg2->unk9);
    arg1->unkC5 = (u8) (arg1->unkC5 + arg2->unk9);
    arg1->unkC6 = (u8) (arg1->unkC6 + arg2->unk9);
    arg1->unkC7 = (u8) (arg1->unkC7 + arg2->unk9);
    arg1->unkC8 = (u8) (arg1->unkC8 + arg2->unk9);
    arg1->unkC9 = (u8) (arg1->unkC9 + arg2->unk9);
    arg1->unkCA = (u8) (arg1->unkCA + arg2->unk9);
    arg1->unkCB = (u8) (arg1->unkCB + arg2->unk9);
    arg1->unkCC = (u8) (arg1->unkCC + arg2->unk9);
    arg1->unkCD = (u8) (arg1->unkCD + arg2->unk9);
    arg1->unkCE = (u8) (arg1->unkCE + arg2->unk9);
    arg1->unkCF = (u8) (arg1->unkCF + arg2->unk9);
    arg1->unkBD = (u8) (arg1->unkBD + arg2->unkA);
    arg1->unk10A = (u16) ((s32) (arg1->unk10A * arg2->unk4) / 100);
    arg1->unk10C = (u8) ((s32) (arg1->unk10C * arg2->unk6) / 100);
}
