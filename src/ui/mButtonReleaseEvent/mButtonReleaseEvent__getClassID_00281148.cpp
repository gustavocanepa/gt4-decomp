#include "gt4/mButtonReleaseEvent.h"
typedef int s32;

extern "C" int mButtonReleaseEvent__GetClassID(void) throw();

extern "C" void mButtonReleaseEvent__getClassID(struct mButtonReleaseEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mButtonReleaseEvent__GetClassID();
    }
}
