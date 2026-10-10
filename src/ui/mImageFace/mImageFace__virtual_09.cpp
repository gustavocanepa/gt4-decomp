#include "gt4/mImageFace.h"
typedef int s32;

extern "C" int func_002A0EC8(void) throw();

extern "C" void mImageFace__virtual_09(struct mImageFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002A0EC8();
    }
}
