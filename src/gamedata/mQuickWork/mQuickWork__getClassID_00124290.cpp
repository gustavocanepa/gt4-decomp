#include "gt4/mQuickWork.h"
typedef int s32;

extern "C" int mQuickWork__GetClassID(void) throw();

extern "C" void mQuickWork__getClassID(struct mQuickWork *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mQuickWork__GetClassID();
    }
}
