#include "gt4/mScrollBox.h"
typedef int s32;

extern "C" int func_002CF598(void) throw();

extern "C" void mScrollBox__virtual_09(struct mScrollBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002CF598();
    }
}
