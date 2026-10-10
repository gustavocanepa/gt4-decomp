#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CBF68_arg0_unk10 {
    char pad0[0x60];
    s32 unk60;
};
struct func_005CBF68_arg0 {
    char pad0[0x10];
    struct func_005CBF68_arg0_unk10 *unk10;
};

s32 func_005CBF68(struct func_005CBF68_arg0 *arg0) {
    return arg0->unk10->unk60;
}
