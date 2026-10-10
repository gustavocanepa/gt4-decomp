#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00239098_arg0 {
    char pad0[0xC4];
    f32 unkC4;
    f32 unkC8;
    f32 unkCC;
};

s32 func_00239098(struct func_00239098_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f2;
    f32 var_f1;
    s32 var_v0;

    temp_f2 = arg0->unkC4;
    temp_f0 = arg0->unkC8;
    temp_f12 = temp_f2 - fparg0;
    arg0->unkC4 = temp_f12;
    if (temp_f12 < temp_f0) {
        arg0->unkC4 = temp_f0;
    }
    var_f1 = arg0->unkC4;
    temp_f0_2 = arg0->unkCC;
    if (temp_f0_2 < var_f1) {
        arg0->unkC4 = temp_f0_2;
        var_f1 = temp_f0_2;
    }
    var_v0 = 1;
    if (var_f1 == temp_f2) {
        var_v0 = 0;
    }
    return var_v0;
}
