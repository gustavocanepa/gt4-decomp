#include "gt4/mFunctionEvent.h"
typedef int s32;

extern "C" int mFunctionEvent__GetClassID(void) throw();

extern "C" void mFunctionEvent__getClassID(struct mFunctionEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mFunctionEvent__GetClassID();
    }
}
