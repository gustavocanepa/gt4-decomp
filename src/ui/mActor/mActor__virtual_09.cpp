#include "gt4/mActor.h"
typedef int s32;

extern "C" int func_001FF0F8(void) throw();

extern "C" void mActor__virtual_09(struct mActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001FF0F8();
    }
}
