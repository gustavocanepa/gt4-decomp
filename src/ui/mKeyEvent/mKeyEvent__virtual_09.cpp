#include "gt4/mKeyEvent.h"
typedef int s32;

extern "C" int func_002A95A8(void) throw();

extern "C" void mKeyEvent__virtual_09(struct mKeyEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002A95A8();
    }
}
