#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00447BB8(s32);                             /* extern */
s32 func_00447E18();                                /* extern */
s32 func_00448170(s32, s32);                    /* extern */

s32 func_00448240(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_00447E18();
    if (temp_v0 != 0) {
        func_00448170(func_00447BB8(temp_v0), arg1);
    }
}
