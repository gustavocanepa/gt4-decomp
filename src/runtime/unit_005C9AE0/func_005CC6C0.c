#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CC6C0_arg0_unk10 {
    char pad0[0x111C];
    s32 unk111C;
};
struct func_005CC6C0_arg0 {
    char pad0[0x10];
    struct func_005CC6C0_arg0_unk10 *unk10;
};

s32 func_005CC6C0(struct func_005CC6C0_arg0 *arg0) {
    return arg0->unk10->unk111C;
}
