/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0051BE28();                                /* extern */
s32 func_0051BE60();                            /* extern */

extern char D_0064B4B0[];
s32 func_0051C7F0(s32 arg0) {
    s32 temp_s0;
    s32 var_v0;

    var_v0 = func_0051BE28();
    if (var_v0 == 0) {
        temp_s0 = M2C_FIELD(*(void **)D_0064B4B0, s32 (**)(s32), 0x44)(arg0);
        func_0051BE60();
        var_v0 = temp_s0;
    }
    return var_v0;
}
