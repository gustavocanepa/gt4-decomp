#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00578CF0(s32, s32);                    /* extern */
s32 func_005A48D8(s32, s32, s32);           /* extern */

s32 func_00567EC0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_00578CF0(0x10, arg0);
    func_005A48D8(temp_v0, 0, arg0);
    return temp_v0;
}
