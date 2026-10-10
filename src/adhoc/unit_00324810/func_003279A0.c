#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00305F60();                            /* extern */
s32 func_003285F8(s32);                         /* extern */
s32 func_005C1628(s32 *);                       /* extern */

void func_003279A0(s32 *arg0, s32 arg1) {
    if (*arg0 != 0) {
        func_00305F60();
        func_003285F8(*arg0);
        *arg0 = 0;
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
