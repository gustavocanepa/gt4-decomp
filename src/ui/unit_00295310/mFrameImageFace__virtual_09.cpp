#include "gt4/mFrameImageFace.h"
typedef int s32;

extern "C" int func_00295C28(void) throw();

extern "C" void mFrameImageFace__virtual_09(struct mFrameImageFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00295C28();
    }
}
