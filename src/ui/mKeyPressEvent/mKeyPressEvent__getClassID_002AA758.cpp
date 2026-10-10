#include "gt4/mKeyPressEvent.h"
typedef int s32;

extern "C" int mKeyPressEvent__GetClassID(void) throw();

extern "C" void mKeyPressEvent__getClassID(struct mKeyPressEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mKeyPressEvent__GetClassID();
    }
}
