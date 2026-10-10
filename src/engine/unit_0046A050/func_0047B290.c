#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00480638(void *, s32);                 /* extern */
s32 func_00480FA0(s32, s32);                    /* extern */

struct func_0047B290_arg1 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    s32 unk70;
};

s32 *func_0047B290(s32 *arg0, struct func_0047B290_arg1 *arg1, s32 arg2, s32 arg3) {
    func_00480FA0(arg3, arg2);
    func_00480638(arg1, arg1->unk64 - 1);
    arg1->unk70 = 1;
    *arg0 = 1;
    return arg0;
}
