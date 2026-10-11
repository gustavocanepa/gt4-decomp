#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD198_arg0_unk10 {
    char pad0[0x13EC];
    s32 unk13EC;
};
struct func_005CD198_arg0 {
    char pad0[0x10];
    struct func_005CD198_arg0_unk10 *unk10;
};

void func_005CD198(struct func_005CD198_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk13EC = arg1;
}
