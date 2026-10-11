#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_002289F8_temp_v0 {
    char pad0[0x8];
    f32 unk8;
};

struct func_002289F8_arg0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

void func_002289F8(void *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f12;
    struct func_002289F8_temp_v0 *temp_v0;

    var_f12 = fparg0;
    temp_f0 = ((struct func_002289F8_arg0 *)arg0)->unk10;
    temp_v0 = arg0 + 0x1C;
    if (var_f12 < temp_f0) {
        var_f12 = temp_f0;
    }
    temp_f0_2 = ((struct func_002289F8_arg0 *)arg0)->unk14;
    if (temp_f0_2 <= var_f12) {
        var_f12 = temp_f0_2;
    }
    ((struct func_002289F8_arg0 *)arg0)->unk18 = var_f12;
    if (var_f12 < temp_v0->unk8) {
        temp_v0->unk8 = var_f12;
    }
}
