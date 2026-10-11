#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00697328[];
void mColorObject__structor_1(s32, s32);
void func_00309348(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_00204558(s32 arg0, s32 arg1) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x20, 4, D_00697328);
    mColorObject__structor_1(temp_v0, arg1);
    sp[0] = temp_v0;
    func_00309348(arg0, sp);
}
