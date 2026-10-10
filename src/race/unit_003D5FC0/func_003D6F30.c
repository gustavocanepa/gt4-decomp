#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003D6F30_arg0 {
    char pad0[0x64];
    s32 unk64;
};

s32 func_003D6F30(struct func_003D6F30_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk64;
    arg0->unk64 = 0;
    return temp_v0;
}
