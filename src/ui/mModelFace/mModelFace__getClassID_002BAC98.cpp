#include "gt4/mModelFace.h"
typedef int s32;

extern "C" int mModelFace__GetClassID(void) throw();

extern "C" void mModelFace__getClassID(struct mModelFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mModelFace__GetClassID();
    }
}
