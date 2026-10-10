#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005725A8(s32, s32, s32);           /* extern */
s32 func_005A48D8(s32, s32, s32);           /* extern */

extern char D_008744D0[];
s32 func_00575D40(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 * arg1;
    temp_v0 = func_005725A8((s32)D_008744D0, temp_s0, 0x10);
    if (temp_v0 != 0) {
        func_005A48D8(temp_v0, 0, temp_s0);
    }
    return temp_v0;
}
