#include "gt4/mWatcher.h"
typedef int s32;

extern "C" int mWatcher__GetClassID(void) throw();

extern "C" void mWatcher__getClassID(struct mWatcher *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mWatcher__GetClassID();
    }
}
