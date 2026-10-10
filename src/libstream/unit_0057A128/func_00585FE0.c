/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0058B2A0(s32, s32);                    /* extern */
s32 func_005B72A8();                                /* extern */
s32 func_005B72F8();                            /* extern */

s32 func_00585FE0(s32 arg0) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = func_005B72A8();
    temp_s0 = func_0058B2A0(arg0, 0);
    if (temp_s1 != 0) {
        func_005B72F8();
    }
    return temp_s0;
}
