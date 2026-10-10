#include "gt4/mProgress.h"
typedef int s32;

extern "C" int mProgress__GetClassID(void) throw();

extern "C" void mProgress__getClassID(struct mProgress *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mProgress__GetClassID();
    }
}
