#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0040CCD8_temp_a0 {
    char pad0[0x488];
    f32 unk488;
    f32 unk48C;
};

s32 func_0040CCD8(s32 arg0) {
    s32 var_v0;
    struct func_0040CCD8_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    var_v0 = 1;
    if (!(temp_a0->unk488 > 0.0f)) {
        var_v0 = -1;
        if (!(temp_a0->unk48C > 0.0f)) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
