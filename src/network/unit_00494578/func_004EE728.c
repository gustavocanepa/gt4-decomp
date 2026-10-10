#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004EE728_arg0 {
    char pad0[0x48];
    s32 unk48;
};

s32 func_004EE728(struct func_004EE728_arg0 *arg0, s32 arg1) {
    return arg0->unk48 + (arg1 * 0x1D0) + 0xC0;
}
