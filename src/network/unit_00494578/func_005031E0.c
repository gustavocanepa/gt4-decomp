#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00501180(s32);                         /* extern */
s32 func_005030C8();                                /* extern */

s32 func_005031E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v0;

    temp_v0 = func_005030C8();
    if (temp_v0 != 0) {
        func_00501180(temp_v0 + 0xB8);
    }
}
