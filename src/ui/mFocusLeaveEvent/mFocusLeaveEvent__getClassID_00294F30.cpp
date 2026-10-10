#include "gt4/mFocusLeaveEvent.h"
typedef int s32;

extern "C" int mFocusLeaveEvent__GetClassID(void) throw();

extern "C" void mFocusLeaveEvent__getClassID(struct mFocusLeaveEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mFocusLeaveEvent__GetClassID();
    }
}
