#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0057AEA8_arg0 {
    char pad0[0x8];
    f32 unk8;
};

void *func_0057AEA8(struct func_0057AEA8_arg0 *arg0, f32 fparg0, f32 fparg1) {
    f32 var_f0;

    var_f0 = arg0->unk8;
    if (var_f0 < fparg0) {
        arg0->unk8 = fparg0;
        var_f0 = fparg0;
    }
    if (fparg1 < var_f0) {
        arg0->unk8 = fparg1;
    }
    return arg0;
}
