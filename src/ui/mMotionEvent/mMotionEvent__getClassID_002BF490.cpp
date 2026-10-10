#include "gt4/mMotionEvent.h"
typedef int s32;

extern "C" int mMotionEvent__GetClassID(void) throw();

extern "C" void mMotionEvent__getClassID(struct mMotionEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mMotionEvent__GetClassID();
    }
}
