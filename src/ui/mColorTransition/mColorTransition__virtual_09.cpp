#include "gt4/mColorTransition.h"
typedef int s32;

extern "C" int func_00286E68(void) throw();

extern "C" void mColorTransition__virtual_09(struct mColorTransition *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00286E68();
    }
}
