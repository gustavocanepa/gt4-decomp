#include "gt4/mRaceRecord.h"
typedef int s32;

extern "C" int func_001A5E70(void) throw();

extern "C" void mRaceRecord__virtual_09(struct mRaceRecord *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001A5E70();
    }
}
