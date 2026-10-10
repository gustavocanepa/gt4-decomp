#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0044D740(s32, s32, s32, s32);      /* extern */
s32 func_00462588();                                /* extern */
s32 func_00462670(s32, s32, s32);               /* extern */

void func_00462738(s32 arg0, s32 arg1, s32 arg2) {
    func_00462670(arg0, func_0044D740(arg1, func_00462588(), 0, 0), arg2);
}
