#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void func_005688C8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_t1;
    s32 var_a1;

    var_a1 = *arg0;
    temp_t1 = 0x10 << arg1;
    if (arg2 > 0) {
        var_a1 = var_a1 + ((arg2 - 1) << arg1) + arg3 + 1;
        if (var_a1 >= temp_t1) {
            var_a1 -= temp_t1 * 2;
        }
    } else if (arg2 < 0) {
        var_a1 = (var_a1 - ((~arg2 << arg1) + arg3)) - 1;
        if (var_a1 < -temp_t1) {
            var_a1 += temp_t1 * 2;
        }
    }
    *arg0 = var_a1;
}
