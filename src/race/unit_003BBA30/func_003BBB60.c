#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_003BBB60_arg0 {
    char pad0[0xC];
    s32 unkC;
};

u32 func_003BBB60(void *arg0, s32 arg1) {
    s32 var_a1;
    s32 var_a1_2;
    u32 *var_a0;
    u32 temp_v1;
    u32 var_a3;

    var_a1 = arg1;
    var_a3 = -1U;
    if (var_a1 >= 0) {
        if (var_a1 >= ((struct func_003BBB60_arg0 *)arg0)->unkC) {
            goto block_4;
        }
    } else {
block_4:
        var_a1 = ((struct func_003BBB60_arg0 *)arg0)->unkC - 1;
    }
    if (var_a1 >= 0) {
        var_a0 = arg0 + 0x14;
        var_a1_2 = var_a1 + 1;
        do {
            temp_v1 = *var_a0;
            var_a0 += 1;
            var_a1_2 -= 1;
            var_a3 = (temp_v1 < var_a3) ? temp_v1 : var_a3;
        } while (var_a1_2 != 0);
    }
    return var_a3;
}
