#include "gt4/mButtonEvent.h"
typedef int s32;

extern "C" int func_0027F2B8(void) throw();

extern "C" void mButtonEvent__getClassID(struct mButtonEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0027F2B8();
    }
}
