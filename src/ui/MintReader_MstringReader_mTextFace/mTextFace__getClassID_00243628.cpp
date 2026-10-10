#include "gt4/mTextFace.h"
typedef int s32;

extern "C" int mTextFace__GetClassID(void) throw();

extern "C" void mTextFace__getClassID(struct mTextFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mTextFace__GetClassID();
    }
}
