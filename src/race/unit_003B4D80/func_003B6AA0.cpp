#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003BBA30(s32, s32);                /* extern */
s32 func_003BBA80(s32, s32);                    /* extern */

void func_003B6AA0(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x1A0;
    func_003BBA30(temp_s0, 0);
    func_003BBA80(temp_s0, arg1);
}
