#include "gt4/mFlashFace.h"
typedef int s32;

extern "C" int mFlashFace__GetClassID(void) throw();

extern "C" void mFlashFace__getClassID(struct mFlashFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mFlashFace__GetClassID();
    }
}
