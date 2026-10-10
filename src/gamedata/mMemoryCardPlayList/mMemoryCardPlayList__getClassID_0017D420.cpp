#include "gt4/mMemoryCardPlayList.h"
typedef int s32;

extern "C" int mMemoryCardPlayList__GetClassID(void) throw();

extern "C" void mMemoryCardPlayList__getClassID(struct mMemoryCardPlayList *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mMemoryCardPlayList__GetClassID();
    }
}
