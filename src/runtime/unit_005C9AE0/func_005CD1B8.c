#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD1B8_arg0_unk10 {
    char pad0[0x13F0];
    s32 unk13F0;
};
struct func_005CD1B8_arg0 {
    char pad0[0x10];
    struct func_005CD1B8_arg0_unk10 *unk10;
};

void func_005CD1B8(struct func_005CD1B8_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk13F0 = arg1;
}
