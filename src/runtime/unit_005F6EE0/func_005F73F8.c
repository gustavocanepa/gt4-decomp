#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F73F8_arg0_unk4 {
    char pad0[0xB8];
    s32 unkB8;
};
struct func_005F73F8_arg0 {
    char pad0[0x4];
    struct func_005F73F8_arg0_unk4 *unk4;
};

s32 func_005F73F8(struct func_005F73F8_arg0 *arg0) {
    return arg0->unk4->unkB8;
}
