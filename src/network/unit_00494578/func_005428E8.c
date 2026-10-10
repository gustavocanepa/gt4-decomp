#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005428E8(s32 arg0) {
    s32 var_v0;
    u32 var_a2;
    u8 *temp_v0;

    var_v0 = 1;
    if (arg0 != 0) {
        var_a2 = 0;
loop_2:
        temp_v0 = arg0 + var_a2;
        var_a2 += 1;
        var_v0 = 0;
        if (*temp_v0 == 0) {
            if (var_a2 >= 0x40U) {
                var_v0 = 1;
            } else {
                goto loop_2;
            }
        }
    }
    return var_v0;
}
