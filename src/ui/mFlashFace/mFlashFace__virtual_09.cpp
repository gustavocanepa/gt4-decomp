#include "gt4/mFlashFace.h"
typedef int s32;

extern "C" int func_00291A28(void) throw();

extern "C" void mFlashFace__virtual_09(struct mFlashFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00291A28();
    }
}
