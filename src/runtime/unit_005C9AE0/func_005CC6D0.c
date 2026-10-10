#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CC6D0_arg0_unk10 {
    char pad0[0x111C];
    s32 unk111C;
};
struct func_005CC6D0_arg0 {
    char pad0[0x10];
    struct func_005CC6D0_arg0_unk10 *unk10;
};

void func_005CC6D0(struct func_005CC6D0_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk111C = arg1;
}
