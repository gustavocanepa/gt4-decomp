#include "gt4/mMusic.h"
typedef int s32;

extern "C" int mMusic__GetClassID(void) throw();

extern "C" void mMusic__getClassID(struct mMusic *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mMusic__GetClassID();
    }
}
