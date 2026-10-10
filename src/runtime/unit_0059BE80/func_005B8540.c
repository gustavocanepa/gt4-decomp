/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005B72A8();                                /* extern */
s32 func_005B72F8();                            /* extern */
s32 func_005B84D0();                                /* extern */

s32 func_005B8540(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s0 = func_005B72A8();
    temp_s1 = func_005B84D0();
    if (temp_s0 != 0) {
        func_005B72F8();
    }
    return temp_s1;
}
