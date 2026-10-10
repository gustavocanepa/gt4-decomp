#include "gt4/mGame.h"
typedef int s32;

extern "C" int mGame__GetClassID(void) throw();

extern "C" void mGame__getClassID(struct mGame *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mGame__GetClassID();
    }
}
