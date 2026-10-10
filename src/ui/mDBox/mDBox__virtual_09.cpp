#include "gt4/mDBox.h"
typedef int s32;

extern "C" int func_002E92C0(void) throw();

extern "C" void mDBox__virtual_09(struct mDBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002E92C0();
    }
}
