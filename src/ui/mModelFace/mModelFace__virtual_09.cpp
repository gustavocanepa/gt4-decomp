#include "gt4/mModelFace.h"
typedef int s32;

extern "C" int func_002BAC88(void) throw();

extern "C" void mModelFace__virtual_09(struct mModelFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002BAC88();
    }
}
