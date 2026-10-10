#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FD940_arg0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
};

s32 func_003FD940(struct func_003FD940_arg0 *arg0, f32 fparg0) {
    f32 temp_f1;
    s32 var_v0;

    temp_f1 = arg0->unk4;
    var_v0 = 1;
    if (!(((fparg0 - temp_f1) / (arg0->unk8 - temp_f1)) < 0x1.9999980000000p-5f)) {
        var_v0 = 0;
    }
    return var_v0;
}
