#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CBF08_arg0_unk10 {
    char pad0[0x5C];
    s32 unk5C;
};
struct func_005CBF08_arg0 {
    char pad0[0x10];
    struct func_005CBF08_arg0_unk10 *unk10;
};

s32 func_005CBF08(struct func_005CBF08_arg0 *arg0) {
    return arg0->unk10->unk5C;
}
