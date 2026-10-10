#include "gt4/mFinalizeEvent.h"
typedef int s32;

extern "C" int func_00290418(void) throw();

extern "C" void mFinalizeEvent__virtual_09(struct mFinalizeEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00290418();
    }
}
