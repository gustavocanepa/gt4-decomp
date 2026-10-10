#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003EFD08_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

s32 func_003EFD08(struct func_003EFD08_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if ((arg0->unkC == 0.0f) && (arg0->unk10 == 1.0f) && (arg0->unk14 == 1.0f) && (arg0->unk0 == 1.0f) && (arg0->unk4 == 1.0f) && (arg0->unk8 == 1.0f)) {
        var_v0 = 1;
    }
    return var_v0;
}
