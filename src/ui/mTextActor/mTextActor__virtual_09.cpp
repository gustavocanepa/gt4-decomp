#include "gt4/mTextActor.h"
typedef int s32;

extern "C" int func_002E3D10(void) throw();

extern "C" void mTextActor__virtual_09(struct mTextActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002E3D10();
    }
}
