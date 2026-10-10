#include "gt4/mDnasInst.h"
typedef int s32;

extern "C" int func_001DB078(void) throw();

extern "C" void mDnasInst__virtual_09(struct mDnasInst *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001DB078();
    }
}
