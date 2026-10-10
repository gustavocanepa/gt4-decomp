#include "gt4/mRotateActor.h"
typedef int s32;

extern "C" int func_002CCA70(void) throw();

extern "C" void mRotateActor__virtual_09(struct mRotateActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002CCA70();
    }
}
