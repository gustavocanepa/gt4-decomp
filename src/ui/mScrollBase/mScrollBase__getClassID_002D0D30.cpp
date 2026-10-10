#include "gt4/mScrollBase.h"
typedef int s32;

extern "C" int mScrollBase__GetClassID(void) throw();

extern "C" void mScrollBase__getClassID(struct mScrollBase *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mScrollBase__GetClassID();
    }
}
