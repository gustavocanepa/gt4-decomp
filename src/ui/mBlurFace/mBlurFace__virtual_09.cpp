#include "gt4/mBlurFace.h"
typedef int s32;

extern "C" int func_0027BD70(void) throw();

extern "C" void mBlurFace__virtual_09(struct mBlurFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0027BD70();
    }
}
