#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

int func_00538BF8(int *, int);
s32 func_0050A1C0(s32 *arg0) {
    s32 var_v0;

    if (func_00538BF8(arg0, 0x16C) == 0) {
        var_v0 = func_00538BF8(*arg0 + 0x158, 0x64);
        if (var_v0 != 0) {
            func_00538C68(arg0);
            goto block_3;
        }
    } else {
block_3:
        var_v0 = -4;
    }
    return var_v0;
}
