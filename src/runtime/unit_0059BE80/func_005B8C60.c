/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005B72A8();                                /* extern */
s32 func_005B72F8();                            /* extern */
s32 func_005B8B68(s32, s32, s32, s32);              /* extern */

s32 func_005B8C60(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;
    s32 temp_s4;

    temp_s4 = func_005B72A8();
    temp_s0 = func_005B8B68(arg0, arg1, arg2, arg3);
    if (temp_s4 != 0) {
        func_005B72F8();
    }
    return temp_s0;
}
