#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00409138_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

void func_00409138(struct func_00409138_arg0 *arg0, s32 arg1) {
    if (arg0->unk18 != 0) {
        if (arg1 != 0) {
            arg0->unk14 = 1;
            return;
        }
        arg0->unk14 = 2;
    }
}
