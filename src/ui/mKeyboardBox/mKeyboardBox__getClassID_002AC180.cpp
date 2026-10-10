#include "gt4/mKeyboardBox.h"
typedef int s32;

extern "C" int mKeyboardBox__GetClassID(void) throw();

extern "C" void mKeyboardBox__getClassID(struct mKeyboardBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mKeyboardBox__GetClassID();
    }
}
