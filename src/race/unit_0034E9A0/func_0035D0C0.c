#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0035C7C8();                                /* extern */
s32 func_0035C848(s32, s32, s32);       /* extern */

void func_0035D0C0(s32 arg0) {
    if (func_0035C7C8() != 0) {
        func_0035C848(arg0, 5, -1);
    }
}
