#include "gt4/mScrollWindow.h"
typedef int s32;

extern "C" int func_002D26E8(void) throw();

extern "C" void mScrollWindow__virtual_09(struct mScrollWindow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002D26E8();
    }
}
