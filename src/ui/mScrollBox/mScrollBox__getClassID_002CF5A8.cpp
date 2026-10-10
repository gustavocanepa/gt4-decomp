#include "gt4/mScrollBox.h"
typedef int s32;

extern "C" int mScrollBox__GetClassID(void) throw();

extern "C" void mScrollBox__getClassID(struct mScrollBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mScrollBox__GetClassID();
    }
}
