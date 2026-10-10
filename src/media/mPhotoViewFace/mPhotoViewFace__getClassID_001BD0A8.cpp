#include "gt4/mPhotoViewFace.h"
typedef int s32;

extern "C" int mPhotoViewFace__GetClassID(void) throw();

extern "C" void mPhotoViewFace__getClassID(struct mPhotoViewFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mPhotoViewFace__GetClassID();
    }
}
