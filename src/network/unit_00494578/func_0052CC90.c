#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00528770(s32);                             /* extern */
s32 func_00528820(s32, s32, s32);               /* extern */

void func_0052CC90(s32 arg0, s32 arg1, s32 arg2) {
    func_00528820(arg0, arg1, func_00528770(arg2));
}
