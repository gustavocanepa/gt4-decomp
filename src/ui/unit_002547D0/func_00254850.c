#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00254850_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

s32 func_00254850(struct func_00254850_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = arg0->unk14;
    if (temp_v1 > 0) {
        temp_v0 = arg0->unk18 - 1;
        arg0->unk18 = temp_v0;
        if (temp_v0 <= 0) {
            arg0->unk18 = temp_v1;
            return 1;
        }
        return 0;
    }
    return 1;
}
