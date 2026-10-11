#include "types.h"
void *memcpy(void *, const void *, unsigned int);

u32 func_00510C38(s32 arg0, u32 arg1, u32 arg2) {
    u32 var_a3;
    u32 var_t0;
    u8 *temp_v1;

    var_t0 = 0;
    var_a3 = 0;
    if (arg1 != 0) {
        do {
            temp_v1 = arg0 + var_t0;
            var_t0 += 1;
            var_a3 = (var_a3 * 0x1F) + *temp_v1;
        } while (var_t0 < arg1);
    }
    return var_a3 % arg2;
}
