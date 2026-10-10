#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0069DC80[];
void hModule__structor_0(s32, s32);
void func_00309348(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void HModule__dynamicAssign(s32 arg0, s32 arg1) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x2C, 4, D_0069DC80);
    hModule__structor_0(temp_v0, arg1);
    sp[0] = temp_v0;
    func_00309348(arg0, sp);
}
