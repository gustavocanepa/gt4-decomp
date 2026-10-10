#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00490830_arg0 {
    char pad0[0x14];
    void *unk14;
    char pad18[0x10];
    f32 unk28;
};
struct func_00490830_temp_v0 {
    char pad0[0xD];
    u8 unkD;
};

f32 func_00490830(struct func_00490830_arg0 *arg0) {
    f32 var_f0;
    struct func_00490830_temp_v0 *temp_v0;

    temp_v0 = arg0->unk14;
    var_f0 = 0.0f;
    if (temp_v0 != NULL) {
        var_f0 = (f32) temp_v0->unkD * arg0->unk28;
    }
    return var_f0;
}
