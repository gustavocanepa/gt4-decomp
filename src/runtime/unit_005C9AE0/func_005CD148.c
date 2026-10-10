#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD148_arg0_unk10 {
    char pad0[0x13E4];
    s32 unk13E4;
};
struct func_005CD148_arg0 {
    char pad0[0x10];
    struct func_005CD148_arg0_unk10 *unk10;
};

s32 func_005CD148(struct func_005CD148_arg0 *arg0) {
    return arg0->unk10->unk13E4;
}
