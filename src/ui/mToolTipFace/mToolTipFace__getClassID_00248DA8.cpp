#include "gt4/mToolTipFace.h"
typedef int s32;

extern "C" int mToolTipFace__GetClassID(void) throw();

extern "C" void mToolTipFace__getClassID(struct mToolTipFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mToolTipFace__GetClassID();
    }
}
