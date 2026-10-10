#include "gt4/mPresent.h"
typedef int s32;

extern "C" int mPresent__GetClassID(void) throw();

extern "C" void mPresent__getClassID(struct mPresent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mPresent__GetClassID();
    }
}
