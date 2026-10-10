/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578168(void *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */

struct func_0060FCA8_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
};

void func_0060FCA8(struct func_0060FCA8_arg0 *arg0, s32 arg1) {
    func_00578500(arg0->unk0);
    arg0->unk40 = arg1;
    func_00578168(arg0, 4, 0, 0, 0);
}
