#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005CD118_arg0_unk10 {
    char pad0[0x13DC];
    s32 unk13DC;
};
struct func_005CD118_arg0 {
    char pad0[0x10];
    struct func_005CD118_arg0_unk10 *unk10;
};

void func_005CD118(struct func_005CD118_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk13DC = arg1;
}
