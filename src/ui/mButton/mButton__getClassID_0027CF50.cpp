#include "gt4/mButton.h"
typedef int s32;

extern "C" int mButton__GetClassID(void) throw();

extern "C" void mButton__getClassID(struct mButton *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mButton__GetClassID();
    }
}
