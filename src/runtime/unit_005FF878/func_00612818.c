#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00612818_arg0 {
    char pad0[0x2];
    u16 unk2;
};

s32 func_00612818(struct func_00612818_arg0 *arg0) {
    return arg0->unk2 & 0xF;
}
