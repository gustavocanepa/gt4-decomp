#include "gt4/mColorWindow.h"
typedef int s32;

extern "C" int mColorWindow__GetClassID(void) throw();

extern "C" void mColorWindow__getClassID(struct mColorWindow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mColorWindow__GetClassID();
    }
}
