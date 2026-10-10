/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578168(void *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */

struct func_0060FEB8_arg0 {
    s32 unk0;
    char pad4[0x7C];
    s32 unk80;
    s32 unk84;
};

void func_0060FEB8(struct func_0060FEB8_arg0 *arg0, s32 arg1, s32 arg2) {
    func_00578500(arg0->unk0);
    arg0->unk80 = arg1;
    arg0->unk84 = arg2;
    func_00578168(arg0, 2, 1, 0, 0);
}
