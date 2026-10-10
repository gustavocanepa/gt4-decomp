#include "gt4/mRootWindow.h"
typedef int s32;

extern "C" int mRootWindow__GetClassID(void) throw();

extern "C" void mRootWindow__getClassID(struct mRootWindow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mRootWindow__GetClassID();
    }
}
