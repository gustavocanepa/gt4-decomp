#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s16 func_0057F260();                             /* extern */
s32 func_005A4724(void *, s32, s16);            /* extern */

struct func_0050F358_arg2 {
    char pad0[0x64];
    s16 unk64;
};

s32 func_0050F358(s32 arg0, s32 arg1, struct func_0050F358_arg2 *arg2) {
    func_005A4724(arg2, arg0, func_0057F260());
    arg2->unk64 = func_0057F260(arg0);
    return 0;
}
