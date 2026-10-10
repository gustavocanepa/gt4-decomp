#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00576100(s32);                         /* extern */
s32 func_00576140(s32);                         /* extern */

struct func_00122CC0_arg0 {
    char pad0[0x2AC];
    s32 unk2AC;
    s32 unk2B0;
};

f32 func_00122CC0(void *arg0) {
    f32 var_f0;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = arg0 + 0x10;
    func_00576100(temp_s1);
    temp_s2 = ((struct func_00122CC0_arg0 *)arg0)->unk2AC;
    temp_s0 = ((struct func_00122CC0_arg0 *)arg0)->unk2B0;
    func_00576140(temp_s1);
    var_f0 = 0.0f;
    if (temp_s0 != 0) {
        var_f0 = (f32) temp_s2 / (f32) temp_s0;
    }
    return var_f0;
}
