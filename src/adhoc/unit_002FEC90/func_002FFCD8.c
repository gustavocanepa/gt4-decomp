#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_002FFAF0(s32, s32);                    /* extern */
s32 func_002FFB18(s32, s32);                    /* extern */
s32 func_005DB110(s32, s32);            /* extern */

s32 func_002FFCD8(s32 arg0, void **arg1) {
    s8 var_a1;
    u32 var_s0;
    u32 var_s1;
    void *temp_v0;

    var_s1 = M2C_FIELD(*arg1, u32 *, -0x10);
    if (var_s1 > 0xFFFFU) {
        var_s1 = 0xFFFF;
        func_005DB110((s32)"WARNING: It is a too long string. truncate at %d character\012", 0xFFFF);
    }
    func_002FFB18(arg0, var_s1 & 0xFFFF);
    var_s0 = 0;
    if (var_s1 != 0) {
        do {
            temp_v0 = *arg1;
            var_a1 = 0;
            if (var_s0 != M2C_FIELD(temp_v0, u32 *, -0x10)) {
                var_a1 = *(s8 *)(temp_v0 + var_s0);
            }
            func_002FFAF0(arg0, var_a1 & 0xFF);
            var_s0 += 1;
        } while (var_s0 < var_s1);
    }
    return arg0;
}
