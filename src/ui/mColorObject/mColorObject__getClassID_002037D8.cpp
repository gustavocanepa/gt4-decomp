#include "gt4/mColorObject.h"
typedef int s32;

extern "C" int mColorObject__GetClassID(void) throw();

extern "C" void mColorObject__getClassID(struct mColorObject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mColorObject__GetClassID();
    }
}
