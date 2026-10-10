#include "gt4/mPhotoRenderFace.h"
typedef int s32;

extern "C" int func_00197A20(void) throw();

extern "C" void mPhotoRenderFace__virtual_09(struct mPhotoRenderFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00197A20();
    }
}
