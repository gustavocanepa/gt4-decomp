#include "gt4/mFBox.h"
typedef int s32;

extern "C" int mFBox__GetClassID(void) throw();

extern "C" void mFBox__getClassID(struct mFBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mFBox__GetClassID();
    }
}
