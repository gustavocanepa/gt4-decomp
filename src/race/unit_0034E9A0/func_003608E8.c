#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_003608E8(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 fparg0) {
    *arg0 = (f32) (arg4 & 0xFF) * 0x1.47ae140000000p-7f;
    *arg1 = (f32) (arg5 & 0xFF) * 0x1.4000000000000p+2f * 0x1.3999980000000p+3f;
    *arg2 = (f32) (arg6 & 0xFF) * 0x1.47ae140000000p-7f;
    *arg3 = (f32) (arg7 & 0xFF) * 0x1.4000000000000p+2f * 0x1.3999980000000p+3f;
    *arg0 *= fparg0;
    *arg2 *= fparg0;
}
