#include "gt4/mSwitchActor.h"
typedef int s32;

extern "C" int func_002E2188(void) throw();

extern "C" void mSwitchActor__virtual_09(struct mSwitchActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002E2188();
    }
}
