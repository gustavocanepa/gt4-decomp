#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A48D8(s32 *, s32, s32);     /* extern */

void func_00555130(s32 arg0, s32 arg1) {
    s32 *temp_s0;

    temp_s0 = (arg1 * 0x114) + arg0;
    func_005A48D8(temp_s0, 0, 0x114);
    *temp_s0 = -1;
}
