#include "gt4/mColorFace.h"
typedef int s32;

extern "C" int func_00284CC0(void) throw();

extern "C" void mColorFace__virtual_09(struct mColorFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00284CC0();
    }
}
