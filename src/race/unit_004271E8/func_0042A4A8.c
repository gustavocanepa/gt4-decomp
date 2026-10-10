#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00422A20(f32);                             /* extern */

struct func_0042A4A8_arg0 {
    char pad0[0x8];
    f32 unk8;
};

f32 func_0042A4A8(struct func_0042A4A8_arg0 *arg0, f32 fparg0) {
    f32 temp_f21;
    f32 var_f20;

    temp_f21 = arg0->unk8;
    var_f20 = fparg0 - 0.0f;
    if (temp_f21 != 0.0f) {
        var_f20 -= temp_f21 * (f32) func_00422A20(var_f20 / temp_f21);
    }
    return var_f20 + 0.0f;
}
