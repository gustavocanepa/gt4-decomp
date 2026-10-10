#include "gt4/mMotionEvent.h"
typedef int s32;

extern "C" int func_002BF480(void) throw();

extern "C" void mMotionEvent__virtual_09(struct mMotionEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002BF480();
    }
}
