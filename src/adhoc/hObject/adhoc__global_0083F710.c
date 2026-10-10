#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

void adhoc__global_0083F710(s32 *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg0 != arg3) {
        temp_s0 = *arg3;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = *arg0;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        *arg0 = temp_s0;
    }
}
