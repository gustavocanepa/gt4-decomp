#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CBD70_arg0_unk10 {
    char pad0[0x1C];
    s32 unk1C;
};
struct func_005CBD70_arg0 {
    char pad0[0x10];
    struct func_005CBD70_arg0_unk10 *unk10;
};

void func_005CBD70(struct func_005CBD70_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1C = arg1;
}
