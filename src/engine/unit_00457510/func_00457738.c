#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_004576C0(s32, s32);
void func_00457738(s32 arg0, s32 arg1) {
    s32 var_s0;
    u32 var_s1;
    var_s0 = 0;
    var_s1 = 0;
    do {
        var_s1 += 1;
        func_004576C0(arg0 + var_s0, arg1 + var_s0);
        var_s0 += 0xC;
    } while (var_s1 < 5U);
}
