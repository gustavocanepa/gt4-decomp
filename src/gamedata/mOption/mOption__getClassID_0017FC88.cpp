#include "gt4/mOption.h"
typedef int s32;

extern "C" int mOption__GetClassID(void) throw();

extern "C" void mOption__getClassID(struct mOption *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mOption__GetClassID();
    }
}
