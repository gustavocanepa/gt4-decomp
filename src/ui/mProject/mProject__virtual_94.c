#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00211408(void *, s32);
void func_002117A0(void *);
s32 func_00213158(s32);
void func_0025A810(s32, void *);
void func_0026A118(void *, s32);
void func_0026B020(void *, s32, s32);
void mProject__virtual_94(s32 arg0, s32 arg1) {
    s32 sp[4];
    s32 temp_s0;
    func_002117A0(sp);
    temp_s0 = func_00213158(sp[0]);
    func_00211408(sp, 2);
    func_0026B020(sp, temp_s0, arg1);
    func_0025A810(arg1, sp);
    func_0026A118(sp, 2);
}
