#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_0038D0C0(s32);                           /* extern */
s32 func_0044F4C0();                                /* extern */
f32 func_0044F9B0(s32);                             /* extern */

f32 NormalCarGeometry__virtual_27(s32 arg0) {
    f32 var_f20;
    s32 temp_v0;

    temp_v0 = func_0044F4C0();
    if (temp_v0 != 0) {
        var_f20 = func_0044F9B0(temp_v0);
    } else {
        var_f20 = 0.0f;
    }
    return M2C_FIELD(func_0038D0C0(arg0), f32 *, 0x40) + var_f20;
}
