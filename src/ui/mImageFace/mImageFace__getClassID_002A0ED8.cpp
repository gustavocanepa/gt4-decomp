#include "gt4/mImageFace.h"
typedef int s32;

extern "C" int mImageFace__GetClassID(void) throw();

extern "C" void mImageFace__getClassID(struct mImageFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mImageFace__GetClassID();
    }
}
