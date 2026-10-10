#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00611998_arg0 {
    char pad0[0x44];
    f32 unk44;
    char pad48[0x4];
    f32 unk4C;
};

s32 func_00611998(struct func_00611998_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!((arg0->unk44 - arg0->unk4C) >= 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
