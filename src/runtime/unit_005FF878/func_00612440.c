#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00612440_arg0 {
    char pad0[0x58];
    u32 unk58;
    u32 unk5C;
};

s32 func_00612440(struct func_00612440_arg0 *arg0) {
    return (u32) arg0->unk58 < (u32) arg0->unk5C;
}
