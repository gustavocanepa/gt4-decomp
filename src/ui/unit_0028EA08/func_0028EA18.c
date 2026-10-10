#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003284E8(s32);                             /* extern */

s32 func_0028EA18(void *arg0) {
    s32 temp_v0;
    s32 var_s1;
    s32 var_v0;
    s32 *s0;

    var_s1 = 0;
    s0 = (s32 *)((char *)arg0 + 0x1C);
    temp_v0 = *s0;
    if ((temp_v0 == 0) || (func_003284E8(temp_v0) == 0)) {
        var_s1 = 1;
    }
    var_v0 = 0;
    if (var_s1 == 0) {
        var_v0 = *s0;
    }
    return var_v0;
}
