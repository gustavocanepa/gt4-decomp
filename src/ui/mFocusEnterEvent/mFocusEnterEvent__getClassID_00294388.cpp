#include "gt4/mFocusEnterEvent.h"
typedef int s32;

extern "C" int mFocusEnterEvent__GetClassID(void) throw();

extern "C" void mFocusEnterEvent__getClassID(struct mFocusEnterEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mFocusEnterEvent__GetClassID();
    }
}
