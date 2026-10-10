#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0047D130(s32 arg0, u32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg1 < 0x80U) {
        var_v0 = (M2C_FIELD((arg1 + arg0), u8 *, 0x1C) & 3) == 2;
    }
    return var_v0;
}
