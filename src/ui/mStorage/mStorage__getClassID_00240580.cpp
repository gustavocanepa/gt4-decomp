#include "gt4/mStorage.h"
typedef int s32;

extern "C" int mStorage__GetClassID(void) throw();

extern "C" void mStorage__getClassID(struct mStorage *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mStorage__GetClassID();
    }
}
