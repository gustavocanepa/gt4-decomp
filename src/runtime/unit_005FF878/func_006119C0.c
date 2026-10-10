#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_006119C0_arg0 {
    char pad0[0x34];
    s32 unk34;
};

s32 func_006119C0(struct func_006119C0_arg0 *arg0) {
    return arg0->unk34 & 0xF;
}
