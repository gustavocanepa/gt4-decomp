#include "gt4/mMoveActor.h"
typedef int s32;

extern "C" int func_002C0530(void) throw();

extern "C" void mMoveActor__virtual_09(struct mMoveActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002C0530();
    }
}
