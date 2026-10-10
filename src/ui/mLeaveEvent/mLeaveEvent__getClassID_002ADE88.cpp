#include "gt4/mLeaveEvent.h"
typedef int s32;

extern "C" int mLeaveEvent__GetClassID(void) throw();

extern "C" void mLeaveEvent__getClassID(struct mLeaveEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mLeaveEvent__GetClassID();
    }
}
