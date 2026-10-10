#include "gt4/mVirtualFace.h"
typedef int s32;

extern "C" int mVirtualFace__GetClassID(void) throw();

extern "C" void mVirtualFace__getClassID(struct mVirtualFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mVirtualFace__GetClassID();
    }
}
