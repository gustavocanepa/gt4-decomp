#include "gt4/mRandom.h"
typedef int s32;

extern "C" int func_002CB848(void) throw();

extern "C" void mRandom__virtual_09(struct mRandom *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002CB848();
    }
}
