#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0044FEC0(s32);                             /* extern */
s32 func_00450040();                                /* extern */
s32 func_00450178(s32, s32);                    /* extern */

void func_00603FC0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;

    temp_s1 = func_00450040();
    func_00450178(temp_s1, func_0044FEC0(arg2));
}
