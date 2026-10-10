#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00532550(s8, s32, s32, s32, s32, s32);     /* extern */
s32 func_00535780(s32);                             /* extern */
s32 func_00536CF8();                                /* extern */
s32 func_00536D38();                                /* extern */

s32 func_0052EC88(s8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_00535780(func_00536CF8());
    if (var_v0 == 0) {
        temp_s0 = func_00532550(arg0, arg1, arg2, arg3, arg4, arg5);
        temp_v0 = func_00535780(func_00536D38());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
