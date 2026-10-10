#include "gt4/mShell.h"
typedef int s32;

extern "C" int mShell__GetClassID(void) throw();

extern "C" void mShell__getClassID(struct mShell *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mShell__GetClassID();
    }
}
