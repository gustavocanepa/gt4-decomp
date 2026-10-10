#include "gt4/mCancelEvent.h"
typedef int s32;

extern "C" int mCancelEvent__GetClassID(void) throw();

extern "C" void mCancelEvent__getClassID(struct mCancelEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCancelEvent__GetClassID();
    }
}
