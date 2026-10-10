#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */
s32 func_005C1628(s32 *);                       /* extern */

void func_004B4400(s32 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_00575DA0(temp_v0);
        *arg0 = 0;
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
