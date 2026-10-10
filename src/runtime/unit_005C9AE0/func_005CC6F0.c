#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CC6F0_arg0_unk10 {
    char pad0[0x1120];
    s32 unk1120;
};
struct func_005CC6F0_arg0 {
    char pad0[0x10];
    struct func_005CC6F0_arg0_unk10 *unk10;
};

void func_005CC6F0(struct func_005CC6F0_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1120 = arg1;
}
