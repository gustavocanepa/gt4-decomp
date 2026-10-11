#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0020C2B0_arg0 {
    char pad0[0x1C];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
};

void func_0020C2B0(struct func_0020C2B0_arg0 *arg0, f32 fparg0) {
    f32 var_f12;
    f32 var_f1;

    var_f12 = fparg0;
    if (var_f12 <= 0.0f) {
        var_f12 = 1.0f;
    }
    var_f1 = arg0->unk20 - arg0->unk1C;
    if (!(var_f1 >= 0.0f)) {
        var_f1 = -var_f1;
    }
    arg0->unk24 = (f32) (var_f1 / (var_f12 * 60.0f));
}
