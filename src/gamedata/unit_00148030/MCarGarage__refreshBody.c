#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_0013BD68(void *, s32);
void func_0013BDC0(void *);
s32 func_00147D80(s32);
void func_00343A58(s32);
void MCarGarage__refreshBody(void) {
    s32 sp[4];
    s32 temp_s0;
    func_0013BDC0(sp);
    temp_s0 = func_00147D80(sp[0]) + 0x4A0;
    func_0013BD68(sp, 2);
    func_00343A58(temp_s0);
}
