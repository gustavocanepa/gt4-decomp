#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004308C8_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

s32 func_004308C8(struct func_004308C8_arg0 *arg0) {
    return ((s32) arg0->unk4C >> 1) & 1;
}
