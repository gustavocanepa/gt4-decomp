#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void *func_00359510(s32);                           /* extern */
s32 func_003598F8(f32, s32, s32, void *, void *); /* extern */
s32 func_00360F80(s32, u32, u8);                    /* extern */

struct func_00351850_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

struct func_00351850_var_s0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x188];
    f32 unk19C;
    char pad1A0[0x4D];
    u8 unk1ED;
};

void func_00351850(void *arg0) {
    s32 temp_s3;
    s32 temp_v0_2;
    u32 temp_a1;
    u32 var_s1;
    struct func_00351850_temp_v0 *temp_v0;
    void *var_s0;

    var_s0 = arg0;
    var_s1 = 0;
    temp_s3 = ((struct func_00351850_var_s0 *)var_s0)->unk10;
    temp_v0 = func_00359510(temp_s3);
    if (temp_v0->unk1 != 0) {
        do {
            temp_a1 = var_s1;
            var_s1 += 1;
            temp_v0_2 = func_00360F80(temp_s3, temp_a1, ((struct func_00351850_var_s0 *)var_s0)->unk1ED);
            func_003598F8(((struct func_00351850_var_s0 *)var_s0)->unk19C, temp_v0_2 + 0xF8, temp_v0_2 + 0x170, var_s0 + 0x1B8, var_s0 + 0x1BC);
            var_s0 += 0xEC;
        } while (var_s1 < (u8) temp_v0->unk1);
    }
}
