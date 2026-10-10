#include "gt4/mStorageHD.h"
typedef int s32;

extern "C" int mStorageHD__GetClassID(void) throw();

extern "C" void mStorageHD__getClassID(struct mStorageHD *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mStorageHD__GetClassID();
    }
}
