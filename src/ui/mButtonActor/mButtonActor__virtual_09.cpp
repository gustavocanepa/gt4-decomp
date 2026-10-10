#include "gt4/mButtonActor.h"
typedef int s32;

extern "C" int func_0027E2C8(void) throw();

extern "C" void mButtonActor__virtual_09(struct mButtonActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0027E2C8();
    }
}
