#include "gt4/mSession.h"
typedef int s32;

extern "C" int mSession__GetClassID(void) throw();

extern "C" void mSession__getClassID(struct mSession *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mSession__GetClassID();
    }
}
