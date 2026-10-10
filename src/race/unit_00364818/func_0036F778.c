#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0036F778_arg0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

f32 func_0036F778(struct func_0036F778_arg0 *arg0, f32 fparg0) {
    f32 var_f12;

    var_f12 = fparg0;
    if (var_f12 <= 0.0f) {
        var_f12 = 0.0f;
    }
    if (var_f12 >= 1.0f) {
        var_f12 = 1.0f;
    }
    return ((((arg0->unk10 * var_f12) + arg0->unk14) * var_f12) + arg0->unk18) * var_f12;
}
