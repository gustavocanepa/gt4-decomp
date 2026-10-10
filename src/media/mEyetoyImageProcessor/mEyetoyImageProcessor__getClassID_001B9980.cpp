#include "gt4/mEyetoyImageProcessor.h"
typedef int s32;

extern "C" int mEyetoyImageProcessor__GetClassID(void) throw();

extern "C" void mEyetoyImageProcessor__getClassID(struct mEyetoyImageProcessor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mEyetoyImageProcessor__GetClassID();
    }
}
