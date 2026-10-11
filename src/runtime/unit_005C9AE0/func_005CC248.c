#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CC248_arg0_unk10 {
    char pad0[0x8C];
    s32 unk8C;
};
struct func_005CC248_arg0 {
    char pad0[0x10];
    struct func_005CC248_arg0_unk10 *unk10;
};

s32 func_005CC248(struct func_005CC248_arg0 *arg0) {
    return arg0->unk10->unk8C;
}
