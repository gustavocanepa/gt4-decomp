#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00442D60_arg1 {
    char pad0[0xB8];
    u16 unkB8;
    u16 unkBA;
    char padBC[0xA5];
    u8 unk161;
    char pad162[0x12];
    s16 unk174;
    s16 unk176;
};
struct func_00442D60_arg2 {
    char pad0[0x3];
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

void func_00442D60(s32 arg0, struct func_00442D60_arg1 *arg1, struct func_00442D60_arg2 *arg2) {
    arg1->unkBA = (u16) ((s32) (arg1->unkBA * arg2->unk4) / 100);
    arg1->unkB8 = (u16) ((s32) (arg1->unkB8 * arg2->unk3) / 100);
    arg1->unk174 = (s16) ((s32) (arg1->unk174 * arg2->unk5) / 100);
    arg1->unk176 = (s16) ((s32) (arg1->unk176 * arg2->unk6) / 100);
    arg1->unk161 = (u8) arg2->unk7;
}
