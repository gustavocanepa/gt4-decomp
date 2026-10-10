#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CBF78_arg0_unk10 {
    char pad0[0x60];
    s32 unk60;
};
struct func_005CBF78_arg0 {
    char pad0[0x10];
    struct func_005CBF78_arg0_unk10 *unk10;
};

void func_005CBF78(struct func_005CBF78_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk60 = arg1;
}
