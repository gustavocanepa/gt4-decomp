#include "gt4/mPlayList.h"
typedef int s32;

extern "C" int mPlayList__GetClassID(void) throw();

extern "C" void mPlayList__getClassID(struct mPlayList *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mPlayList__GetClassID();
    }
}
