#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

u8 *func_00515DD8(s32);                             /* extern */

void func_00516030(s32 arg0, s32 arg1, u32 arg2) {
    s32 (*temp_v0_2)(s32, s32, u32);
    u8 *temp_v0;

    if ((arg2 < 0x40U) || (arg2 == -2U) || (arg2 == -1U)) {
        temp_v0 = func_00515DD8(arg1);
        if (temp_v0 != NULL) {
            temp_v0_2 = *(s32 *)(0x8541B0 + (*temp_v0 * 4));
            if (temp_v0_2 != NULL) {
                temp_v0_2(arg0, arg1, arg2);
            }
        }
    }
}
