#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001C1620(s32);
struct func_001C2030_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_001C2030(struct func_001C2030_arg0 *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;

    temp_v0 = (arg0->unk0 + 0xF) & ~0xF;
    arg0->unk8 = temp_v0;
    temp_a0 = ((temp_v0 * arg0->unk4) + 0x7F) & ~0x7F;
    arg0->unkC = temp_a0;
    temp_v0_2 = func_001C1620(temp_a0 * 3);
    temp_v1 = arg0->unkC;
    arg0->unk10 = temp_v0_2;
    temp_v0_3 = temp_v0_2 + temp_v1;
    arg0->unk14 = temp_v0_3;
    arg0->unk18 = (s32) (temp_v0_3 + temp_v1);
}
