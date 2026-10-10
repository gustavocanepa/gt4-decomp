#include "gt4/mPhotoViewFace.h"
typedef int s32;

extern "C" int func_001BD098(void) throw();

extern "C" void mPhotoViewFace__virtual_09(struct mPhotoViewFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001BD098();
    }
}
