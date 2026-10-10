#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576FE8(s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_00577478(s32);                             /* extern */

void func_00576F70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_00576FE8(arg0, arg1, arg2, 0, 0, func_00577478(arg3), arg3, arg4);
}
