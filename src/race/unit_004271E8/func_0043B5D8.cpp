#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
void func_0043B5D8(s32 arg0) {
    s32 *var_a0;
    s32 var_v0;

    var_a0 = (s32 *)(arg0 + 0x20);
    var_v0 = 7;
    do {
        var_v0 -= 1;
        *var_a0 = 0;
        var_a0 -= 1;
    } while (var_v0 >= 0);
}

}
