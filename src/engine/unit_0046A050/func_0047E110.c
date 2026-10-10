#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0047E110_arg0 {
    f32 unk0;
    f32 unk4;
    char pad8[0x8];
    f32 unk10;
    f32 unk14;
    char pad18[0x18];
    f32 unk30;
    f32 unk34;
};
struct func_0047E110_arg2 {
    f32 unk0;
    f32 unk4;
};
struct func_0047E110_arg1 {
    f32 unk0;
    f32 unk4;
};

void func_0047E110(struct func_0047E110_arg0 *arg0, struct func_0047E110_arg1 *arg1, struct func_0047E110_arg2 *arg2) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f7;

    temp_f6 = arg0->unk14;
    temp_f4 = arg0->unk10;
    temp_f7 = 1.0f / ((arg0->unk0 * temp_f6) - (arg0->unk4 * temp_f4));
    arg2->unk0 = (f32) (temp_f7 * ((((temp_f6 * arg1->unk0) - (temp_f4 * arg1->unk4)) + (temp_f4 * arg0->unk34)) - (temp_f6 * arg0->unk30)));
    temp_f2 = arg0->unk4;
    temp_f1 = arg0->unk0;
    arg2->unk4 = (f32) (temp_f7 * (((-temp_f2 * arg1->unk0) + (temp_f1 * arg1->unk4) + (temp_f2 * arg0->unk30)) - (temp_f1 * arg0->unk34)));
}
