#include "gt4/mVBox.h"
typedef int s32;

extern "C" int mVBox__GetClassID(void) throw();

extern "C" void mVBox__getClassID(struct mVBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mVBox__GetClassID();
    }
}
