/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576AD8(s32, s32);                    /* extern */
s32 func_00578168(void *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */

struct func_00610398_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
    s32 unk44;
};

void func_00610398(struct func_00610398_arg0 *arg0, s32 arg1, s32 arg2) {
    func_00578500(arg0->unk0);
    arg0->unk40 = arg1;
    arg0->unk44 = arg2;
    func_00576AD8(arg1, arg2);
    func_00578168(arg0, 2, 0, 0, 0);
}
