#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CBD10_arg0_unk10 {
    char pad0[0x14];
    s32 unk14;
};
struct func_005CBD10_arg0 {
    char pad0[0x10];
    struct func_005CBD10_arg0_unk10 *unk10;
};

s32 func_005CBD10(struct func_005CBD10_arg0 *arg0) {
    return arg0->unk10->unk14;
}
