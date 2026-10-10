#include "gt4/mButtonPressEvent.h"
typedef int s32;

extern "C" int func_002805C8(void) throw();

extern "C" void mButtonPressEvent__virtual_09(struct mButtonPressEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002805C8();
    }
}
