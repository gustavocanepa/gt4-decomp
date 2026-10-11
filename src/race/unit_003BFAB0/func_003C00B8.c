#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003C00B8_arg0 {
    char pad0[0xC0];
    s32 unkC0;
    s32 unkC4;
    f32 unkC8;
    s32 unkCC;
};

void func_003C00B8(struct func_003C00B8_arg0 *arg0) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = arg0->unkC4;
    arg0->unkC8 = 0.0f;
    arg0->unkCC = 0;
    if (temp_v0 != 0) {
        arg0->unkC8 = (f32) ((temp_v0 * 0x3C) + 0xB4);
    }
    var_v0 = 1;
    if (!(arg0->unkC8 > 0.0f)) {
        var_v0 = 0;
    }
    arg0->unkC0 = var_v0;
}
