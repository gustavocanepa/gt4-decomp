#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0039A530_arg0 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    char pad10[0x4];
    f32 unk14;
    f32 unk18;
};

void func_0039A530(struct func_0039A530_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk0 = arg1;
    arg0->unk14 = fparg2;
    arg0->unk4 = fparg0;
    arg0->unkC = fparg1;
    arg0->unk8 = (f32) (fparg0 + fparg1);
    arg0->unk18 = fparg3;
}
