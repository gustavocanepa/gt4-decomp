#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00457CD0(s32 *arg0, s32 arg1) {
    s32 *var_v1;
    s32 var_a2;

    var_a2 = 0;
    if (*arg0 > 0) {
        var_v1 = arg0 + 1;
        do {
            var_a2 += 1;
            *var_v1 += arg1;
            var_v1 += 1;
        } while (var_a2 < *arg0);
    }
}
