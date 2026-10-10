#include "gt4/mGameInputData.h"
typedef int s32;

extern "C" int func_0029B2E0(void) throw();

extern "C" void mGameInputData__virtual_09(struct mGameInputData *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0029B2E0();
    }
}
