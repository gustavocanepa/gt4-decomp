#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004EE778_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

s32 func_004EE778(struct func_004EE778_arg0 *arg0, s32 arg1) {
    return arg0->unk4C + (arg1 * 0x1D0) + 0xC0;
}
