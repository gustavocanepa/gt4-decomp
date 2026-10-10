#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CD178_arg0_unk10 {
    char pad0[0x13E8];
    s32 unk13E8;
};
struct func_005CD178_arg0 {
    char pad0[0x10];
    struct func_005CD178_arg0_unk10 *unk10;
};

void func_005CD178(struct func_005CD178_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk13E8 = arg1;
}
