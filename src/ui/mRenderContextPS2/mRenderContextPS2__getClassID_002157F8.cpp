#include "gt4/mRenderContextPS2.h"
typedef int s32;

extern "C" int mRenderContextPS2__GetClassID(void) throw();

extern "C" void mRenderContextPS2__getClassID(struct mRenderContextPS2 *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mRenderContextPS2__GetClassID();
    }
}
