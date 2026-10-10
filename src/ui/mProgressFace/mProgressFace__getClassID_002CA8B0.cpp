#include "gt4/mProgressFace.h"
typedef int s32;

extern "C" int mProgressFace__GetClassID(void) throw();

extern "C" void mProgressFace__getClassID(struct mProgressFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mProgressFace__GetClassID();
    }
}
