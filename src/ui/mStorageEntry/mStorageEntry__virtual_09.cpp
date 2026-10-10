#include "gt4/mStorageEntry.h"
typedef int s32;

extern "C" int func_002E0B70(void) throw();

extern "C" void mStorageEntry__virtual_09(struct mStorageEntry *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002E0B70();
    }
}
