#include "gt4/mRandom.h"
typedef int s32;

extern "C" int mRandom__GetClassID(void) throw();

extern "C" void mRandom__getClassID(struct mRandom *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mRandom__GetClassID();
    }
}
