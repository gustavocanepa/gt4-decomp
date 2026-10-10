#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578CF0(s32, s32);                    /* extern */
s32 func_005A48D8(s32, s32, s32);           /* extern */

s32 func_001C1620(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = ((arg0 + 0x7F) & ~0x7F) + 0x80;
    temp_v0 = func_00578CF0(0x80, temp_s0);
    func_005A48D8(temp_v0, 0, temp_s0);
    return temp_v0;
}
