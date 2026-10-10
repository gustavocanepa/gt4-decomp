#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CD098_arg0_unk10 {
    char pad0[0x13CC];
    s32 unk13CC;
};
struct func_005CD098_arg0 {
    char pad0[0x10];
    struct func_005CD098_arg0_unk10 *unk10;
};

void func_005CD098(struct func_005CD098_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk13CC = arg1;
}
