#include "gt4/mScaleBar.h"
typedef int s32;

extern "C" int func_00236828(void) throw();

extern "C" void mScaleBar__virtual_09(struct mScaleBar *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00236828();
    }
}
