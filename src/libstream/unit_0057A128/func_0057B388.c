#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0057B388_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0x8];
    u32 unk14;
};

s32 func_0057B388(struct func_0057B388_arg0 *arg0) {
    s32 var_a1;
    u32 temp_v0;
    u32 temp_v1;

    var_a1 = arg0->unk8;
    temp_v1 = arg0->unk14;
    temp_v0 = arg0->unk4 + var_a1;
    if (temp_v1 < temp_v0) {
        var_a1 -= temp_v0 - temp_v1;
    }
    return var_a1;
}
