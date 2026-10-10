/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578168(void *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */
s32 func_005A609C(void *, s32);                 /* extern */

struct func_00610300_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s8 unk4C;
};

void func_00610300(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_00578500(((struct func_00610300_arg0 *)arg0)->unk0);
    ((struct func_00610300_arg0 *)arg0)->unk40 = arg1;
    ((struct func_00610300_arg0 *)arg0)->unk44 = arg2;
    ((struct func_00610300_arg0 *)arg0)->unk48 = arg3;
    ((struct func_00610300_arg0 *)arg0)->unk4C = 0;
    if (arg4 != 0) {
        func_005A609C(arg0 + 0x4C, arg4);
    }
    func_00578168(arg0, 1, 0, 0, 0);
}
