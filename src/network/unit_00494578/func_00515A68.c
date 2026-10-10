/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00535780(s32);                             /* extern */
s32 func_00536CF8();                                /* extern */
s32 func_00536D38();                                /* extern */

extern char D_0064B4B4[];
s32 func_00515A68(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_00535780(func_00536CF8());
    if (var_v0 == 0) {
        temp_s0 = M2C_FIELD(*(void **)D_0064B4B4, s32 (**)(s32), 0x8C)(arg0);
        temp_v0 = func_00535780(func_00536D38());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
