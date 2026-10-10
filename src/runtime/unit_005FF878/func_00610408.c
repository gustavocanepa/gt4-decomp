/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578168(void *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */

struct func_00610408_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s64 unk40;
    s64 unk48;
};

void func_00610408(struct func_00610408_arg0 *arg0, s64 arg1, s64 arg2) {
    func_00578500(arg0->unk0);
    arg0->unk40 = arg1;
    arg0->unk48 = arg2;
    func_00578168(arg0, 3, 1, 0, 0);
}
