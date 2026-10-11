#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD0B8_arg0_unk10 {
    char pad0[0x13D0];
    s32 unk13D0;
};
struct func_005CD0B8_arg0 {
    char pad0[0x10];
    struct func_005CD0B8_arg0_unk10 *unk10;
};

void func_005CD0B8(struct func_005CD0B8_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk13D0 = arg1;
}
