#include "gt4/mEyetoyFace.h"
typedef int s32;

extern "C" int mEyetoyFace__GetClassID(void) throw();

extern "C" void mEyetoyFace__getClassID(struct mEyetoyFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mEyetoyFace__GetClassID();
    }
}
