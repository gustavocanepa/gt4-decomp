#include "gt4/mCrossTransition.h"
typedef int s32;

extern "C" int mCrossTransition__GetClassID(void) throw();

extern "C" void mCrossTransition__getClassID(struct mCrossTransition *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCrossTransition__GetClassID();
    }
}
