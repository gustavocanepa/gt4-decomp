#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00575FB0(s32, s32);                        /* extern */
s32 func_0057F260(s32);                             /* extern */
s32 func_005A4724(s32, s32, s32);               /* extern */

s32 func_005A6250(s32 arg0, s32 arg1) {
    s32 temp_s2;
    s32 temp_v0;

    temp_s2 = func_0057F260(arg1) + 1;
    temp_v0 = func_00575FB0(arg0, temp_s2);
    if (temp_v0 != 0) {
        func_005A4724(temp_v0, arg1, temp_s2);
    }
    return temp_v0;
}
