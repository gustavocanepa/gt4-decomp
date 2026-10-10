#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578DB0(s32, s32);                /* extern */
s32 func_005C1628(s32);                         /* extern */

void func_005037F0(s32 arg0, s32 arg1) {
    func_00578DB0(arg0 + 0x1C, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
