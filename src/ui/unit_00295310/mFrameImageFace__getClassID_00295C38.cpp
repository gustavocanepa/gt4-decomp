#include "gt4/mFrameImageFace.h"
typedef int s32;

extern "C" int mFrameImageFace__GetClassID(void) throw();

extern "C" void mFrameImageFace__getClassID(struct mFrameImageFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mFrameImageFace__GetClassID();
    }
}
