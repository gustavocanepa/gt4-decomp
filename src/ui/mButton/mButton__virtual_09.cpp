#include "gt4/mButton.h"
typedef int s32;

extern "C" int func_0027CF40(void) throw();

extern "C" void mButton__virtual_09(struct mButton *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0027CF40();
    }
}
