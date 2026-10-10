#include "gt4/mSliderBar.h"
typedef int s32;

extern "C" int func_002DD7E8(void) throw();

extern "C" void mSliderBar__virtual_09(struct mSliderBar *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002DD7E8();
    }
}
