#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0069D9F8[];
void hInt__structor_0(s32, s32);
void func_00309348(s32, s32 *);
s32 func_00326750(s32, s32, void *);
void func_002FE2E0(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_00326750(0x14, 4, D_0069D9F8);
    hInt__structor_0(temp_v0, 0);
    sp[0] = temp_v0;
    func_00309348(arg0, sp);
}
