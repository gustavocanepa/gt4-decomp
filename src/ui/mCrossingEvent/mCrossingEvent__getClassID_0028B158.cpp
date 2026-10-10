#include "gt4/mCrossingEvent.h"
typedef int s32;

extern "C" int mCrossingEvent__GetClassID(void) throw();

extern "C" void mCrossingEvent__getClassID(struct mCrossingEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCrossingEvent__GetClassID();
    }
}
