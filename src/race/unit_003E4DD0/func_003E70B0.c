#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003E70B0_var_a0 {
    f32 unk0;
    char pad4[0x8];
    f32 unkC;
};

s32 func_003E70B0(s32 arg0, s32 arg1, s32 arg2) {
    f32 *var_a1;
    f32 temp_f1;
    s32 temp_v0;
    s32 var_a2;
    s32 var_v1;
    void *var_a0;

    var_a2 = arg2;
    var_v1 = 0;
    if (var_a2 < 3) {
        temp_v0 = var_a2 * 4;
        var_a0 = temp_v0 + arg0;
        var_a1 = temp_v0 + arg1;
        do {
            temp_f1 = *var_a1;
            var_a1 += 1;
            var_v1 *= 4;
            if (temp_f1 < ((struct func_003E70B0_var_a0 *)var_a0)->unk0) {
                var_v1 |= 1;
            } else if (((struct func_003E70B0_var_a0 *)var_a0)->unkC < temp_f1) {
                var_v1 |= 2;
            }
            var_a2 += 1;
            var_a0 += 4;
        } while (var_a2 < 3);
    }
    return var_v1;
}
