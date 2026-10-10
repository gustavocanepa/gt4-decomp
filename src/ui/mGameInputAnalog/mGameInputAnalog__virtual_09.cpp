#include "gt4/mGameInputAnalog.h"
typedef int s32;

extern "C" int func_0029A6D0(void) throw();

extern "C" void mGameInputAnalog__virtual_09(struct mGameInputAnalog *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0029A6D0();
    }
}
