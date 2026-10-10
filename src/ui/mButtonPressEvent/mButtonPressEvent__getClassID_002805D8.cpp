#include "gt4/mButtonPressEvent.h"
typedef int s32;

extern "C" int mButtonPressEvent__GetClassID(void) throw();

extern "C" void mButtonPressEvent__getClassID(struct mButtonPressEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mButtonPressEvent__GetClassID();
    }
}
