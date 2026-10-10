#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00612DF0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x4];
    s32 unk24;
};

s32 func_00612DF0(struct func_00612DF0_arg0 *arg0) {
    return arg0->unk24 - arg0->unk1C;
}
