#include "gt4/mUpdateContext.h"
typedef int s32;

extern "C" int mUpdateContext__GetClassID(void) throw();

extern "C" void mUpdateContext__getClassID(struct mUpdateContext *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mUpdateContext__GetClassID();
    }
}
