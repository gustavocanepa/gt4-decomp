#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A48D8(s32, s32, s32);           /* extern */

s32 func_0050A5A0(s32 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_005A48D8(temp_v0, 0, arg1 * 4);
    }
    return 0;
}
