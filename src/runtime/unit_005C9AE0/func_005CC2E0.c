#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CC2E0_arg0_unk10 {
    char pad0[0x10BC];
    s32 unk10BC;
};
struct func_005CC2E0_arg0 {
    char pad0[0x10];
    struct func_005CC2E0_arg0_unk10 *unk10;
};

s32 func_005CC2E0(struct func_005CC2E0_arg0 *arg0) {
    return arg0->unk10->unk10BC;
}
