#include "gt4/mRaceRecordUnit.h"
typedef int s32;

extern "C" int mRaceRecordUnit__GetClassID(void) throw();

extern "C" void mRaceRecordUnit__getClassID(struct mRaceRecordUnit *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mRaceRecordUnit__GetClassID();
    }
}
