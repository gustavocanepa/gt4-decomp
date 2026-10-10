#include "gt4/mMagnifyActor.h"
typedef int s32;

extern "C" int func_002B9980(void) throw();

extern "C" void mMagnifyActor__virtual_09(struct mMagnifyActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002B9980();
    }
}
