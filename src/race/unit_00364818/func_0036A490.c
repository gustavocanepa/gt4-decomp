#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void *func_00359510(s32, s32);                      /* extern */
s32 func_0036A080(void *, s32, void *, f32);    /* extern */
s8 func_0036A1D8(void *, s32);                  /* extern */

struct func_0036A490_temp_s0 {
    char pad0[0x24];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    char pad30[0x485];
    s8 unk4B5;
    char pad4B6[0xFE];
    f32 unk5B4;
};
struct func_0036A490_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

struct func_0036A490_var_v0 {
    f32 unk0;
    char pad4[0x2C];
    f32 unk30;
};
struct func_0036A490_arg0 {
    char pad0[0x10];
    s32 unk10;
};
struct func_0036A490_var_v1 {
    char pad0[0x1C];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
};

void func_0036A490(void *arg0) {
    s8 *var_a0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    s32 var_a1;
    s32 var_a1_2;
    struct func_0036A490_temp_s0 *temp_s0;
    struct func_0036A490_temp_v0 *temp_v0;
    void *var_v0;
    void *var_v1;

    var_a1 = 2;
    temp_s0 = arg0 + 0x104;
    var_v0 = arg0 + 0x128;
    temp_s0->unk5B4 = 0.0f;
    do {
        temp_f0 = ((struct func_0036A490_var_v0 *)var_v0)->unk30;
        var_a1 -= 1;
        temp_f2 = ((struct func_0036A490_var_v0 *)var_v0)->unk0;
        var_v0 += 4;
        temp_s0->unk5B4 = (f32) (temp_s0->unk5B4 + (temp_f0 * temp_f2));
    } while (var_a1 >= 0);
    temp_v0 = func_00359510(((struct func_0036A490_arg0 *)arg0)->unk10, var_a1);
    var_a1_2 = 0;
    if (temp_v0->unk1 != 0) {
        var_a0 = arg0 + 0x22C;
        var_v1 = arg0 + 0x7B8;
        do {
            var_a1_2 += 1;
            temp_f0_2 = ((struct func_0036A490_var_v1 *)var_v1)->unk1C * temp_s0->unk24;
            temp_f3 = ((struct func_0036A490_var_v1 *)var_v1)->unk24 * temp_s0->unk28;
            temp_f2_2 = ((struct func_0036A490_var_v1 *)var_v1)->unk20;
            var_v1 += 0x34;
            *(f32 *)var_a0 = (temp_f0_2 - temp_f3) + (temp_f2_2 * temp_s0->unk2C);
            var_a0 += 0xEC;
        } while (var_a1_2 < (s32) temp_v0->unk1);
    }
    func_0036A080(arg0, var_a1_2, temp_v0, temp_s0->unk5B4);
    temp_s0->unk4B5 = func_0036A1D8(arg0, 0);
}
