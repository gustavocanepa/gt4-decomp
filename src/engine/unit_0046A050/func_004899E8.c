#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004899E8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};
struct func_004899E8_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

s32 func_004899E8(struct func_004899E8_arg0 *arg0, struct func_004899E8_arg1 *arg1) {
    s32 var_v0;

    var_v0 = 0;
    if ((arg0->unk0 == arg1->unk0) && (arg0->unkC == arg1->unkC) && (arg0->unk18 == arg1->unk18) && (arg0->unk4 == arg1->unk4) && (arg0->unk10 == arg1->unk10) && (arg0->unk1C == arg1->unk1C) && (arg0->unk8 == arg1->unk8) && (arg0->unk14 == arg1->unk14)) {
        var_v0 = 1;
        if (arg0->unk20 != arg1->unk20) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
