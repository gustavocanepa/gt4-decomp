#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005544E8(s32, s32, s32, s32, s32, s32, s32); /* extern */

struct func_005D0ED8_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_005D0ED8(struct func_005D0ED8_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_005544E8(arg0->unk4, arg0->unk8, arg0->unkC, arg1, arg2, arg3, arg4);
}
