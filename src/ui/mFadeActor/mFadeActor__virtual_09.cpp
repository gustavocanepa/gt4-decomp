#include "gt4/mFadeActor.h"
typedef int s32;

extern "C" int func_0020B4E8(void) throw();

extern "C" void mFadeActor__virtual_09(struct mFadeActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0020B4E8();
    }
}
