#include "gt4/mUpdateContext.h"
typedef int s32;

extern "C" int func_0024E310(void) throw();

extern "C" void mUpdateContext__virtual_09(struct mUpdateContext *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0024E310();
    }
}
