#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00577700(s32);                         /* extern */
s32 func_005B68D0();                                /* extern */

s32 func_00577740(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v0;

    temp_v0 = func_005B68D0();
    if (temp_v0 >= 0) {
        func_00577700(temp_v0);
    }
}
