#include "gt4/mSlideShowFace.h"
typedef int s32;

extern "C" int func_001AA248(void) throw();

extern "C" void mSlideShowFace__virtual_09(struct mSlideShowFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001AA248();
    }
}
