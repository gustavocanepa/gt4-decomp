#include "gt4/mDemonstration.h"
typedef int s32;

extern "C" int mDemonstration__GetClassID(void) throw();

extern "C" void mDemonstration__getClassID(struct mDemonstration *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mDemonstration__GetClassID();
    }
}
