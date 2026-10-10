#include "gt4/mColorObject.h"
typedef int s32;

extern "C" int func_002037C8(void) throw();

extern "C" void mColorObject__virtual_09(struct mColorObject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002037C8();
    }
}
