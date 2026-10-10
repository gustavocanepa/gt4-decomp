#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004F5D00_arg0 {
    char pad0[0x5A8];
    s32 unk5A8;
};

s32 func_004F5D00(struct func_004F5D00_arg0 *arg0, s32 arg1) {
    return arg0->unk5A8 + (arg1 * 0x2C) + 0x1D8;
}
