#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_00454B08(s32, s32);                  /* extern */

struct func_00458740_arg0 {
    char pad0[0x20];
    s32 unk20;
};
struct func_00458740_temp_v0 {
    char pad0[0x4];
    f32 unk4;
};

f32 func_00458740(struct func_00458740_arg0 *arg0, s32 arg1) {
    f32 var_f0;
    s32 var_v0;
    struct func_00458740_temp_v0 *temp_v0;

    var_v0 = arg1;
    if (var_v0 == 0) {
        var_v0 = arg0->unk20;
    }
    temp_v0 = func_00454B08(var_v0, 0x800002);
    var_f0 = 0.0f;
    if (temp_v0 != NULL) {
        var_f0 = temp_v0->unk4;
    }
    return var_f0;
}
