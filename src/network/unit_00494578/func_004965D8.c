/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004965D8_arg0 {
    char pad0[0x2C];
    s32 unk2C;
    s32 unk30;
};
struct func_004965D8_temp_v0_2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char padC[0x4];
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

void func_004965D8(struct func_004965D8_arg0 *arg0) {
    s32 temp_v0;
    s32 var_a1;
    struct func_004965D8_temp_v0_2 *temp_v0_2;

    var_a1 = arg0->unk30 - 1;
    if (var_a1 >= 0) {
        do {
            temp_v0 = var_a1 << 5;
            var_a1 -= 1;
            temp_v0_2 = temp_v0 + arg0->unk2C;
            temp_v0_2->unk0 = (f32) (temp_v0_2->unk0 + temp_v0_2->unk10);
            temp_v0_2->unk4 = (f32) (temp_v0_2->unk4 + temp_v0_2->unk14);
            temp_v0_2->unk8 = (f32) (temp_v0_2->unk8 + temp_v0_2->unk18);
        } while (var_a1 >= 0);
    }
}
