#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_0038CDE8(s32, f32);                        /* extern */
void *func_0038D0C0(s32);                           /* extern */
s32 func_0044F4C0();                                /* extern */
f32 func_0044F9A0(s32);                             /* extern */

struct func_0038D130_temp_s0 {
    char pad0[0x34];
    f32 unk34;
};

f32 func_0038D130(s32 arg0, s32 arg1, f32 fparg0) {
    f32 var_f20;
    s32 temp_v0;
    struct func_0038D130_temp_s0 *temp_s0;

    temp_v0 = func_0044F4C0();
    if (temp_v0 != 0) {
        var_f20 = func_0044F9A0(temp_v0);
    } else {
        var_f20 = 0.0f;
    }
    if (arg1 != 0) {
        return M2C_FIELD(func_0038D0C0(arg0), f32 *, 0x34) + var_f20;
    }
    temp_s0 = func_0038D0C0(arg0);
    return temp_s0->unk34 + func_0038CDE8(arg0, fparg0);
}
