#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003337D8();                            /* extern */

struct func_003335F8_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
    s32 unk18;
};

void func_003335F8(struct func_003335F8_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0) {
    func_003337D8();
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
    arg0->unkC = arg3;
    arg0->unk10 = arg4;
    arg0->unk14 = fparg0;
    arg0->unk18 = arg5;
}
