#include "gt4/mScrollArrow.h"
typedef int s32;

extern "C" int mScrollArrow__GetClassID(void) throw();

extern "C" void mScrollArrow__getClassID(struct mScrollArrow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mScrollArrow__GetClassID();
    }
}
