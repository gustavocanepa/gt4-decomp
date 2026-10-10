#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0054EB20(s32, s32, s32, s32, s32);         /* extern */
s32 func_0057F238(s32, s32);                        /* extern */

s32 func_0054EC70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (func_0057F238(arg1, arg0 + 0x240) == 0) {
        return 1;
    }
    return func_0054EB20(arg0, arg1, arg2, arg3, arg4);
}
