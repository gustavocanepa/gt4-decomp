#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005F6418(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;

    var_a2 = 0;
    do {
        temp_v0 = var_a2 * 4;
        var_a2 += 1;
        *(s32 *)(arg0 + temp_v0) = *(s32 *)(arg1 + temp_v0);
    } while (var_a2 < 8);
    return arg0;
}
