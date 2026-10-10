#include "gt4/mRaceRecordUnit.h"
typedef int s32;

extern "C" int func_001A49B0(void) throw();

extern "C" void mRaceRecordUnit__virtual_09(struct mRaceRecordUnit *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001A49B0();
    }
}
