#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00575E60(s32, s32);                    /* extern */
s32 func_005ADF20(s32);                     /* extern */

s32 func_00562778(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_00575E60(0x80, ((u32) (arg0 + 0x3F) >> 6) << 6);
    func_005ADF20(0);
    return temp_s0;
}
