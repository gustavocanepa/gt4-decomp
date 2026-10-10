#include "gt4/mCancelEvent.h"
typedef int s32;

extern "C" int func_00282900(void) throw();

extern "C" void mCancelEvent__virtual_09(struct mCancelEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00282900();
    }
}
