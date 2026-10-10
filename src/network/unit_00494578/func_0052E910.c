#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00531590(s32);                             /* extern */
s32 func_00535780(s32);                             /* extern */
s32 func_00536CF8();                                /* extern */
s32 func_00536D38();                                /* extern */

s32 func_0052E910(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != 0) {
        var_v0 = func_00535780(func_00536CF8());
        if (var_v0 == 0) {
            temp_s0 = func_00531590(arg0);
            temp_v0 = func_00535780(func_00536D38());
            var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
        }
    }
    return var_v0;
}
