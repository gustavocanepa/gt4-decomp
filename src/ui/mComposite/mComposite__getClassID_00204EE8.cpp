#include "gt4/mComposite.h"
typedef int s32;

extern "C" int mComposite__GetClassID(void) throw();

extern "C" void mComposite__getClassID(struct mComposite *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mComposite__GetClassID();
    }
}
