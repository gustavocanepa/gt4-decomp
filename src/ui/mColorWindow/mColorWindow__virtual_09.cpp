#include "gt4/mColorWindow.h"
typedef int s32;

extern "C" int func_00287E30(void) throw();

extern "C" void mColorWindow__virtual_09(struct mColorWindow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00287E30();
    }
}
