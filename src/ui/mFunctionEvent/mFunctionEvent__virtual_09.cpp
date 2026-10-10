#include "gt4/mFunctionEvent.h"
typedef int s32;

extern "C" int func_0020D150(void) throw();

extern "C" void mFunctionEvent__virtual_09(struct mFunctionEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0020D150();
    }
}
