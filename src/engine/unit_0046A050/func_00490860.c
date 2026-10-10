#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00490860_arg0 {
    char pad0[0x14];
    void *unk14;
    char pad18[0x10];
    f32 unk28;
};
struct func_00490860_temp_v0 {
    char pad0[0xE];
    s8 unkE;
};

f32 func_00490860(struct func_00490860_arg0 *arg0) {
    f32 var_f0;
    struct func_00490860_temp_v0 *temp_v0;

    temp_v0 = arg0->unk14;
    var_f0 = 0.0f;
    if (temp_v0 != NULL) {
        var_f0 = (f32) temp_v0->unkE * arg0->unk28;
    }
    return var_f0;
}
