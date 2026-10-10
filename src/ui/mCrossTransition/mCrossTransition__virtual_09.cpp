#include "gt4/mCrossTransition.h"
typedef int s32;

extern "C" int func_00289850(void) throw();

extern "C" void mCrossTransition__virtual_09(struct mCrossTransition *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00289850();
    }
}
