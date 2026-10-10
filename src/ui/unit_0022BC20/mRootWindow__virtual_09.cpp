#include "gt4/mRootWindow.h"
typedef int s32;

extern "C" int func_00232DC8(void) throw();

extern "C" void mRootWindow__virtual_09(struct mRootWindow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00232DC8();
    }
}
