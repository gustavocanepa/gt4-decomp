#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003F1F78();                                /* extern */

struct func_003F1FB0_arg0 {
    char pad0[0x2];
    u8 unk2;
    char pad3[0x2D];
    u16 unk30;
};

s32 func_003F1FB0(void *arg0, f32 *arg1, f32 *arg2) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f3;
    s32 var_v0;

    var_v0 = func_003F1F78();
    if (var_v0 != 0) {
        temp_f3 = *arg1;
        temp_f0 = (f32) ((struct func_003F1FB0_arg0 *)arg0)->unk30 * 0x1.acee9c0000000p-4f;
        if (temp_f3 < temp_f0) {
            *arg2 = 0x1.0000000000000p+0f;
        } else {
            temp_f0_2 = temp_f0 / temp_f3;
            *arg2 = temp_f0_2;
            temp_f2 = M2C_FIELD(((((struct func_003F1FB0_arg0 *)arg0)->unk2 * 4) + arg0), f32 *, 0x40);
            if (temp_f0_2 < temp_f2) {
                *arg2 = temp_f2;
            }
            *arg1 = *arg2 * temp_f3;
        }
        var_v0 = 1;
    }
    return var_v0;
}
