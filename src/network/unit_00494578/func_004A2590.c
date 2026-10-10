#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004A2590_arg0 {
    char pad0[0x3];
    s8 unk3;
    char pad4[0x230];
    f32 unk234;
    f32 unk238;
    f32 unk23C;
    f32 unk240;
    f32 unk244;
    char pad248[0xD60];
    f32 unkFA8;
    char padFAC[0xC];
    f32 unkFB8;
};

void func_004A2590(struct func_004A2590_arg0 *arg0) {
    f32 temp_f1;
    f32 temp_f3;
    f32 temp_f4;

    temp_f3 = arg0->unk238;
    temp_f1 = arg0->unk234;
    temp_f4 = arg0->unk23C;
    arg0->unk3 = 0;
    arg0->unkFA8 = (f32) ((temp_f1 - temp_f3) * temp_f4 * 0.5f);
    arg0->unkFB8 = (f32) ((((1.0f - ((temp_f1 + temp_f3) * 0.5f)) + arg0->unk244) * temp_f4) + (arg0->unk240 + 1.0f));
}
