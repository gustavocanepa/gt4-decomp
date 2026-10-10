#include "gt4/mPhotoRenderFace.h"
typedef int s32;

extern "C" int mPhotoRenderFace__GetClassID(void) throw();

extern "C" void mPhotoRenderFace__getClassID(struct mPhotoRenderFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mPhotoRenderFace__GetClassID();
    }
}
