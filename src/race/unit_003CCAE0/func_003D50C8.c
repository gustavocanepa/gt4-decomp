#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_003D3E80(void *, s32, s32, f32, s32, s32 *, s32, s32, s32); /* extern */

struct func_003D50C8_temp_v0 {
    char pad0[0xC];
    s32 unkC;
};

struct func_003D50C8_arg0 {
    char pad0[0x31C];
    s32 unk31C;
};

void func_003D50C8(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4, s32 arg5, f32 fparg0) {
    s32 temp_a0;
    s32 var_s0;
    struct func_003D50C8_temp_v0 *temp_v0;

    if (arg3 != NULL) {
        var_s0 = 0;
        if (*arg3 != 0) {
loop_3:
            temp_v0 = *arg3 + (((arg2 * 4) + var_s0) * 4);
            temp_a0 = var_s0 * 0x1D;
            var_s0 += 1;
            func_003D3E80(arg0 + (temp_a0 * 4), arg1, arg2, fparg0, temp_v0->unkC, arg3, arg4, arg5, ((struct func_003D50C8_arg0 *)arg0)->unk31C);
            if (var_s0 < 4) {
                goto loop_3;
            }
        }
    }
}
