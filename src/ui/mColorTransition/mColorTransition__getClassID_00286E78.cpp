#include "gt4/mColorTransition.h"
typedef int s32;

extern "C" int mColorTransition__GetClassID(void) throw();

extern "C" void mColorTransition__getClassID(struct mColorTransition *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mColorTransition__GetClassID();
    }
}
