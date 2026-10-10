#include "gt4/mCarModel.h"
typedef int s32;

extern "C" int mCarModel__GetClassID(void) throw();

extern "C" void mCarModel__getClassID(struct mCarModel *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mCarModel__GetClassID();
    }
}
