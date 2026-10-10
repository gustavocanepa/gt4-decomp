#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004906C8_arg0 {
    char pad0[0x34];
    f32 unk34;
    char pad38[0x20];
    f32 unk58;
    char pad5C[0x4];
    f32 unk60;
};

s32 func_004906C8(struct func_004906C8_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    s32 var_v0;

    var_v0 = 1;
    temp_f0 = arg0->unk34 + fparg0;
    arg0->unk34 = temp_f0;
    if (!(temp_f0 < (arg0->unk60 - arg0->unk58))) {
        var_v0 = 0;
    }
    return var_v0;
}
