#include "gt4/mBlurFace.h"
typedef int s32;

extern "C" int mBlurFace__GetClassID(void) throw();

extern "C" void mBlurFace__getClassID(struct mBlurFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mBlurFace__GetClassID();
    }
}
