#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00434E38(s32, s32, s32, s32);          /* extern */
s32 func_00447BB8(s32);                             /* extern */

void func_00434F78(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00434E38(arg0, func_00447BB8(arg1), arg2, arg3);
}
