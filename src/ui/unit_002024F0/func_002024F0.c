#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_002024F0_arg0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
};
struct func_002024F0_arg1 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
};

void *func_002024F0(struct func_002024F0_arg0 *arg0, struct func_002024F0_arg1 *arg1) {
    arg0->unk4 = (f32) arg1->unk4;
    arg0->unk8 = (f32) arg1->unk8;
    arg0->unkC = (f32) arg1->unkC;
    arg0->unk10 = (f32) arg1->unk10;
    arg0->unk14 = (f32) arg1->unk14;
    arg0->unk18 = (f32) arg1->unk18;
    arg0->unk1C = (f32) arg1->unk1C;
    arg0->unk20 = (f32) arg1->unk20;
    arg0->unk24 = (f32) arg1->unk24;
    return arg0;
}
