#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0030F648_arg0 {
    u8 pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_0030F648(struct func_0030F648_arg0 *arg0) {
    s32 temp_v1;

    temp_v1 = (s32) (arg0->unk8 - arg0->unk4) >> 2;
    return (temp_v1 < 2) ? 1 : (temp_v1 - 1);
}
