#include "gt4/mSound.h"
typedef int s32;

extern "C" int mSound__GetClassID(void) throw();

extern "C" void mSound__getClassID(struct mSound *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mSound__GetClassID();
    }
}
