#include "gt4/mActivateEvent.h"
typedef int s32;

extern "C" int mActivateEvent__GetClassID(void) throw();

extern "C" void mActivateEvent__getClassID(struct mActivateEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mActivateEvent__GetClassID();
    }
}
