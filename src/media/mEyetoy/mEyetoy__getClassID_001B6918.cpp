#include "gt4/mEyetoy.h"
typedef int s32;

extern "C" int mEyetoy__GetClassID(void) throw();

extern "C" void mEyetoy__getClassID(struct mEyetoy *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mEyetoy__GetClassID();
    }
}
