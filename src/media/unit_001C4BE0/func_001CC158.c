#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A5DC8(s32, s32);                    /* extern */
s32 func_005A609C(s32, s32);                    /* extern */

extern char D_00694D60[];
s8 *func_001CC158(s32 arg0, s8 *arg1) {
    s32 temp_s0;
    s32 temp_s2;

    temp_s0 = arg1 + 1;
    temp_s2 = arg0 + 0x24;
    *arg1 = 0x2F;
    func_005A609C(temp_s0, temp_s2);
    func_005A5DC8(temp_s0, (s32)D_00694D60);
    func_005A5DC8(temp_s0, temp_s2);
    return arg1;
}
