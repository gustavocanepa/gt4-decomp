#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00693C80[];
void mGTShirtPS2__structor_0(s32);
void func_001B9BB8(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_001C4268(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x32C, 4, D_00693C80);
    mGTShirtPS2__structor_0(temp_v0);
    sp[0] = temp_v0;
    func_001B9BB8(arg0, sp);
}
