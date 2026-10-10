#include "gt4/mPipe.h"
typedef int s32;

extern "C" int mPipe__GetClassID(void) throw();

extern "C" void mPipe__getClassID(struct mPipe *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mPipe__GetClassID();
    }
}
