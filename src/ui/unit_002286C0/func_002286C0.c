#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_006983B8[];
void mProgress__structor_0(s32);
void func_00309348(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_002286C0(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x2C, 4, D_006983B8);
    mProgress__structor_0(temp_v0);
    sp[0] = temp_v0;
    func_00309348(arg0, sp);
}
