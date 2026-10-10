#include "gt4/mGameStats.h"
typedef int s32;

extern "C" int func_0016C0E8(void) throw();

extern "C" void mGameStats__virtual_09(struct mGameStats *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0016C0E8();
    }
}
