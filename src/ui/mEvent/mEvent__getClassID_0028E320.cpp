#include "gt4/mEvent.h"
typedef int s32;

extern "C" int mEvent__GetClassID(void) throw();

extern "C" void mEvent__getClassID(struct mEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mEvent__GetClassID();
    }
}
