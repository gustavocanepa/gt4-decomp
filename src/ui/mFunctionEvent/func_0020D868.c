#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00697768[];
void mFunctionEvent__structor_0(s32, s32, s32);
void func_0028E348(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_0020D868(s32 arg0, s32 arg1) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x34, 4, D_00697768);
    mFunctionEvent__structor_0(temp_v0, arg1, 0);
    sp[0] = temp_v0;
    func_0028E348(arg0, sp);
}
