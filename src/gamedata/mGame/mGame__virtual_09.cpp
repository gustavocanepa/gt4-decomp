#include "gt4/mGame.h"
typedef int s32;

extern "C" int func_0015F530(void) throw();

extern "C" void mGame__virtual_09(struct mGame *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0015F530();
    }
}
