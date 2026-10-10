#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004F4428_arg0 {
    char pad0[0x5A8];
    s32 unk5A8;
};

s32 func_004F4428(struct func_004F4428_arg0 *arg0, s32 arg1) {
    return arg0->unk5A8 + (arg1 * 0xD0) + 0x1D8;
}
