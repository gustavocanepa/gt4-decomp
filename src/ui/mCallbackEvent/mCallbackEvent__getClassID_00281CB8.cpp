#include "gt4/mCallbackEvent.h"
typedef int s32;

extern "C" int mCallbackEvent__GetClassID(void) throw();

extern "C" void mCallbackEvent__getClassID(struct mCallbackEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCallbackEvent__GetClassID();
    }
}
