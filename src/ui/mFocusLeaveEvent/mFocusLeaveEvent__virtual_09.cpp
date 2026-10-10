#include "gt4/mFocusLeaveEvent.h"
typedef int s32;

extern "C" int func_00294F20(void) throw();

extern "C" void mFocusLeaveEvent__virtual_09(struct mFocusLeaveEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00294F20();
    }
}
