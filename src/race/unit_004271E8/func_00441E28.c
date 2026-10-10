#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00441E28_arg1 {
    char pad0[0xB8];
    u16 unkB8;
    u16 unkBA;
    char padBC[0x6C];
    u8 unk128;
    u8 unk129;
    u8 unk12A;
    char pad12B[0x39];
    u16 unk164;
    u16 unk166;
    char pad168[0xC];
    u16 unk174;
    u16 unk176;
};
struct func_00441E28_arg2 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    char padC[0x4];
    u8 unk10;
    u8 unk11;
    char pad12[0x2];
    u8 unk14;
};

void func_00441E28(s32 arg0, struct func_00441E28_arg1 *arg1, struct func_00441E28_arg2 *arg2) {
    arg1->unk12A = (u8) arg2->unk14;
    arg1->unk128 = (u8) arg2->unk10;
    arg1->unk129 = (u8) arg2->unk11;
    arg1->unkBA = (u16) arg2->unk2;
    arg1->unk174 = (u16) arg2->unk4;
    arg1->unk176 = (u16) arg2->unk6;
    arg1->unk164 = (u16) arg2->unk8;
    arg1->unk166 = (u16) arg2->unkA;
    arg1->unkB8 = (u16) arg2->unk0;
}
