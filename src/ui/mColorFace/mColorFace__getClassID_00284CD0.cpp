#include "gt4/mColorFace.h"
typedef int s32;

extern "C" int mColorFace__GetClassID(void) throw();

extern "C" void mColorFace__getClassID(struct mColorFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mColorFace__GetClassID();
    }
}
