#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00579330(s32);                         /* extern */
s64 func_005B8450();                                /* extern */

extern char D_00874D50[];
s32 func_00579358(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s64 temp_s0;

    temp_s0 = (s64) (func_005B8450() << 0x20) >> 0x20;
    return func_00579330((s32)D_00874D50) + temp_s0;
}
