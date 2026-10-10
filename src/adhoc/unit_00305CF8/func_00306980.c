#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00306848(s32, void *, s32, s32);
s32 func_003166B8(s32);
void func_00306980(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp[4];
    sp[0] = func_003166B8(arg1);
    func_00306848(arg0, sp, arg2, arg3);
}
