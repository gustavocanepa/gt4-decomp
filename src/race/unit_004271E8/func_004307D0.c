#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s64 func_00447BB8(s32);                             /* extern */
s32 func_005A609C(s32);                             /* extern */

void func_004307D0(s64 *arg0) {
    *arg0 = func_00447BB8(func_005A609C(arg0 + 1));
}
