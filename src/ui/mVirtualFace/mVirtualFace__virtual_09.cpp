#include "gt4/mVirtualFace.h"
typedef int s32;

extern "C" int func_002E78E0(void) throw();

extern "C" void mVirtualFace__virtual_09(struct mVirtualFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002E78E0();
    }
}
