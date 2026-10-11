#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004807A0_arg0 {
    char pad0[0x78];
    s32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
};

void func_004807A0(struct func_004807A0_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    arg0->unk78 = 1;
    arg0->unk7C = (f32) arg2;
    arg0->unk80 = (f32) arg3;
    arg0->unk84 = (f32) arg4;
    arg0->unk88 = (f32) arg5;
}
