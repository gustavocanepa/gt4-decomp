/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578168(void *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */

struct func_00610538_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
    s32 unk44;
    s32 unk48;
};

void func_00610538(struct func_00610538_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_00578500(arg0->unk0);
    arg0->unk40 = arg2;
    arg0->unk44 = arg3;
    arg0->unk48 = arg4;
    func_00578168(arg0, arg1, 0, 0, 0);
}
