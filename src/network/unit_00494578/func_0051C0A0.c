#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0051BE28();                                /* extern */
s32 func_0051BE60();                            /* extern */
s32 func_0051CCD0();                                /* extern */

s32 func_0051C0A0(void) {
    s32 temp_s0;
    s32 var_v0;

    var_v0 = func_0051BE28();
    if (var_v0 == 0) {
        temp_s0 = func_0051CCD0();
        func_0051BE60();
        var_v0 = temp_s0;
    }
    return var_v0;
}
