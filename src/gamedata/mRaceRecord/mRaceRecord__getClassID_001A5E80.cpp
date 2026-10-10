#include "gt4/mRaceRecord.h"
typedef int s32;

extern "C" int mRaceRecord__GetClassID(void) throw();

extern "C" void mRaceRecord__getClassID(struct mRaceRecord *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mRaceRecord__GetClassID();
    }
}
