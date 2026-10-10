#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD0D8_arg0_unk10 {
    char pad0[0x13D4];
    s32 unk13D4;
};
struct func_005CD0D8_arg0 {
    char pad0[0x10];
    struct func_005CD0D8_arg0_unk10 *unk10;
};

void func_005CD0D8(struct func_005CD0D8_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk13D4 = arg1;
}
