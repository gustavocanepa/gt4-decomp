#include "gt4/mKeyReleaseEvent.h"
typedef int s32;

extern "C" int mKeyReleaseEvent__GetClassID(void) throw();

extern "C" void mKeyReleaseEvent__getClassID(struct mKeyReleaseEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mKeyReleaseEvent__GetClassID();
    }
}
