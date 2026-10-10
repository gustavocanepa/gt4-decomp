#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0056F3E0(void *, s32, s32, s32);       /* extern */

struct func_004EFA40_arg0 {
    char pad0[0x80];
    s32 unk80;
};

void func_004EFA40(void *arg0, s32 arg1, s32 arg2) {
    func_0056F3E0(arg0 + 0x40, ((struct func_004EFA40_arg0 *)arg0)->unk80, arg1, arg2);
}
