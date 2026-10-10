#include "gt4/mEnterEvent.h"
typedef int s32;

extern "C" int mEnterEvent__GetClassID(void) throw();

extern "C" void mEnterEvent__getClassID(struct mEnterEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mEnterEvent__GetClassID();
    }
}
