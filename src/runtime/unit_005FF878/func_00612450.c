#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00612450_arg0 {
    char pad0[0x54];
    u32 unk54;
    char pad58[0x4];
    u32 unk5C;
};

s32 func_00612450(struct func_00612450_arg0 *arg0) {
    return (u32) arg0->unk54 < (u32) arg0->unk5C;
}
