#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_006050D0_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_006050D0(struct func_006050D0_arg0 *arg0) {
    return arg0->unk4 - arg0->unk8;
}
