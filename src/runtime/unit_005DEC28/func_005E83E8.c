#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E83E8_arg0 {
    char pad0[0xFC];
    f32 unkFC;
};

void func_005E83E8(struct func_005E83E8_arg0 *arg0, f32 fparg0) {
    f32 var_f12;

    var_f12 = fparg0;
    if (var_f12 < 0.0f) {
        var_f12 = 0.0f;
    }
    if (var_f12 > 1.0f) {
        var_f12 = 1.0f;
    }
    arg0->unkFC = var_f12;
}
