#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD088_arg0_unk10 {
    char pad0[0x13CC];
    s32 unk13CC;
};
struct func_005CD088_arg0 {
    char pad0[0x10];
    struct func_005CD088_arg0_unk10 *unk10;
};

s32 func_005CD088(struct func_005CD088_arg0 *arg0) {
    return arg0->unk10->unk13CC;
}
