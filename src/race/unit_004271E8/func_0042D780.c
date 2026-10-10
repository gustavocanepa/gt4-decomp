#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0042D780(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_a3;
    s32 var_v1;
    var_a3 = 0;
    if (arg1 > 0) {
        var_v1 = *arg0;
        do {
            temp_v0 = 1 << var_a3;
            var_a3 += 1;
            var_v1 = (arg2 & temp_v0) ? (var_v1 + 2) : (var_v1 + 4);
        } while (var_a3 < arg1);
        *arg0 = var_v1;
    }
}
