#include "gt4/mMemoryCardFile.h"
typedef int s32;

extern "C" int mMemoryCardFile__GetClassID(void) throw();

extern "C" void mMemoryCardFile__getClassID(struct mMemoryCardFile *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mMemoryCardFile__GetClassID();
    }
}
