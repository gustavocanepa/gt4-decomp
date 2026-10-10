#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0042AD00_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
};

void func_0042AD00(struct func_0042AD00_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7, f32 arg_sp0) {
    arg0->unk8 = 1;
    if (arg0->unkC != 0) {
        arg0->unk10 = fparg0;
        arg0->unk14 = fparg1;
        arg0->unk18 = fparg2;
        arg0->unk1C = fparg3;
        arg0->unk20 = fparg4;
        arg0->unk24 = fparg5;
        arg0->unk28 = fparg6;
        arg0->unk2C = fparg7;
        arg0->unk30 = arg_sp0;
    }
    arg0->unk0 = 1;
}
