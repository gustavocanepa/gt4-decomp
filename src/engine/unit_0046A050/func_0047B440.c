#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_004807E0(s32);
void func_00480FA0(s32, s32);
s32 *func_0047B440(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00480FA0(arg3, arg2);
    func_004807E0(arg1);
    *arg0 = 1;
    return arg0;
}
