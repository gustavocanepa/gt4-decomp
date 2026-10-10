#include "gt4/mSlideShowFace.h"
typedef int s32;

extern "C" int mSlideShowFace__GetClassID(void) throw();

extern "C" void mSlideShowFace__getClassID(struct mSlideShowFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mSlideShowFace__GetClassID();
    }
}
