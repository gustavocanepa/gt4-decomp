#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005AD9A0();                                /* extern */

s32 func_00520970(s32 arg0, s32 arg1, s32 *arg2) {
    s32 temp_v0;

    if (arg1 >= 0) {
        temp_v0 = func_005AD9A0();
        if (temp_v0 > 0) {
            *arg2 += temp_v0;
        }
    }
    return 0;
}
