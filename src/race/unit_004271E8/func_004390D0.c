#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004390D0_arg0 {
    char pad0[0xC];
    f32 unkC;
    f32 unk10;
};

s32 func_004390D0(struct func_004390D0_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!((arg0->unkC / arg0->unk10) >= 1.5f)) {
        var_v0 = 0;
    }
    return var_v0;
}
