#include "gt4/mRaceData.h"
typedef int s32;

extern "C" int func_001A0CA0(void) throw();

extern "C" void mRaceData__virtual_09(struct mRaceData *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001A0CA0();
    }
}
