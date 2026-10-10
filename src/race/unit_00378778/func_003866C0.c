#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003866C0_arg0_unk4 {
    char pad0[0x10];
    s32 unk10;
};
struct func_003866C0_arg0 {
    char pad0[0x4];
    struct func_003866C0_arg0_unk4 *unk4;
};

void func_003866C0(struct func_003866C0_arg0 *arg0, s32 arg1) {
    arg0->unk4->unk10 = arg1;
}
