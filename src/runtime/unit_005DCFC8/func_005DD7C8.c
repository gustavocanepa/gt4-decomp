#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005DD7C8_arg0 {
    char pad0[0x1C];
    void *unk1C;
};
struct func_005DD7C8_temp_a0_unk4 {
    char pad0[0x8];
    s32 unk8;
};
struct func_005DD7C8_temp_a0 {
    s32 unk0;
    struct func_005DD7C8_temp_a0_unk4 *unk4;
};

s32 func_005DD7C8(struct func_005DD7C8_arg0 *arg0) {
    s32 var_v1;
    struct func_005DD7C8_temp_a0 *temp_a0;

    temp_a0 = arg0->unk1C;
    var_v1 = 0;
    if (temp_a0->unk0 != temp_a0) {
        var_v1 = temp_a0->unk4->unk8 != 0;
    }
    return var_v1;
}
