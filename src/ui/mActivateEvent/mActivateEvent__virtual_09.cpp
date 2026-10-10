#include "gt4/mActivateEvent.h"
typedef int s32;

extern "C" int func_002773D0(void) throw();

extern "C" void mActivateEvent__virtual_09(struct mActivateEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002773D0();
    }
}
