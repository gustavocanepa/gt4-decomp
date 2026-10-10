#include "gt4/mManager.h"
typedef int s32;

extern "C" int mManager__GetClassID(void) throw();

extern "C" void mManager__getClassID(struct mManager *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mManager__GetClassID();
    }
}
