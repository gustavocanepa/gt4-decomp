#include "gt4/mToolTipFace.h"
typedef int s32;

extern "C" int func_00248D98(void) throw();

extern "C" void mToolTipFace__virtual_09(struct mToolTipFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00248D98();
    }
}
