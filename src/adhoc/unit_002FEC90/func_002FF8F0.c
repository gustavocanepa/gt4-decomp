#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s8 HIO__read8();                                 /* extern */

s32 func_002FF8F0(s32 arg0, s8 *arg1) {
    *arg1 = HIO__read8();
    return arg0;
}
