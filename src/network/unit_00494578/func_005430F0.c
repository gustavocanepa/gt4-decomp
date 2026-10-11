#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00538830(s32);                             /* extern */
s32 func_00538988();                                /* extern */
void *func_00542A28(s32, s32);                      /* extern */
s32 memcpy(s32, s32, s32);           /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */

struct func_005430F0_temp_v0_2 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_005430F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    struct func_005430F0_temp_v0_2 *temp_v0_2;

    temp_v0 = func_00538988();
    if (temp_v0 != 0) {
        temp_v0_2 = func_00542A28(temp_v0, arg1);
        if ((temp_v0_2 != NULL) && (func_00538830(temp_v0_2->unkC) == 0)) {
            memcpy(arg2, temp_v0_2->unkC, 0x40);
            return 0;
        }
    }
    if (arg2 != 0) {
        func_005A48D8(arg2, 0, 0x40);
    }
    return -1;
}
