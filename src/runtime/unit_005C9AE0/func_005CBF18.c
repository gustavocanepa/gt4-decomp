#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CBF18_arg0_unk10 {
    char pad0[0x5C];
    s32 unk5C;
};
struct func_005CBF18_arg0 {
    char pad0[0x10];
    struct func_005CBF18_arg0_unk10 *unk10;
};

void func_005CBF18(struct func_005CBF18_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk5C = arg1;
}
