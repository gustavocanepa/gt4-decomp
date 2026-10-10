#include "gt4/mSelectBar.h"
typedef int s32;

extern "C" int mSelectBar__GetClassID(void) throw();

extern "C" void mSelectBar__getClassID(struct mSelectBar *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mSelectBar__GetClassID();
    }
}
