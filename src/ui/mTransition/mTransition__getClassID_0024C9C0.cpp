#include "gt4/mTransition.h"
typedef int s32;

extern "C" int mTransition__GetClassID(void) throw();

extern "C" void mTransition__getClassID(struct mTransition *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mTransition__GetClassID();
    }
}
