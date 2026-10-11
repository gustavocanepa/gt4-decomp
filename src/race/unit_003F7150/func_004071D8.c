#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_004071D8(s32 arg0, f32 fparg0) {
    f32 *var_a0;
    s32 var_v0;

    var_a0 = (f32 *)(arg0 + 0xFC);
    var_v0 = 0x3F;
    do {
        var_v0 -= 1;
        *var_a0 = fparg0;
        var_a0 -= 1;
    } while (var_v0 >= 0);
}
