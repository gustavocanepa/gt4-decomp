#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0057F238(s32, s32);
struct func_0042AC18_arg0 {
    s32 unk0;
    char pad4[0x4];
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

void func_0042AC18(struct func_0042AC18_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    if ((arg0->unk18 == 3) && (func_0057F238(arg1, arg0->unk14) == 0)) {
        arg0->unk1C = 1;
        arg0->unk8 = fparg0;
        arg0->unkC = fparg1;
        arg0->unk10 = fparg2;
        arg0->unk0 = 1;
    }
}
