#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern f32 D_00620E6C[];
struct func_0036F5C0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0036F5C0(struct func_0036F5C0_arg0 *arg0, s32 arg1) {
    if (arg1 <= 0) arg1 = 1;
    if (arg1 > 16) arg1 = 16;
    arg0->unk4 = D_00620E6C[arg1] * 100.0f;
}
