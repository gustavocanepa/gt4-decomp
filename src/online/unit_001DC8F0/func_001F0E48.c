#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001F0E88();                                /* extern */
s32 func_004EF278(s32, s32);                /* extern */

extern char D_00645440[];
s32 func_001F0E48(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (func_001F0E88() != 0) {
        return 1;
    }
    return func_004EF278((s32)D_00645440, 0);
}
