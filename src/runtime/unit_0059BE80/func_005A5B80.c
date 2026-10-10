#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s64 func_005AD4F0(s32, s16, s32, s32);              /* extern */

struct func_005A5B80_arg0 {
    char pad0[0xC];
    u16 unkC;
    s16 unkE;
    char pad10[0x40];
    s32 unk50;
    s32 unk54;
};

s64 func_005A5B80(struct func_005A5B80_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;

    temp_a0 = (s64) (func_005AD4F0(arg0->unk54, arg0->unkE, arg1, arg2) << 0x20) >> 0x20;
    if (temp_a0 >= 0) {
        arg0->unk50 = (s32) (arg0->unk50 + temp_a0);
        return temp_a0;
    }
    arg0->unkC = (u16) (arg0->unkC & 0xEFFF);
    return temp_a0;
}
