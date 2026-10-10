#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A609C(s32, s32);                    /* extern */

void func_0042FC50(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x54;
    func_005A609C(arg0 + 0x34, temp_s0);
    func_005A609C(temp_s0, arg1);
}
