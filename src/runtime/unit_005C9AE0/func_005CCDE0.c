#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CCDE0_arg0_unk10 {
    char pad0[0x1164];
    s32 unk1164;
};
struct func_005CCDE0_arg0 {
    char pad0[0x10];
    struct func_005CCDE0_arg0_unk10 *unk10;
};

s32 func_005CCDE0(struct func_005CCDE0_arg0 *arg0) {
    return arg0->unk10->unk1164;
}
