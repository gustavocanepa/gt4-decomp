#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A48D8(s32, s32, s32);   /* extern */

extern char D_008465F0[];
s32 func_004543E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_005A48D8((s32)D_008465F0, 0, 0x40);
    return 1;
}
