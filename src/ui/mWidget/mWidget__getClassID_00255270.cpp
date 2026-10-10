#include "gt4/mWidget.h"
typedef int s32;

extern "C" int mWidget__GetClassID(void) throw();

extern "C" void mWidget__getClassID(struct mWidget *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mWidget__GetClassID();
    }
}
