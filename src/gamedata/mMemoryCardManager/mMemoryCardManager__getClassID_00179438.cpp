#include "gt4/mMemoryCardManager.h"
typedef int s32;

extern "C" int mMemoryCardManager__GetClassID(void) throw();

extern "C" void mMemoryCardManager__getClassID(struct mMemoryCardManager *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mMemoryCardManager__GetClassID();
    }
}
