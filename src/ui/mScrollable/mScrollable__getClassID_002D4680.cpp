#include "gt4/mScrollable.h"
typedef int s32;

extern "C" int mScrollable__GetClassID(void) throw();

extern "C" void mScrollable__getClassID(struct mScrollable *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mScrollable__GetClassID();
    }
}
