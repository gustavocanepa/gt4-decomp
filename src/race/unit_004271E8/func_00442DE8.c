#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00442DE8_arg1 {
    char pad0[0xBA];
    u16 unkBA;
    char padBC[0xA8];
    s16 unk164;
    s16 unk166;
    char pad168[0xC];
    s16 unk174;
    s16 unk176;
};
struct func_00442DE8_arg2 {
    char pad0[0x3];
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

void func_00442DE8(s32 arg0, struct func_00442DE8_arg1 *arg1, struct func_00442DE8_arg2 *arg2) {
    arg1->unkBA = (u16) ((s32) (arg1->unkBA * arg2->unk3) / 100);
    arg1->unk174 = (s16) ((s32) (arg1->unk174 * arg2->unk4) / 100);
    arg1->unk176 = (s16) ((s32) (arg1->unk176 * arg2->unk5) / 100);
    arg1->unk164 = (s16) ((s32) (arg1->unk164 * arg2->unk6) / 100);
    arg1->unk166 = (s16) ((s32) (arg1->unk166 * arg2->unk7) / 100);
}
