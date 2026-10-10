#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00538988();                                /* extern */
s32 func_00542970(s32);                         /* extern */
s32 func_00542A28(s32, s32);                        /* extern */
s32 func_00542A60(s32, s32);                    /* extern */

void func_00543980(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_00538988();
    temp_v0_2 = func_00542A28(temp_v0, arg1);
    if (temp_v0_2 != 0) {
        func_00542A60(temp_v0, temp_v0_2);
        func_00542970(temp_v0_2);
    }
}
