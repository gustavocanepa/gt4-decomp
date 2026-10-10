#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0046E8E0_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0x4];
    s32 unk10;
    s32 unk14;
    char pad18[0x8];
    s32 unk20;
};

void func_0046E8E0(struct func_0046E8E0_arg0 *arg0) {
    s32 temp_v0;

    if (arg0->unk20 == 0) {
        temp_v0 = arg0->unk8 + 1;
        arg0->unk8 = temp_v0;
        arg0->unk10 = (s32) (arg0->unk10 + 1);
        if (temp_v0 >= arg0->unk4) {
            arg0->unk14 = 0;
        }
    }
}
