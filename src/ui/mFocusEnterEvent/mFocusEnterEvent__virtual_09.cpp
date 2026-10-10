#include "gt4/mFocusEnterEvent.h"
typedef int s32;

extern "C" int func_00294378(void) throw();

extern "C" void mFocusEnterEvent__virtual_09(struct mFocusEnterEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00294378();
    }
}
