#include "gt4/mGameInputData.h"
typedef int s32;

extern "C" int mGameInputData__GetClassID(void) throw();

extern "C" void mGameInputData__getClassID(struct mGameInputData *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mGameInputData__GetClassID();
    }
}
