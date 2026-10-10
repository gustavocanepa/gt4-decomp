#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004CFA90_arg0 {
    char pad0[0x14];
    s32 (*unk14)(s32);
};

void func_004CFA90(struct func_004CFA90_arg0 *arg0, s32 arg1) {
    arg0->unk14(arg1);
}
