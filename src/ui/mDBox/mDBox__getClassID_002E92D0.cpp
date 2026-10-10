#include "gt4/mDBox.h"
typedef int s32;

extern "C" int mDBox__GetClassID(void) throw();

extern "C" void mDBox__getClassID(struct mDBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mDBox__GetClassID();
    }
}
