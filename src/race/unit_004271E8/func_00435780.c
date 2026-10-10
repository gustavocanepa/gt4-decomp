#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00434F78(s32, s32, s32, s32);          /* extern */
s32 func_00435348();                                /* extern */

s32 func_00435780(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    temp_v0 = func_00435348();
    if (temp_v0 >= 0) {
        func_00434F78(arg0 + (temp_v0 << 5) + 8, arg1, arg2, arg3);
    }
    return temp_v0;
}
