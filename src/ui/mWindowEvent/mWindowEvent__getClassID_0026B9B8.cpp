#include "gt4/mWindowEvent.h"
typedef int s32;

extern "C" int mWindowEvent__GetClassID(void) throw();

extern "C" void mWindowEvent__getClassID(struct mWindowEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mWindowEvent__GetClassID();
    }
}
