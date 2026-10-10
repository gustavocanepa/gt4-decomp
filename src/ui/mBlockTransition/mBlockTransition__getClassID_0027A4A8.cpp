#include "gt4/mBlockTransition.h"
typedef int s32;

extern "C" int mBlockTransition__GetClassID(void) throw();

extern "C" void mBlockTransition__getClassID(struct mBlockTransition *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mBlockTransition__GetClassID();
    }
}
