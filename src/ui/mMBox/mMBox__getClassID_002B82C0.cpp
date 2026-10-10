#include "gt4/mMBox.h"
typedef int s32;

extern "C" int mMBox__GetClassID(void) throw();

extern "C" void mMBox__getClassID(struct mMBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mMBox__GetClassID();
    }
}
