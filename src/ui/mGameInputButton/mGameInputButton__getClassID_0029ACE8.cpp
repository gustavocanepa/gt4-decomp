#include "gt4/mGameInputButton.h"
typedef int s32;

extern "C" int mGameInputButton__GetClassID(void) throw();

extern "C" void mGameInputButton__getClassID(struct mGameInputButton *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mGameInputButton__GetClassID();
    }
}
