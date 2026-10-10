#include "gt4/mScrollBase.h"
typedef int s32;

extern "C" int func_002D0D20(void) throw();

extern "C" void mScrollBase__virtual_09(struct mScrollBase *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002D0D20();
    }
}
