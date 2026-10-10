#include "gt4/mGameInputAnalog.h"
typedef int s32;

extern "C" int mGameInputAnalog__GetClassID(void) throw();

extern "C" void mGameInputAnalog__getClassID(struct mGameInputAnalog *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mGameInputAnalog__GetClassID();
    }
}
