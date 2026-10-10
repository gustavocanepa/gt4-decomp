/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0051BE28();                                /* extern */
s32 func_0051BE60();                            /* extern */

extern char D_0064B4B0[];
s32 func_0051CBF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s0;
    s32 var_v0;

    var_v0 = func_0051BE28();
    if (var_v0 == 0) {
        temp_s0 = M2C_FIELD(*(void **)D_0064B4B0, s32 (**)(), 0x54)();
        func_0051BE60();
        var_v0 = temp_s0;
    }
    return var_v0;
}
