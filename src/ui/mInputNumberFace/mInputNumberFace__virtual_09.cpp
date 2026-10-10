#include "gt4/mInputNumberFace.h"
typedef int s32;

extern "C" int func_002A43B8(void) throw();

extern "C" void mInputNumberFace__virtual_09(struct mInputNumberFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002A43B8();
    }
}
