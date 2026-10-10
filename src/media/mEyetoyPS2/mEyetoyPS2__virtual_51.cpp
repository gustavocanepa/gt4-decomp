#include "gt4/mEyetoyPS2.h"
typedef int s32;

extern void func_001C4D20(s32);

extern "C" void mEyetoyPS2__virtual_51(struct mEyetoyPS2 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk14;
    if (temp_v0 != 0) {
        func_001C4D20(temp_v0);
    }
}
