#include "gt4/mGamePort.h"
typedef int s32;

extern "C" int func_0029BBC8(void) throw();

extern "C" void mGamePort__virtual_09(struct mGamePort *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0029BBC8();
    }
}
