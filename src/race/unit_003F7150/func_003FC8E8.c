#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003FC8E8_arg0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
};

f32 func_003FC8E8(struct func_003FC8E8_arg0 *arg0, s32 *arg1, f32 fparg0) {
    f32 temp_f1;
    f32 var_f0;

    temp_f1 = arg0->unk4;
    var_f0 = (fparg0 - temp_f1) / (arg0->unk8 - temp_f1);
    *arg1 = 0;
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
        *arg1 = 1;
    }
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
        *arg1 = 1;
    }
    return var_f0;
}
