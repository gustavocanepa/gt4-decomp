#include "gt4/mRenderContext.h"
typedef int s32;

extern "C" int mRenderContext__GetClassID(void) throw();

extern "C" void mRenderContext__getClassID(struct mRenderContext *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mRenderContext__GetClassID();
    }
}
