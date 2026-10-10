#include "gt4/mSystem.h"
typedef int s32;

extern "C" int mSystem__GetClassID(void) throw();

extern "C" void mSystem__getClassID(struct mSystem *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mSystem__GetClassID();
    }
}
