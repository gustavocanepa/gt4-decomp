#include "gt4/mHBox.h"
typedef int s32;

extern "C" int mHBox__GetClassID(void) throw();

extern "C" void mHBox__getClassID(struct mHBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mHBox__GetClassID();
    }
}
