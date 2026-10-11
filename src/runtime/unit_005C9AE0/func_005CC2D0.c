#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CC2D0_arg0_unk10 {
    char pad0[0x10B8];
    s32 unk10B8;
};
struct func_005CC2D0_arg0 {
    char pad0[0x10];
    struct func_005CC2D0_arg0_unk10 *unk10;
};

void func_005CC2D0(struct func_005CC2D0_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk10B8 = arg1;
}
