#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_003E21A8(void *, void *);                  /* extern */

extern char D_00621D28[];
struct func_003E4278_arg0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
};
struct func_003E4278_arg3 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct func_003E4278_var_s0 {
    char pad0[0xC];
    f32 unkC;
};

s32 func_003E4278(struct func_003E4278_arg0 *arg0, s32 arg1, void *arg2, struct func_003E4278_arg3 *arg3) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f21;
    s32 var_s1;
    s32 var_s4;
    s32 var_v0;
    void *var_s0;

    var_f21 = 0x1.86a0000000000p+16f;
    var_s0 = (arg1 * 0x50) + (s32)D_00621D28;
    var_s1 = 0;
    var_s4 = -1;
    do {
        temp_f0 = func_003E21A8(arg3, var_s0);
        if (!(temp_f0 >= 0x0.0p+0f)) {
            temp_f0_2 = (func_003E21A8(arg2, var_s0) + ((struct func_003E4278_var_s0 *)var_s0)->unkC) / temp_f0;
            if (temp_f0_2 < var_f21) {
                var_f21 = temp_f0_2;
                var_s4 = var_s1;
            }
        }
        var_s1 += 1;
        var_s0 += 0x10;
    } while (var_s1 < 5);
    var_v0 = -1;
    if (var_s4 >= 0) {
        var_v0 = var_s4;
        arg0->unk10 = (f32) (arg0->unk10 - (var_f21 * arg3->unk0));
        arg0->unk14 = (f32) (arg0->unk14 - (var_f21 * arg3->unk4));
        arg0->unk18 = (f32) (arg0->unk18 - (var_f21 * arg3->unk8));
    }
    return var_v0;
}
