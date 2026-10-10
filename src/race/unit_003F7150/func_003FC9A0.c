#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003FC9A0_arg0 {
    char pad0[0x8];
    f32 unk8;
};

f32 func_003FC9A0(struct func_003FC9A0_arg0 *arg0, s32 arg1, s32 *arg2) {
    f32 var_f0;

    var_f0 = (f32) arg1 / (arg0->unk8 * 60.0f);
    *arg2 = 0;
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
        *arg2 = 1;
    }
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
        *arg2 = 1;
    }
    return var_f0;
}
