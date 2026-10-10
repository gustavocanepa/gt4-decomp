#include "gt4/mFinalizeEvent.h"
typedef int s32;

extern "C" int mFinalizeEvent__GetClassID(void) throw();

extern "C" void mFinalizeEvent__getClassID(struct mFinalizeEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mFinalizeEvent__GetClassID();
    }
}
