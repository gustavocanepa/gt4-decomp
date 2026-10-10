#include "gt4/mTransform.h"
typedef int s32;

extern "C" int mTransform__GetClassID(void) throw();

extern "C" void mTransform__getClassID(struct mTransform *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mTransform__GetClassID();
    }
}
