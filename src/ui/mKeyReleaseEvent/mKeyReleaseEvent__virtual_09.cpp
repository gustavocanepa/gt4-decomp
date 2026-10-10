#include "gt4/mKeyReleaseEvent.h"
typedef int s32;

extern "C" int func_002AB4A0(void) throw();

extern "C" void mKeyReleaseEvent__virtual_09(struct mKeyReleaseEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002AB4A0();
    }
}
