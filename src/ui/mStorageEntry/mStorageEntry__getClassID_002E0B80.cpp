#include "gt4/mStorageEntry.h"
typedef int s32;

extern "C" int mStorageEntry__GetClassID(void) throw();

extern "C" void mStorageEntry__getClassID(struct mStorageEntry *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mStorageEntry__GetClassID();
    }
}
