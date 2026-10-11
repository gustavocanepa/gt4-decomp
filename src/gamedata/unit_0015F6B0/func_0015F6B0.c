#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_006901E0[];
void mGame__structor_0(s32, s32);
void func_00309348(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_0015F6B0(s32 arg0, s32 arg1) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x18, 4, D_006901E0);
    mGame__structor_0(temp_v0, arg1);
    sp[0] = temp_v0;
    func_00309348(arg0, sp);
}
