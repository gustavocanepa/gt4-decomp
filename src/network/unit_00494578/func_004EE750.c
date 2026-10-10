#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004EE750_arg0 {
    char pad0[0x48];
    s32 unk48;
};

s32 func_004EE750(struct func_004EE750_arg0 *arg0, s32 arg1) {
    return arg0->unk48 + (arg1 * 0x1D0) + 0xD0;
}
