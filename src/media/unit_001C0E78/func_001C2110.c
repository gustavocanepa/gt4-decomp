#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001C1620();                        /* extern */

struct func_001C2110_arg0 {
    char pad0[0x8];
    u32 unk8;
    char padC[0x4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

void func_001C2110(struct func_001C2110_arg0 *arg0, u32 arg1, u32 arg2) {
    s32 temp_a1;
    s32 temp_v1;
    u32 temp_v0;

    temp_v0 = (arg1 >= arg2) ? arg2 : arg1;
    temp_v1 = arg1 - temp_v0;
    temp_a1 = arg2 - temp_v0;
    arg0->unk14 = temp_a1;
    arg0->unk10 = temp_v1;
    arg0->unk8 = temp_v0;
    arg0->unk18 = func_001C1620(((temp_v0 + temp_v1 + temp_a1) * 4) + 4, temp_a1);
    arg0->unk1C = func_001C1620(((((arg1 + 0xF) & ~0xF) * arg2) + 0x7F) & ~0x7F);
}
